#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include "user.h"
#include "user_admin.h"
#include<fstream>
#include "session.h"
#include "register_window.h"
#include "admin_window.h"
#include "user_vendor.h"
#include "vendor_window.h"
#include "form_validate.h"
#include "farmer_window.h"
#include "user_farmer.h"
QString user_global;
QString cat_global;
QString district_global;
user_admin u_a_g;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString user_ = ui->login_user->text();
    QString pass_ = ui->login_pass->text();
    QString selected;
    ui->login_pass->setText("");
    ui->login_user->setText("");
    if(ui->radio_admin->isChecked())
        selected = "admin";
    else if(ui->radio_vendor->isChecked())
        selected = "vendor";
    else if(ui->radio_farmer->isChecked())
    {
        selected = "farmer";
    }
    if(selected == "admin")
    {
    user *p;
    user_admin uv;
    p=&uv;
    QString res=p->login(user_,pass_);

    cat_global = "admin";
    district_global = res;
    if(res !="login_failed")
    {
    admin_window *a = new admin_window;
    a->show();
    }
    else
    {
        ui->label_5->setText("password incorrect");
    }

    }
    else if(selected == "vendor")
    {
        user_vendor uv;
        QString res=uv.login(user_,pass_);
        ui->login_pass->setText(res);
        ui->login_user->setText("");
        district_global = res;
        cat_global = "vendor";
        if(res !="login_failed")
        {
            user_global = user_;
        vendor_window *a = new vendor_window;
        a->show();
        }
        else
        {
            ui->label_5->setText("password incorrect");
        }


    }
    else if(selected == "farmer")
    {
        user_farmer uv;
        QString res=uv.login(user_,pass_);
        ui->login_pass->setText(res);
        ui->login_user->setText("");
        district_global = res;
        cat_global = "farmer";
        if(res !="login_failed")
        {
            user_global = user_;
        farmer_window *a = new farmer_window;
        a->show();
        }
        else
        {
            ui->label_5->setText("password incorrect");
        }


    }
    else
    {
        ui->label_5->setText("you have not selected the type of account");
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    vendor_window *a = new vendor_window;
    a->show();
}

void MainWindow::on_pushButton_register_clicked()
{
    register_window *a = new register_window;
    a->show();
}
