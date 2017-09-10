#include "enter_reg.h"
#include "ui_enter_reg.h"

enter_reg::enter_reg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::enter_reg)
{
    ui->setupUi(this);
}

enter_reg::~enter_reg()
{
    delete ui;
}
