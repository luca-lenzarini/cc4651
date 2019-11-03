#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "LinkedList.h"
#include "Produto.h"
#include <QMainWindow>
#include <QTableWidgetItem>
#include "ListaDeCompras.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    LinkedList<Produto> produtosLista;
    ListaDeCompra listaDeCompra;

private slots:
    void on_addButton_clicked();
    void on_nomeAddText_editingFinished();

    void on_searchButton_clicked();

    void on_listaProdutosTable_cellEntered(int row, int column);

    void on_listaProdutosTable_cellDoubleClicked(int row, int column);

    void on_listaProdutosTable_itemDoubleClicked(QTableWidgetItem *item);

    void on_searchButton_2_clicked();

    void on_removeButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
