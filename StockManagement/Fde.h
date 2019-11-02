#ifndef FDE_H
#define FDE_H

template <typename T>
class FDE;

template <typename T>
class No{
private:
    T valor;
    No<T>* proximo;

public:
    No(T valor){
        this->valor = valor;
        proximo = nullptr;
    }
};

template <typename T> class FDE {
private:
  No<T> *primeiro;
  No<T> *ultimo;
  int tam;

public:
  FDE(){
      this->primeiro = nullptr;
      this->ultimo = nullptr;
      this->tam = 0;
  }

  bool push(T valor) {
      No<T>* novo = new No<T>(valor);
      if(!novo)
          return false;

      if(ultimo)
          ultimo->proximo = novo;
      ultimo=novo;
      if(!primeiro)
          primeiro=novo;

      return true;
  }

  T pop() {
        if(!primeiro)
            return nullptr;

        T toReturn = primeiro;
        toReturn = primeiro->valor;

        primeiro = primeiro->proximo;
        return toReturn;
  }

  bool vazia() {
    return primeiro == nullptr;
  }
};

#endif /* FDE_H */
