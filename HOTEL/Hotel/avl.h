#ifndef AVL_H
#define AVL_H

#include <queue>
#include "pessoa.h"

#include <iostream>
using namespace std;

template <typename T> class No {
public:
  No<T> *esq;
  No<T> *dir;
  No<T> *pai;
  int altura;
  T valor;
  int fatorBalanc(){
    int e = esq ? (esq->altura) : -1;
    int d = dir ? (dir->altura) : -1;
    return d - e;
  }

  No(T valor) : esq(nullptr), dir(nullptr),pai(nullptr), altura(0), valor(valor){}
  virtual ~No(){}
  T getValor(){
    return valor;
  }
};

template <typename T> class Avl {
private:
  No<T> *raiz;
  int quantidade;

  void setAltura(No<T>* n){
    if(!n)
      return;
    int m=-1;
    if(n && n->esq){
      m = n->esq->altura;
    }
    if(n && n->dir && n->dir->altura > m){
      m = n->dir->altura;
    }
    n->altura = m+1;
  }

  void setPai(No<Pessoa>* n, No<Pessoa>* pai){
      if(n){
        n->pai = pai;
        if(pai){
            if(n->valor.getId() < pai->valor.getId() )
                pai->esq = n;
            else
                pai->dir = n;
        }else{
          raiz = n;
        }
      }
  }

  void leftRotate(No<T>* n){
        No<T>* x = n;
        No<T>* y = n->dir;
        No<T>* b = y->esq;

        y->pai = x;
        setPai(y, x->pai);
        x->dir = b;
        if(b)
            b->pai = x;

        setPai(x, y);
        setAltura(x);
        setAltura(y);
        setAltura(y->pai);
  }


  void rightRotate(No<T>* n){
    No<T>* x = n;
    No<T>* y = n->esq;
    No<T>* b = y->dir;

    y->pai = x;
    setPai(y, x->pai);
    x->esq = b;
    if(b)
      b->pai = x;


    setPai(x, y);
    setAltura(x);
    setAltura(y);
    setAltura(y->pai);
  }


  void balanceie(No<T>* n){
    if( n->fatorBalanc() >= 2 ){
      if(n->dir && n->dir->fatorBalanc() < 0){
        rightRotate(n->dir);
      }
      leftRotate(n);
    }else if(n->fatorBalanc() <= -2){
      if(n->esq && n->esq->fatorBalanc() > 0){
        leftRotate(n->esq);
      }
      rightRotate(n);
    }
  }

  int coluna(No<T>* n){
    int contaPaisEsquerdos=fe(raiz);
    No<T> * at = n->pai;
    No<T> * ant = n;
    while(at){
      if(at->dir == ant)
        contaPaisEsquerdos++;
      else
        contaPaisEsquerdos--;
      ant=at;
      at=at->pai;
    }
    return max(fe(n), contaPaisEsquerdos);
  }

  int nivel(No<T>* n){
    int k=0;
    No<T>* at = n;
    while(at){
      k++;
      at = at->pai;
    }
    return k;
  }


public:

  Avl() : raiz(nullptr), quantidade(0){

  }

  No<T>* getRaiz(){
    return raiz;
  }
  bool insere(Pessoa valor) {
    No<Pessoa> *novo = new No<Pessoa>(valor);
    if (!novo)
      return false;

    No<Pessoa> *ptrAnterior = nullptr;
    No<Pessoa> *ptrAtual = raiz;
    while (ptrAtual) {
      ptrAnterior = ptrAtual;
      if (valor.getId() < ptrAtual->valor.getId())
        ptrAtual = ptrAtual->esq;
      else
        ptrAtual = ptrAtual->dir;
    }

    if (ptrAnterior) {
      novo->pai = ptrAnterior;
      if (valor.getId() < ptrAnterior->valor.getId())
        ptrAnterior->esq = novo;
      else
        ptrAnterior->dir = novo;
    } else
      raiz = novo;

    quantidade++;
    No<T>* a = novo->pai;
    while(a){
      setAltura(a);
      balanceie(a);
      //cout << a->valor << endl;
      a = a->pai;
    }
    return true;
  }

  No<Pessoa>* busca(Pessoa v){
    No<Pessoa>* atual = raiz;
    while(atual){
      if(v.getId() < atual->valor.getId()){
        atual = atual->esq;
      }else if(v.getId() > atual->valor.getId()){
        atual = atual->dir;
      }else{
        return atual;
      }
    }
    return nullptr;
  }


  bool remove(No<T>* n){
    if(!n)
      return false;

    int filhos = (n->esq!= nullptr) + (n->dir!=nullptr);
    if(filhos==0){
      if(n->pai){
        if(n == n->pai->esq)
          n->pai->esq = nullptr;
        else
          n->pai->dir = nullptr;
      }else{
        raiz = NULL;
      }

      delete n;
    }else if(filhos == 1){
      No<T> *filho = n->esq;
      if(!filho)
        filho = n->dir;
      setPai(filho, n->pai);
      delete n;
    }else{
      No<T>* suc = sucessor(n);
      T valor = suc->valor;
      remove(suc);
      n->valor = valor;
    }

    return true;
  }

  void erd(){
      erd(raiz);
  }
  void erd(No<T>* n){
     if(n){
         erd(n->esq);
         cout << n->valor << "(" << n->altura << ")" << endl;
         erd(n->dir);
     }
  }


  void red(){
      red(raiz);
  }
  void red(No<T>* n){
     if(n){
         cout << n->valor << endl;
         red(n->esq);
         red(n->dir);
     }
  }

  int fe(No<T>* n){
      if(!n){
          return -1;
      }
      return max(fe(n->esq)+1, fe(n->dir)-1);
  }


  No<T>* sucessor(No<T> *n){
      n=n->dir;
      while(n && n->esq){
          n=n->esq;
      }
      return n;
  }

  int getLastId(){
      return this->quantidade;
  }


  virtual ~Avl(){
    while(raiz){
      remove(raiz);
    }
  }
};

#endif /* AVL_H */
