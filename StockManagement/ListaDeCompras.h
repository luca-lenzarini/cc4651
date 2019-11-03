#ifndef LISTADECOMPRAS_H
#define LISTADECOMPRAS_H

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <Produto.h>
#include "Fde.h"

#define MAX 10
using namespace std;

class ListaDeCompra {
private:
  Produto vetor[MAX];
  int tamanho;
  FDE<Produto> filaDeCompras;

public:
  ListaDeCompra(){
      this->tamanho = 0;
  }

  bool add(Produto novo) {

    if (this->tamanho >= MAX)
      return false;

    int i = 0;
    while (i < tamanho && vetor[i].getPrioridade() < novo.getPrioridade()) {
      i++;
    }

    for (int j = tamanho; j > i; j--) {
      vetor[j] = vetor[j - 1];
    }

    vetor[i] = novo;
    tamanho++;
    return true;
  }

  int busca(Produto elemento) {
    for (int i = 0; i < tamanho; i++) {
      if (vetor[i] == elemento)
        return i;
    }
    return -1;
  }

  int buscaBinaria(Produto elemento) {
    int i = 0;
    int f = tamanho - 1;
    while (i <= f) {
      int p = (i + f) / 2;
      if (elemento.getPrioridade() < vetor[p].getPrioridade())
        f = p - 1;
      else if (elemento > vetor[p])
        i = p + 1;
      else
        return p;
    }

    return -1;
  }

  bool remove(Produto elemento) {
    int pos = busca(elemento);
    if (pos == -1)
      return false;

    for (int i = pos; i < tamanho - 1; i++)
      vetor[i] = vetor[i + 1];

    tamanho--;
    return true;
  }

  int size(){
    return tamanho;
  }

  void gerarFila(){
      filaDeCompras.clear();

      for(int i = 0; i < tamanho; i++){
        filaDeCompras.push(vetor[i]);
      }
  }

  FDE<Produto> getFila(){
      return this->filaDeCompras;
  }
};


#endif // LISTADECOMPRAS_H
