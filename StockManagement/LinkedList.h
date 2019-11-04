#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include "Produto.h"

using namespace std;

template <typename T> class Node {
public:
  T valor;
  Node<T> *next;

  Node(T valor) {
    this->valor = valor;
    this->next = nullptr;
  }
};

template <typename T> class LinkedList {
private:
  Node<T> *primeiro;
  unsigned int total;

public:
  LinkedList(){
      primeiro = nullptr;
      total = 0;
  }


  bool add(T valor) {
    Node<T> *atual = primeiro;
    Node<T> *anterior = nullptr;

    Node<T> *newNode = new Node<T>(valor);

    if (!newNode)
      return false;

    while (atual && atual->valor < valor) {
      anterior = atual;
      atual = atual->next;
    }

    if (anterior)
      anterior->next = newNode;
    else
      primeiro = newNode;

    newNode->next = atual;
    this->total++;
    return true;
  }

  Node<T> *get(T valor) {
    Node<T> *atual = primeiro;
    while (atual && atual->valor < valor) {
        atual = atual->next;
    }

    if (atual && atual->valor == valor){
        return atual;
    }else{
        return NULL;
    }

  }

  Node<T>* get(int index){
      Node<T> *atual = primeiro;

      int i = 0;

      while (atual && i < index) {
          atual = atual->next;
          i++;
      }

      if (atual){
          return atual;
      }else{
          return NULL;
      }
  }

  bool remove(T valor) {
    Node<T> *anterior = nullptr;
    Node<T> *atual = primeiro;
    while (atual && atual->valor < valor) {
      anterior = atual;
      atual = atual->next;
    }

    if (atual == nullptr || atual->valor != valor)
      return false;

    if (anterior)
      anterior->next = atual->next;
    else
      primeiro = atual->next;

    delete atual;

    this->total--;
    return true;
  }

  void print(){
      Node<T> *atual = primeiro;

      while(atual != nullptr){
          cout<<atual->valor;
          atual = atual->next;
      }
  }

  int size(){
      return this->total;
  }

  void clear(){
      primeiro = 0;
      total = 0;
  }
};


#endif // LINKEDLIST_H
