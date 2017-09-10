#include "admin_window.h"
#include "ui_admin_window.h"
#include "session.h"
#include "user.h"
#include "user_admin.h"
#include "functions.h"
#include "QComboBox"
#include <QDateTime>
int ctr = 0;
int cap;
admin_window::admin_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin_window)
{
    ui->setupUi(this);
    ui->comboBox->hide();
    ui->comboBox_2->hide();
    ui->scrollArea->hide();
}
admin_window::~admin_window()
{
    delete ui;
}
void admin_window::on_pushButton_clicked()
{
    int flag = 0;
    QString pname = ui->add_name->text();
    QString upper_limit = ui->add_ul->text();
    QString lower_limit = ui->add_ll->text();
    QString ind_limit = ui->add_ulv->text();
    QString capacity = ui->add_cap->text();
    QString pricekg = ui->price_kg->text();
    ui->add_name->setText("");
    ui->add_ul->setText("");
    ui->add_ll->setText("");
    ui->add_ulv->setText("");
    ui->add_cap->setText("");
    ui->price_kg->setText("");
    std::string product = pname.toUtf8().constData();
    std::string uui =pname.toUtf8().constData();
    std::string uiii = district_global.toUtf8().constData();
    std::string filename;
    filename = filename + "/home/pape/cold_storage/database/admin/product_detail/" + uiii + ".csv";

    int w = check_first2(filename,uui);
    if(w)
    {
        flag =1;
    }
    if(check_for_stringsa(upper_limit)||upper_limit == "")
        flag = 2;
    else if(check_for_stringsa(lower_limit)||lower_limit=="")
        flag = 3;
    else if(check_for_stringsa(ind_limit)||ind_limit=="")
        flag = 4;
    else if(check_for_stringsa(pricekg)||pricekg=="")
        flag = 5;
    else if(check_for_stringsa(capacity)||capacity=="")
        flag = 6;
    else
    {}
    if(flag == 0)
    {
        user_admin u;
    u.add_new(pname,upper_limit,lower_limit,ind_limit,capacity,pricekg);
    ui->label_36->setText("product has been added");
    }
    else if(flag == 1)
    {
        ui->label_36->setText("product already exists");
    }
    else if(flag == 2)
    {
        ui->label_36->setText("enter valid upper limit");
    }
    else if(flag == 3)
    {
        ui->label_36->setText("enter valid lower limit");
    }
    else if(flag == 4)
    {
        ui->label_36->setText("enter valid ind limit");
    }
    else if(flag == 5)
    {
        ui->label_36->setText("enter valid price limit");
    }
    else if(flag == 6)
    {
        ui->label_36->setText("enter valid cap limit");
    }
    else
    {

    }
}

void admin_window::on_refresh_seeall_clicked()
{

}

void admin_window::on_pushButton_2_clicked()
{
QString t = ui->search_product->text();
QString* res= search_product_name(t);
if(res[0] != "")
{

user_admin u;
QString res11 = u.check_capacity_both(t);

QString pr = search_price(t);
std::string capa = res[4].toUtf8().constData();
int qty2 = atoi(capa.c_str());
std::string capa1 = res11.toUtf8().constData();
int qty3 = atoi(capa1.c_str());
int cap1;
cap1 = qty2 - qty3;
std::string ss = std::to_string(cap1);
QString final_cap_left = QString::fromStdString(ss);
QString texted = "\n max space left for " + res[0] + " is = " + final_cap_left;
QString final = "product name is " + res[0] + "\n upper limit is " + res[1] + "\n lowerlimit is " + res[2] +"\n price per kg is" + pr + texted;
ui->label_7->setText(final);
}
else
{
    ui->label_7->setText("product not found in this district database");
}
}

