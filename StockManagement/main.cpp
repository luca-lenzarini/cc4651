#include "mainwindow.h"

#include <QApplication>
#include "Produto.h"
#include "LinkedList.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    */

    Produto *produto1 = new Produto(1, 1, 2, 4);
    Produto *produto2 = new Produto(1, 1, 2, 5);
    Produto *produto3 = new Produto(1, 1, 2, 1);

    LinkedList<Produto> lista;

    lista.insere(*produto1);
    lista.insere(*produto2);
    lista.insere(*produto3);
}
