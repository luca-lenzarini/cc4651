#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <stdio.h>

using namespace std;

class Produto{
private:
    double preco;
    int quantidade;
    double tamanho;
    int prioridade;
    int quantidadeMinima;

public:
    Produto(){
        this->preco = 0;
        this->quantidade = 0;
        this->tamanho = 0;
        this->prioridade = 0;
        this->quantidadeMinima = 0;
    }

    Produto(double preco, int quantidade, double tamanho, int prioridade, int quantidadeMinima){
        this->preco=preco;
        this->quantidade=quantidade;
        this->tamanho=tamanho;
        this->prioridade=prioridade;
        this->quantidadeMinima = quantidadeMinima;
    }

    friend ostream& operator<<(ostream&os, const Produto& print){
        os << print.prioridade;
        return os;
    }

    bool operator==(const Produto& comparison){
        if(this->prioridade == comparison.prioridade){
            return true;
        }
        return false;
    }

    bool operator>(const Produto& comparison){
        if(this->prioridade > comparison.prioridade){
            cout<<"é true"<<endl;
            return true;
        }
        return false;
    }

    bool operator<(const Produto& comparison){
        if(this->prioridade < comparison.prioridade){
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
};

#endif // PRODUTO_H
