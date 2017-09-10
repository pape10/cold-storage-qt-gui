#ifndef ENTER_REG_H
#define ENTER_REG_H

#include <QMainWindow>

namespace Ui {
class enter_reg;
}

class enter_reg : public QMainWindow
{
    Q_OBJECT

public:
    explicit enter_reg(QWidget *parent = 0);
    ~enter_reg();

private:
    Ui::enter_reg *ui;
};

#endif // ENTER_REG_H