void admin_window::on_pushButton_4_clicked()
{
    QString fname = ui->lineEdit->text();
    QString qty = ui->lineEdit_2->text();
    QString product_name = ui->comboBox->currentText();
    QString date_buy = ui->lineEdit_3->text();
    QString pkg = ui->lineEdit_4->text();
    QString price = ui->lineEdit_5->text();
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    std::string capa = qty.toUtf8().constData();
    int qty123 = atoi(capa.c_str());
    int flag =0;
       if(check_for_stringsa(pkg)||pkg=="")
           flag =1;
       else if(check_for_stringsa(price)||price=="")
           flag =2;
       else if(check_for_stringsa(qty)||qty=="")
           flag =3;

    if(qty123<=cap && flag == 0)
    {
        user_admin u;
    int x =u.buy_farmer(product_name,qty,fname,date_buy,pkg,price);
    if(x==1)
    {
        ui->label_25->setText("you have succesfully bought");
    }
    else
    {
        ui->label_25->setText("your order couldnot be processed");
    }
    }
    else if(flag ==1)
    {
        ui->label_25->setText("enter valid pkg");
    }
    else if(flag ==2)
    {
        ui->label_25->setText("enter valid price");
    }
    else if(flag ==1)
    {
        ui->label_25->setText("enter valid qty");
    }
    else
    {
        ui->label_25->setText("you are exceeding the stock limit");
    }
}
void admin_window::on_pushButton_6_clicked()
{
    ctr =0;
    ui->pushButton_6->hide();
        ui->comboBox->show();
        user_admin u;
        QString* as = u.see_all_product(0);
        int i=0;
        while(as[i]!="\0")
        {
            ui->comboBox->addItem(as[i]);
            i++;
            ctr++;
        }
        delete []as;
}

void admin_window::on_comboBox_currentTextChanged(const QString &arg1)
{
    QString res = search_price(arg1);
    ui->lineEdit_4->setText(res);
    user_admin u;
    QString res11 = u.check_capacity_both(arg1);
    QString capacity = search_cap(arg1);
    std::string capa = capacity.toUtf8().constData();
    int qty2 = atoi(capa.c_str());
    std::string capa1 = res11.toUtf8().constData();
    int qty3 = atoi(capa1.c_str());
    cap = qty2 - qty3;
    std::string ss = std::to_string(cap);
    QString final_cap_left = QString::fromStdString(ss);
    QString texted = "max space left for " + arg1 + " is = " + final_cap_left;
    ui->label_33->setText(texted);
}

void admin_window::on_refresh_vendor_clicked()
{
    ui->refresh_vendor->hide();
    ctr =0;
    ui->refresh_vendor->hide();
        ui->comboBox_2->show();
        user_admin u;
        QString* as = u.see_all_product(ctr);
        int i=0;
        while(as[i]!="\0")
        {
            ui->comboBox_2->addItem(as[i]);
            i++;
            ctr++;
        }
        delete []as;
}

void admin_window::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    QString res = search_price(arg1);
    ui->lineEdit_8->setText(res);
}

void admin_window::on_comboBox_2_activated(const QString &arg1)
{

}

void admin_window::on_pushButton_5_clicked()
{
    ui->label_32->setText("");
    int flag = 0;
    QString date2 = ui->dateEdit->text();
    QString vuname = ui->lineEdit_10->text();
    QString qty = ui->lineEdit_7->text();
    QString product_name = ui->comboBox_2->currentText();
    QString pkg = ui->lineEdit_8->text();
    QString price = ui->lineEdit_9->text();
    QString vname = ui->lineEdit_6->text();
    ui->lineEdit_10->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_9->setText("");
    user_admin u;
    QString res = u.check_ind_limit(product_name,vuname,date2,qty);
    QString res2 = search_ind_limit(product_name);
    std::string res_str = res.toUtf8().constData();
    std::string res2_str = res2.toUtf8().constData();
    int qty1 = atoi(res_str.c_str());
    int qty2 = atoi(res2_str.c_str());
    int net = qty2 - qty1;
    QString res3 = u.check_upper_limit(product_name,date2,qty);
    QString res4 = search_upper_limit(product_name);
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
     else if(check_for_stringsa(pkg)||pkg=="")
         flag=4;
     else if(check_for_stringsa(price)||price=="")
         flag=5;
     else if(check_for_stringsa(qty)||qty=="")
         flag=6;
    else
    {
    }
    if(flag == 0)
    {
    int x =u.sell_vendor(product_name,qty,vuname,date2,pkg,price,vname);
    if(x==1)
    {
        ui->label_32->setText("you have succesfully bought");
    }
    else
    {
        ui->label_32->setText("your order couldnot be processed");
    }
    }
    if(flag == 1)
        ui->label_32->setText("you have exceeded your daily ind limit of this product");
    else if(flag == 2)
        ui->label_32->setText("upper limit for this particular product has been reached");
    else if(flag == 3)
    {
        ui->label_32->setText("there is not this much stock left");
    }
    else if(flag == 4)
    {
        ui->label_32->setText("enter valid price/kg");
    }
    else if(flag == 5)
    {
        ui->label_32->setText("enter valid price");
    }
    else if(flag == 6)
    {
        ui->label_32->setText("enter valid qty");
    }
    else
    {
    }
}

