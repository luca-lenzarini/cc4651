#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Produto.h"
#include "LinkedList.h"
#include <QLineEdit>
#include <string>
#include <QMessageBox>
#include <iostream>
#include <stdio.h>

using namespace std;

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
            QMessageBox::information(this, "Sucesso", "Produto criado com sucesso");
            int row = produtosLista.size()-1;
            ui->listaProdutosTable->setRowCount(row+1);

            ui->listaProdutosTable->setItem(row, 0, new QTableWidgetItem(nome));
            ui->listaProdutosTable->setItem(row, 1, new QTableWidgetItem(preco));
            ui->listaProdutosTable->setItem(row, 2, new QTableWidgetItem(qtd));
            ui->listaProdutosTable->setItem(row, 3, new QTableWidgetItem(tamanho));
            ui->listaProdutosTable->setItem(row, 4, new QTableWidgetItem(prioridade));

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
    Produto produtoEncontrado;

    LinkedList<Produto> novaLista = this->produtosLista;

    bool buscaRetorno = this->produtosLista.busca(*searchProdutoNome, &produtoEncontrado);


    if(buscaRetorno){
        ui->searchTable->setRowCount(1);
        ui->searchTable->setItem(0, 0, new QTableWidgetItem(produtoEncontrado.getQuantidade()));
        ui->searchTable->setItem(0, 1, new QTableWidgetItem(produtoEncontrado.getPreco()));
        ui->searchTable->setItem(0, 0, new QTableWidgetItem(produtoEncontrado.getTamanho()));
    }else{
        QMessageBox::warning(this, "Erro", "Produto não encontrado.");
    }
}
