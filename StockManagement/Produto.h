#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Produto{
private:
    string nome;

    double tamanho;
    int prioridade;
    int quantidadeMinima;

public:
    double preco;
    int quantidade;
    Produto(string nome){
        this->nome = nome;
    }

    Produto(){
        this->preco = 0;
        this->quantidade = 0;
        this->tamanho = 0;
        this->prioridade = 0;
        this->quantidadeMinima = 0;
    }

    Produto(double preco, int quantidade, double tamanho, int prioridade, int quantidadeMinima, string nome){
        this->preco=preco;
        this->quantidade=quantidade;
        this->tamanho=tamanho;
        this->prioridade=prioridade;
        this->quantidadeMinima = quantidadeMinima;
        this->nome = nome;
    }

    friend ostream& operator<<(ostream&os, const Produto& print){
        os << print.prioridade << " " << print.nome << " " << print.preco << " " << print.tamanho << " " << print.quantidade << " " << print.quantidadeMinima;
        return os;
    }

    bool operator==(const Produto& comparison){
        if(this->nome.compare(comparison.nome) == 0){
            return true;
        }
        return false;
    }

    bool operator!=(const Produto& comparison){
        if(this->nome.compare(comparison.nome) != 0){
            return true;
        }
        return false;
    }

    bool operator>(const Produto& comparison){
        if(this->nome.compare(comparison.nome) > 0){
            return true;
        }
        return false;
    }

    bool operator<(const Produto& comparison){
        if(this->nome.compare(comparison.nome) < 0){
            return true;
        }
        return false;
    }

    void setPreco(double newPreco){
        this->preco = newPreco;
    }

    double getPreco(){
        return this->preco;
    }

    void setQuantidade(int quantidade){
        this->quantidade = quantidade;
    }

    int getQuantidade(){
        return this->quantidade;
    }

    void setQuantidadeMinima(int quantidadeMinima){
        this->quantidadeMinima = quantidadeMinima;
    }

    int getQuantidadeMinima(){
        return this->quantidadeMinima;
    }

    void setTamanho(double tamanho){
        this->tamanho = tamanho;
    }

    double getTamanho(){
        return this->tamanho;
    }

    void setPrioridade(int prioridade){
        this->prioridade=prioridade;
    }

    int getPrioridade(){
        return this->prioridade;
    }

    void setNome(string nome){
        this->nome = nome;
    }

    string getNome(){
        return this->nome;
    }
};

#endif // PRODUTO_H
