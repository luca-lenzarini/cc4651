#ifndef CADASTROHOSPEDE_H
#define CADASTROHOSPEDE_H

#include <QMainWindow>

namespace Ui {
class CadastroHospede;
}

class CadastroHospede : public QMainWindow
{
    Q_OBJECT

public:
    explicit CadastroHospede(QWidget *parent = nullptr);
    ~CadastroHospede();

private slots:
    void on_okButton_clicked();

private:
    Ui::CadastroHospede *ui;
};

#endif // CADASTROHOSPEDE_H
