import pandas as pd
import numpy as np
import streamlit as st

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
    
    similaridades.sort(key=lambda x: x[1])
    return similaridades[:3]  # Retornar os 3 casos mais semelhantes

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

# Quando o usuário clicar no botão
if st.button('Buscar Casos Semelhantes'):
    casos_semelhantes = calcular_similaridade(novo_caso, df_casos, df_pesos)
    
    # Exibir os resultados
    st.write('Casos mais semelhantes encontrados:')
    for caso in casos_semelhantes:
        st.write(f'Doença: {caso[0]}, Similaridade: {caso[1]}')
