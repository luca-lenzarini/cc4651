#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Produto.h"
#include "LinkedList.h"
#include <QLineEdit>
#include <string>
#include <QMessageBox>
#include <iostream>
#include <stdio.h>
#include <ListaDeCompras.h>
#include "Fde.h"

using namespace std;

//init
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listaProdutosTable->setColumnCount(5);

    QStringList headerLabels;
    headerLabels.append("Nome");
    headerLabels.append("Preço");
    headerLabels.append("Qtd");
    headerLabels.append("Tamanho");
    headerLabels.append("Prioridade");
    ui->listaProdutosTable->setHorizontalHeaderLabels(headerLabels);
    ui->listaProdutosTable->verticalHeader()->setVisible(false);

    ui->filaDeCompas->setColumnCount(3);
    ui->filaDeCompas->setHorizontalHeaderLabels(headerLabels);
    ui->filaDeCompas->verticalHeader()->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked(){
    QString nome = ui->nomeAddText->text();
    QString preco = ui->precoAddText->text();
    QString qtd = ui->qtdAddText->text();
    QString qtdMinima = ui->qtdMinimaAddText->text();
    QString tamanho = ui->tamanhoAddText->text();
    QString prioridade = ui->prioridadeAddText->text();

    QString errors;
    bool precoNoError = true;
    bool qtdNoError = true;
    bool qtdMinimaNoError = true;
    bool tamanhoNoError = true;
    bool prioridadeNoError = true;

    if(nome.isEmpty() || preco.isEmpty() || qtd.isEmpty() || qtdMinima.isEmpty() || tamanho.isEmpty() || prioridade.isEmpty()){
        errors = "Todos os campos devem ser preenchidos.\n";
    }

    Produto *novoProduto = new Produto(
        preco.toDouble(&tamanhoNoError),
        qtd.toInt(&qtdNoError, 10),
        tamanho.toDouble(&tamanhoNoError),
        prioridade.toInt(&prioridadeNoError, 10),
        qtdMinima.toInt(&qtdMinimaNoError, 10),
        nome.toStdString()
    );

    if(errors.isEmpty()){
        if(not(precoNoError))
            errors += "-O campo preço deve ser um numero.\n";
        if(not(qtdNoError))
            errors += "-O campo quantidade deve ser um numero.\n";
        if(not(qtdMinimaNoError))
            errors += "-O campo Qtd Minima deve ser um numero.\n";
        if(not(tamanhoNoError))
            errors += "-O campo Tamanho deve ser um numero.\n";
        if(not(prioridadeNoError))
            errors += "-O campo Prioridade deve ser um numero.\n";
        if(prioridade.toInt() < 0 || prioridade.toInt() > 10)
            errors += "-O campo Prioridade deve estar entre 0 e 10";
    }
    if(errors.isEmpty()){
        if(produtosLista.add(*novoProduto)){


            if(novoProduto->getQuantidade() < novoProduto->getQuantidadeMinima()){

                listaDeCompra.add(*novoProduto);

                listaDeCompra.gerarFila();

                FDE<Produto> fdeCompras = listaDeCompra.getFila();

                ui->filaDeCompas->setRowCount(fdeCompras.size());

                int index = 0;

                for(int i = fdeCompras.size() - 1; i >= 0; i--){
                    ui->filaDeCompas->setItem(index, 0, new QTableWidgetItem(QString::fromStdString(fdeCompras.get(i)->valor.getNome())));
                    ui->filaDeCompas->setItem(index, 1, new QTableWidgetItem(QString::number(fdeCompras.get(i)->valor.getQuantidade())));
                    ui->filaDeCompas->setItem(index, 2, new QTableWidgetItem(QString::number(fdeCompras.get(i)->valor.getQuantidadeMinima())));
                    index++;
                }
            }

            //QMessageBox::information(this, "Sucesso", "Produto criado com sucesso");
            int row = produtosLista.size()-1;
            ui->listaProdutosTable->setRowCount(row+1);

            for(int i = 0; i < produtosLista.size(); i++){

                Produto currentProduto = produtosLista.get(i)->valor;

                ui->listaProdutosTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(currentProduto.getNome())));
                ui->listaProdutosTable->setItem(i, 1, new QTableWidgetItem(QString::number(currentProduto.getPreco())));
                ui->listaProdutosTable->setItem(i, 2, new QTableWidgetItem(QString::number(currentProduto.getQuantidade())));
                ui->listaProdutosTable->setItem(i, 3, new QTableWidgetItem(QString::number(currentProduto.getTamanho())));
                ui->listaProdutosTable->setItem(i, 4, new QTableWidgetItem(QString::number(currentProduto.getPrioridade())));
            }
        }else{
            QMessageBox::warning(this, "Corrija os erros para continuar", "Ocorreu um erro ao criar o produto");
        }
    }else{
        QMessageBox::warning(this, "Erro", errors);
    }

}

