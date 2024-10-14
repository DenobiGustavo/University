import pandas as pd
import numpy as np
import streamlit as st
import sqlite3
from sqlite3 import Error

# Função para calcular a similaridade usando distância euclidiana ponderada
def calcular_similaridade(novo_caso, df_casos, df_pesos):
    similaridades = []
    for index, row in df_casos.iterrows():
        # Calcular a distância ponderada
        distancia = np.sqrt(np.sum([
            ((novo_caso[attr] == row[attr]) * df_pesos.loc[df_pesos['Atributo'] == attr, 'Peso'].values[0]) ** 2
            for attr in df_pesos['Atributo'] if attr in novo_caso and pd.notna(row[attr])
        ]))
        similaridades.append((row['DescDoenca'], distancia))  # Usar o nome da doença
    
    # Ordenar os casos em ordem crescente de similaridade
    similaridades.sort(key=lambda x: x[1])
    return similaridades[:3]  # Retornar os 3 casos mais semelhantes

# Função para criar a conexão com SQLite
def create_connection():
    try:
        conn = sqlite3.connect('soja_doencas.db')
        return conn
    except Error as e:
        st.write(f"Erro ao conectar ao banco de dados: {e}")
        return None

# Função para criar a tabela no banco de dados SQLite
def create_table(conn):
    try:
        cursor = conn.cursor()
        sql_create_table = '''CREATE TABLE IF NOT EXISTS registros (
                                id INTEGER PRIMARY KEY AUTOINCREMENT,
                                nome_doenca TEXT NOT NULL,
                                similaridade REAL NOT NULL,
                                atributos TEXT NOT NULL
                            );'''
        cursor.execute(sql_create_table)
        conn.commit()
    except Error as e:
        st.write(f"Erro ao criar a tabela: {e}")

# Função para inserir um registro no banco de dados SQLite
def insert_registro(conn, doenca, similaridade, atributos):
    try:
        cursor = conn.cursor()
        sql_insert = '''INSERT INTO registros(nome_doenca, similaridade, atributos) VALUES(?, ?, ?)'''
        cursor.execute(sql_insert, (doenca, similaridade, atributos))
        conn.commit()
        st.write(f'Registro inserido: {doenca}, {similaridade}, {atributos}')
    except Error as e:
        st.write(f"Erro ao inserir o registro: {e}")

# Carregar os dados das planilhas
df_casos = pd.read_excel('base.xlsx', sheet_name='Casos')
df_pesos = pd.read_excel('base.xlsx', sheet_name='Pesos')

# Interface com Streamlit
st.title('Sistema RBC de Doenças da Soja')

# Lista de atributos relevantes
atributos_relevantes = df_pesos['Atributo'].dropna().tolist()

# Input dos dados do novo caso, dinamicamente baseado nos atributos relevantes
novo_caso = {}

# Criar caixas de seleção para todos os atributos
for atributo in atributos_relevantes:
    opcoes = df_casos[atributo].dropna().unique().tolist()  # Extrair as opções disponíveis
    if len(opcoes) > 0:
        novo_caso[atributo] = st.selectbox(atributo, opcoes)

# Conectar ao banco de dados SQLite
conn = create_connection()
create_table(conn)

# Armazenar a seleção do usuário em session_state
if 'casos_semelhantes' not in st.session_state:
    st.session_state.casos_semelhantes = []
if 'doenca_selecionada' not in st.session_state:
    st.session_state.doenca_selecionada = None

# Quando o usuário clicar no botão
if st.button('Buscar Casos Semelhantes'):
    st.session_state.casos_semelhantes = calcular_similaridade(novo_caso, df_casos, df_pesos)

# Exibir os resultados em ordem crescente de similaridade
if st.session_state.casos_semelhantes:
    st.write('Casos mais semelhantes encontrados:')
    
    # Criar um selectbox para as doenças semelhantes
    opcoes_doencas = [f'{caso[0]} (Similaridade: {caso[1]})' for caso in st.session_state.casos_semelhantes]
    st.session_state.doenca_selecionada = st.selectbox('Selecione uma doença para cadastrar:', opcoes_doencas)

    # Mostrar detalhes da doença selecionada
    if st.session_state.doenca_selecionada:
        st.write(f'Doença selecionada: {st.session_state.doenca_selecionada}')

# Quando o usuário confirmar a seleção
if st.session_state.doenca_selecionada and st.button('Cadastrar Seleção'):
    nome_doenca = st.session_state.doenca_selecionada.split(' (')[0]
    similaridade = float(st.session_state.doenca_selecionada.split(': ')[1].replace(')', ''))
    
    # Serializar os atributos selecionados
    atributos_selecionados = ', '.join([f'{key}: {value}' for key, value in novo_caso.items()])
    
    # Inserir a doença, similaridade e os atributos no banco de dados SQLite
    insert_registro(conn, nome_doenca, similaridade, atributos_selecionados)

    # Limpar a seleção após o cadastro
    st.session_state.casos_semelhantes = []
    st.session_state.doenca_selecionada = None

# Fechar a conexão com o banco de dados
if conn:
    conn.close()
