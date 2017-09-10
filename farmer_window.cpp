#include "farmer_window.h"
#include "ui_farmer_window.h"
#include "user_farmer.h"
#include "farmer_function.h"
#include<string>
farmer_window::farmer_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::farmer_window)
{
    ui->setupUi(this);
    ui->pushButton_4->hide();
}
int ctr3 = 0;
int capacity_int = 0;
farmer_window::~farmer_window()
{
    delete ui;
}

void farmer_window::on_pushButton_2_clicked()
{
qApp->exit();
}

void farmer_window::on_pushButton_clicked()
{
    QString t = ui->lineEdit->text();
    QString res= search_product_namef(t);
    if(res != "false")
    {
    QString ulll= search_upper_limitf(t);
    QString lll = search_lower_limitf(t);
    QString indl = search_lower_limitf(t);
    QString cap = search_capf(t);
    QString p = search_pricef(t);
    user_farmer u;
    QString res11 = u.check_capacity_both(t);
    QString capacity = search_capf(t);
    std::string capa = capacity.toUtf8().constData();
    int qty2 = atoi(capa.c_str());
    std::string capa1 = res11.toUtf8().constData();
    int qty3 = atoi(capa1.c_str());
    int cap1;
    cap1 = qty2 - qty3;
    std::string ss = std::to_string(cap1);
    QString final_cap_left = QString::fromStdString(ss);
    QString texted = "\n max space left for " + t + " is = " + final_cap_left;
    QString final = "product name is " + res + "\n upper limit is " + ulll + "\n lowerlimit is " + lll +"\n price per kg is" + p + texted;
    ui->label_2->setText(final);
    }
    else
    {
        ui->label_2->setText("product not found in this district database");
    }

}

void farmer_window::on_pushButton_3_clicked()
{
    ctr3 =0;
    ui->pushButton_3->hide();
        ui->comboBox->show();
        user_farmer u;
        QString* as = u.see_all_product(0);
        int i=0;
        while(as[i]!="\0")
        {
            ui->comboBox->addItem(as[i]);
            i++;
            ctr3++;
        }
        delete []as;
}

void farmer_window::on_comboBox_activated(const QString &arg1)
{

}
void farmer_window::on_comboBox_currentTextChanged(const QString &arg1)
{

    QString res = search_pricef(arg1);
    ui->lineEdit_2->setText(res);
    user_farmer u;
    QString res11 = u.check_capacity_both(arg1);
    QString capacity = search_capf(arg1);
    std::string capa = capacity.toUtf8().constData();
    int qty2 = atoi(capa.c_str());
    std::string capa1 = res11.toUtf8().constData();
    int qty3 = atoi(capa1.c_str());
    capacity_int = qty2 - qty3;
    std::string ss = std::to_string(capacity_int);
    QString final_cap_left = QString::fromStdString(ss);
    QString texted = "max space left for " + arg1 + " is = " + final_cap_left;
    ui->label_3->setText(texted);
}

void farmer_window::on_pushButton_5_clicked()
{
    QString fname = user_global;
    QString qty = ui->lineEdit_3->text();
    QString product_name = ui->comboBox->currentText();
    QString date_buy = ui->lineEdit_4->text();
    QString pkg = ui->lineEdit_2->text();
    QString price = ui->lineEdit_5->text();
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    std::string capa = qty.toUtf8().constData();
    int qty123 = atoi(capa.c_str());
    int flag =0;
       if(check_for_stringsf(pkg)||pkg=="")
           flag =1;
       else if(check_for_stringsf(price)||price=="")
           flag =2;
       else if(check_for_stringsf(qty)||qty=="")
           flag =3;

    if(qty123<=capacity_int && flag == 0)
    {
        user_farmer u;
    int x =u.rent(product_name,qty,fname,date_buy,pkg,price);
    if(x==1)
    {
        ui->label_3->setText("you have succesfully rented");
    }
    else
    {
        ui->label_3->setText("your order couldnot be processed");
    }
    }
    else if(flag ==1)
    {
        ui->label_3->setText("enter valid pkg");
    }
    else if(flag ==2)
    {
        ui->label_3->setText("enter valid price");
    }
    else if(flag ==1)
    {
        ui->label_3->setText("enter valid qty");
    }
    else
    {
        ui->label_3->setText("you are exceeding the stock limit");
    }
}

void farmer_window::on_refresh_see_clicked()
{
    ui->refresh_see->hide();
     ui->scrollArea_2->show();
     user_farmer us;
     QString* as = us.see_all_product(ctr3);
     int i=0;
     while(as[i]!="\0")
     {
         QPushButton *b = new QPushButton;
         b->setText(as[i]);
         ui->verticalLayout_5->addWidget(b);
         i++;
         ctr3++;
     }
     delete []as;
}
