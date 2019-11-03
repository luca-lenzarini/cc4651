#ifndef FDE_H
#define FDE_H

template <typename T>
class FDE;

template <typename T>
class No{
public:
    T valor;
    No<T>* proximo;

    No(T valor){
        this->valor = valor;
        proximo = nullptr;
    }

    ~No(){
        delete this;
    }
};

template <typename T> class FDE {
public:
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

      if(ultimo)
          ultimo->proximo = novo;
      ultimo=novo;
      if(!primeiro)
          primeiro=novo;
      tam++;
      return true;
  }

  T pop() {
        if(!primeiro)
            return nullptr;

        T toReturn = primeiro->valor;

        primeiro = primeiro->proximo;
        return toReturn;
  }

  No<T>* get(int index){
      No<T>* atual = primeiro;

      for(int i = 0; i <= index; i++){
          if(i == index){
              return atual;
          }
          atual = atual->proximo;
      }
      return nullptr;

  }

  bool vazia() {
    return primeiro == nullptr;
  }

  void clear(){
      this->primeiro = nullptr;
      this->ultimo = nullptr;
      this->tam = 0;
  }

  int size(){
      return this->tam;
  }
};

#endif /* FDE_H */
