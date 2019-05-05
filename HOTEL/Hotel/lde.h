#ifndef LDE_H
#define LDE_H

#include <cstdlib>
#include <iostream>
#include "room.h"

using namespace std;

template <typename T> class No {
public:
  Room quarto;
  No<Room> *prox;

  No(Room quarto) {
    this->quarto = quarto;
    this->prox = NULL;
  }
};

template <typename T> class Lde {
private:
  No<Room> *primeiro;
  unsigned int total;

public:
  Lde() : primeiro(nullptr), total(0) {
  }

  bool add(Room quarto) {
    No<Room> *atual = primeiro;
    No<Room> *anterior = nullptr;

    No<Room> *novo = new No<Room>(quarto);

    if (!novo)
      return false;

    while (atual && !atual->quarto.isGreaterThan(quarto)) {
      anterior = atual;
      atual = atual->prox;
    }

    if (anterior){
      anterior->prox = novo;
  }
    else
      primeiro = novo;

    novo->prox = atual;
    return true;
  }

  ~Lde() {
    No<Room> *prox = nullptr;
    No<Room> *atual = primeiro;
    while (atual) {
      prox = atual->prox;
      delete atual;
      atual = prox;
    }
  }

  No<Room> *busca(int numeroQuarto) {
    No<Room> *atual = primeiro;
    while (atual && atual->quarto.getNumber() < numeroQuarto) {
      atual = atual->prox;
    }

    if (atual && atual->quarto.getNumber() == numeroQuarto)
      return atual;
    else
      return nullptr;
  }

  bool remove(int valor) {
    No<Room> *anterior = nullptr;
    No<Room> *atual = primeiro;
    while (atual && atual->quarto.getNumber() < valor) {
      anterior = atual;
      atual = atual->prox;
    }

    if (atual == nullptr || atual->quarto.getNumber() != valor)
      return false;

    if (anterior)
      anterior->prox = atual->prox;
    else
      primeiro = atual->prox;

    delete atual;

    return true;
  }

};


#endif // LDE_H
