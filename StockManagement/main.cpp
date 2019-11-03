#include "mainwindow.h"

#include <QApplication>
#include "Produto.h"
#include "LinkedList.h"
#include <stdio.h>
#include <iostream>
#include "ListaDeCompras.h"
#include "Fde.h"

using namespace std;

int main(int argc, char *argv[])
{

/*
    LinkedList<Produto> lista;

    Produto *produto1 = new Produto(1.1, 1, 30, 2, 10, "produto1");
    Produto *produto2 = new Produto(1.1, 1, 30, 2, 1, "produto2");
    Produto *produto3 = new Produto(1.1, 1, 30, 2, 10, "produto3");
    Produto *produto4 = new Produto(1.1, 1, 30, 2, 200, "produto4");

    ListaDeCompra fde;


    fde.add(*produto1);
    fde.add(*produto2);
    fde.add(*produto3);
    fde.add(*produto4);

    fde.gerarFila();

    FDE<Produto> novafde = fde.getFila();

    cout<<novafde.size()<<endl;

    for(int i = 0; i < novafde.size(); i ++){
        cout<<novafde.get(i)->valor.getNome()<<endl;
    }

    fde.gerarFila();
*/



    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


}
