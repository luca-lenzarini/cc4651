#ifndef CADASTRARHOSPEDE_H
#define CADASTRARHOSPEDE_H

#include <QMainWindow>

namespace Ui {
class CadastrarHospede;
}

class CadastrarHospede : public QMainWindow
{
    Q_OBJECT

public:
    explicit CadastrarHospede(QWidget *parent = nullptr);
    ~CadastrarHospede();

private:
    Ui::CadastrarHospede *ui;
};

#endif // CADASTRARHOSPEDE_H
