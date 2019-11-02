#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "LinkedList.h"
#include "Produto.h"
#include <QMainWindow>

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

private slots:
    void on_listaProdutosButton_clicked();

    void on_addButton_clicked();

    void on_nomeAddText_objectNameChanged(const QString &objectName);

    void on_nomeAddText_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
