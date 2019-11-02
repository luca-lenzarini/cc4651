#include "mainwindow.h"

#include <QApplication>
#include "Produto.h"
#include "LinkedList.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
