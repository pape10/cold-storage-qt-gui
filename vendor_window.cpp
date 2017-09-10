#include "vendor_window.h"
#include "ui_vendor_window.h"
#include "user.h"
#include "user_vendor.h"
#include "function3.h"
#include "QString"
int ctr2 = 0;
int cap2= 0;
vendor_window::vendor_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vendor_window)
{
    ui->setupUi(this);
    ui->scrollArea->hide();
}

vendor_window::~vendor_window()
{
    delete ui;
}



void vendor_window::on_refresh_clicked()
{
   ui->pushButton->hide();
    ui->scrollArea->show();
    user_vendor us;
    QString* as = us.see_all_product(ctr2);
    int i=0;
    while(as[i]!="\0")
    {
        QPushButton *b = new QPushButton;
        b->setText(as[i]);
        ui->verticalLayout->addWidget(b);
        i++;
        ctr2++;
    }
    delete []as;
}

void vendor_window::on_pushButton_100_clicked()
{
    QString t = ui->lineEdit->text();
    QString res= search_product_namev(t);
    ui->label->setText(res);
    QString ulll= search_upper_limitv(t);
    ui->label_2->setText(ulll);
    QString lll = search_lower_limitv(t);
    ui->label_3->setText(lll);
    QString indl = search_lower_limitv(t);
    ui->label_4->setText(indl);
    QString cap = search_capv(t);
    ui->label_5->setText(cap);
}


void vendor_window::on_pushButton_2_clicked()
{
qApp->exit();
}

void vendor_window::on_refresh_vendor_clicked()
{
    ui->refresh_vendor->hide();
    ctr2 =0;
        user_vendor us;
        QString* as = us.see_all_product(ctr2);
        int i=0;
        while(as[i]!="\0")
        {
            ui->comboBox->addItem(as[i]);
            i++;
            ctr2++;
        }
        delete []as;
}

void vendor_window::on_comboBox_currentTextChanged(const QString &arg1)
{
    QString res = search_pricev(arg1);
    ui->lineEdit_2->setText(res);
}

void vendor_window::on_pushButton_3_clicked()
{
    ui->label_6->setText("");
    int flag = 0;
    QString date2 = ui->dateEdit->text();
    QString vuname = user_global;
    QString qty = ui->vendor_qty->text();
    QString product_name = ui->comboBox->currentText();
    QString pkg = ui->lineEdit_2->text();
    QString price = ui->vendor_price->text();
    QString vname = ui->vendor_name->text();
    ui->vendor_name->setText("");
    ui->vendor_price->setText("");
    ui->vendor_qty->setText("");
    user_vendor u;
    QString res = u.check_ind_limit(product_name,vuname,date2,qty);
    QString res2 = search_ind_limitv(product_name);
    std::string res_str = res.toUtf8().constData();
    std::string res2_str = res2.toUtf8().constData();
    int qty1 = atoi(res_str.c_str());
    int qty2 = atoi(res2_str.c_str());
    int net = qty2 - qty1;
    QString res3 = u.check_upper_limit(product_name,date2,qty);
    QString res4 = search_upper_limitv(product_name);
    std::string res3_str = res3.toUtf8().constData();
    std::string res4_str = res4.toUtf8().constData();
    int qty3 = atoi(res3_str.c_str());
    int qty4 = atoi(res4_str.c_str());
    int net2 = qty4 - qty3;
    QString res11 = u.check_capacity(product_name);
    std::string res11_str = res11.toUtf8().constData();
     int qty11 = atoi(res11_str.c_str());
     std::string res12_str = qty.toUtf8().constData();
      int qty12 = atoi(res12_str.c_str());
     if(net<=0)
    {
        flag = 1;
    }

    else if(net2<=0)
    {
        flag = 2;
    }
    else if((qty11 - qty12)<=0)
     {
        flag = 3;
     }
    else
    {
    }
    if(flag == 0)
    {
    int x =u.sell_vendor(product_name,qty,vuname,date2,pkg,price,vname);
    if(x==1)
    {
        ui->label_6->setText("you have succesfully bought");
    }
    else
    {
        ui->label_6->setText("your order couldnot be processed");
    }
    }
    if(flag == 1)
        ui->label_6->setText("you have exceeded your daily ind limit of this product");
    else if(flag == 2)
        ui->label_6->setText("upper limit for this particular product has been reached");
    else if(flag == 3)
    {
        ui->label_6->setText("there is not this much stock left");
    }
    else
    {
    }
}

void vendor_window::on_check_status_clicked()
{
    QString uid = ui->lineEdit_3->text();
    user_vendor ua;
    QString dis = ua.check_delivery_status(uid);
    if(dis != "not true")
    ui->label_8->setText(dis);
    else
        ui->label_8->setText("unique id not found");
}
