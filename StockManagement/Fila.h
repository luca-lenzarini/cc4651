#ifndef FILA_H
#define FILA_H

template <typename T> class FDS {
private:
  int sz;
  T *buff;
  int i;
  int f;

public:
  FDS(int sz) : sz(sz), buff(new T[sz]), i(0), f(0){};

  bool enfileira(T novo) {
    if (cheia())
      return false;

    buff[f] = novo;
    f = (f + 1) % sz;
    return true;
  }

  bool desenfileira(T &saida) {
    if (vazia())
      return false;
    saida = buff[i];
    i = (i + 1) % sz;

    return true;
  }

  bool vazia() {
    return i == f;
  }

  bool cheia() {
    return ((f + 1) % sz) == i;
  }

  virtual ~FDS() {
      delete[] buff;
  }
};

#endif // FILA_H
