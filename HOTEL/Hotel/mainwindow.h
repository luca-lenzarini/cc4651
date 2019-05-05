#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "cadastrohospede.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_cadastrasHospedeButton_clicked();

private:
    Ui::MainWindow *ui;
    CadastroHospede *cadastro;
};

#endif // MAINWINDOW_H