void MainWindow::on_nomeAddText_editingFinished()
{
    ui->nomeAddText->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0-9_]{0,255}"), this ));
}

void MainWindow::on_searchButton_clicked()
{
    string produtoName = ui->searchText->text().toStdString();

    Produto *searchProdutoNome = new Produto(produtoName);

    if(this->produtosLista.get(*searchProdutoNome)){
        Produto produtoEncontrado = this->produtosLista.get(*searchProdutoNome)->valor;

        ui->listaProdutosTable->setRowCount(1);
        ui->listaProdutosTable->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(produtoEncontrado.getNome())));
        ui->listaProdutosTable->setItem(0, 1, new QTableWidgetItem(QString::number(produtoEncontrado.getPreco())));
        ui->listaProdutosTable->setItem(0, 2, new QTableWidgetItem(QString::number(produtoEncontrado.getQuantidade())));
        ui->listaProdutosTable->setItem(0, 3, new QTableWidgetItem(QString::number(produtoEncontrado.getTamanho())));
        ui->listaProdutosTable->setItem(0, 4, new QTableWidgetItem(QString::number(produtoEncontrado.getPrioridade())));
    }else{
        QMessageBox::warning(this, "Não encontrado", "Produto não encontrado.");
    }

}

void MainWindow::on_deleteButton_clicked(){

    string produtoName = ui->searchText->text().toStdString();

    Produto *searchProdutoNome = new Produto(produtoName);

    if(produtosLista.remove(*searchProdutoNome)){
        QMessageBox::warning(this, "Sucesso", "Produto removido com sucesso");

        for(int i = 0; i < produtosLista.size(); i++){

            Produto currentProduto = produtosLista.get(i)->valor;
            ui->listaProdutosTable->setRowCount(produtosLista.size());
            ui->listaProdutosTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(currentProduto.getNome())));
            ui->listaProdutosTable->setItem(i, 1, new QTableWidgetItem(QString::number(currentProduto.getPreco())));
            ui->listaProdutosTable->setItem(i, 2, new QTableWidgetItem(QString::number(currentProduto.getQuantidade())));
            ui->listaProdutosTable->setItem(i, 3, new QTableWidgetItem(QString::number(currentProduto.getTamanho())));
            ui->listaProdutosTable->setItem(i, 4, new QTableWidgetItem(QString::number(currentProduto.getPrioridade())));
        }

    }else{
        QMessageBox::warning(this, "Erro", "Produto não encontrado");
    }
}


void MainWindow::on_listaProdutosTable_itemDoubleClicked(QTableWidgetItem *item){}

void MainWindow::on_listaProdutosTable_cellDoubleClicked(int row, int column){}

void MainWindow::on_listaProdutosTable_cellEntered(int row, int column){}

void MainWindow::on_searchButton_2_clicked(){}

void MainWindow::on_removeButton_clicked()
{

}
