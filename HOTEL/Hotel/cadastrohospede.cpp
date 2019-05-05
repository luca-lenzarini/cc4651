#include "cadastrohospede.h"
#include "ui_cadastrohospede.h"
#include <string>
#include "pessoa.h"
#include "avl.h"

static Avl<Pessoa> listaDeHospedes;

CadastroHospede::CadastroHospede(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CadastroHospede)
{
    ui->setupUi(this);
}

CadastroHospede::~CadastroHospede()
{
    delete ui;
}

void CadastroHospede::on_okButton_clicked()
{
    string name = ui->nameText->toPlainText().toUtf8().constData();
    int age = ui->ageText->toPlainText().split(" ")[0].toInt();

    Pessoa hospede(listaDeHospedes.getLastId() + 1, name, age);

    listaDeHospedes.insere(hospede);
}
