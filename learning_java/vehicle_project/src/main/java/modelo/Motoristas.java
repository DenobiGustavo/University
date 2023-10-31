/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

/**
 *
 * @author temporario
 */
public class Motoristas extends Usuarios {
    private int cnh;
    private String secao;

    public int getCnh() {
        return cnh;
    }

    public void setCnh(int cnh) {
        this.cnh = cnh;
    }

    public String getSecao() {
        return secao;
    }

    public void setSecao(String secao) {
        this.secao = secao;
    }
    
    public Motoristas(String nome, String endereco, int cnh, String secao){
        super(nome, endereco);
        this.cnh = cnh;
        this.secao = secao;
    }
}
