#ifndef PRODUTO_H
#define PRODUTO_H

#endif // PRODUTO_H

#include <iostream>
#include <stdio.h>

using namespace std;

class Produto{
private:
    double preco;
    int quantidade;
    double tamanho;
    int prioridade;

public:
    friend ostream& operator<<(ostream&os, const Produto& print){
        os << print.preco << '/' << print.tamanho << '/' << print.prioridade;
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

    Produto(double preco, int quantidade, double tamanho, int prioridade){
        this->preco=preco;
        this->quantidade=quantidade;
        this->tamanho=tamanho;
        this->prioridade=prioridade;
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
