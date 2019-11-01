#include "mainwindow.h"

#include <QApplication>
#include "Produto.h"
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

    Produto *produto2 = new Produto(1.1, 1, 2.2, 2);
    Produto *produto = new Produto(1.1, 1, 2.2, 1);

    cout << *produto;

}