void admin_window::on_pushButton_7_clicked()
{
    QString pname = ui->lineEdit_12->text();
    QString* res= search_product_name(pname);
    if(res[0] != "")
    {
        QString p =search_price(pname);
        ui->lineEdit_13->setText(res[1]);
        ui->lineEdit_14->setText(res[2]);
        ui->lineEdit_15->setText(res[3]);
        ui->lineEdit_16->setText(p);
        ui->lineEdit_17->setText(res[4]);
    }
    else
    {
    ui->label_42->setText("product not found");
    }
}

void admin_window::on_submit_check_clicked()
{

}

void admin_window::on_sub_clicked()
{
    QString uid = ui->lineEdit_11->text();
    user_admin u;
    QString dis = u.check_delivery_status(uid);
    if(dis != "not true")
    ui->label_38->setText(dis);
    else
        ui->label_38->setText("unique id not found");
}

void admin_window::on_pushButton_8_clicked()
{
    int flag = 0;
    QString pname = ui->lineEdit_12->text();
    QString ul = ui->lineEdit_13->text();
    QString ll = ui->lineEdit_14->text();
    QString il = ui->lineEdit_15->text();
    QString p = ui->lineEdit_16->text();
    QString cap = ui->lineEdit_17->text();
    ui->lineEdit_12->setText("");
    ui->lineEdit_13->setText("");
    ui->lineEdit_14->setText("");
    ui->lineEdit_15->setText("");
    ui->lineEdit_16->setText("");
    ui->lineEdit_17->setText("");
    if(check_for_stringsa(ul)||ul =="")
        flag = 1;
    else if(check_for_stringsa(ll)||ll=="")
        flag = 2;
    else if(check_for_stringsa(il)||il=="")
        flag = 3;
    else if(check_for_stringsa(p)||p=="")
        flag = 4;
    else if(check_for_stringsa(cap)||cap=="")
        flag = 5;
    else
    {}
    if(flag == 0)
    {

    user_admin u;
    QString fin = u.modify(pname,ul,ll,il,p,cap);
    if(fin == "true")
        ui->label_42->setText("modification succesful");
    else
        ui->label_42->setText("modification unsuccesful");
    }
    else if(flag == 1)
    {
        ui->label_42->setText("enter valid upper limit");
    }
    else if(flag == 2)
    {
        ui->label_42->setText("enter valid lower limit");
    }
    else if(flag == 3)
    {
        ui->label_42->setText("enter valid ind limit");
    }
    else if(flag == 4)
    {
        ui->label_42->setText("enter valid price limit");
    }
    else if(flag == 5)
    {
        ui->label_42->setText("enter valid cap limit");
    }
    else
    {

    }

}

void admin_window::on_refresh_again_clicked()
{
    ui->pushButton_3->hide();
    ui->scrollArea->show();
    user_admin u_a;
    QString* as = u_a.see_all_product(ctr);
    int i=0;
    while(as[i]!="\0")
    {
        QPushButton *b = new QPushButton;
        b->setText(as[i]);
        ui->verticalLayout_2->addWidget(b);
        i++;
        ctr++;
    }
    delete []as;
}

void admin_window::on_comboBox_activated(const QString &arg1)
{

}

void admin_window::on_pushButton_9_clicked()
{
   qApp->exit();
}
