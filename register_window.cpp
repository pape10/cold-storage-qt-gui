#include "register_window.h"
#include "ui_register_window.h"
#include "user.h"
#include "user_admin.h"
#include "string"
#include "user_vendor.h"
#include "user_farmer.h"
#include "function2.h"
register_window::register_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::register_window)
{
    ui->setupUi(this);
}

register_window::~register_window()
{
    delete ui;
}

void register_window::on_pushButton_clicked()
{
    ui->reg_admin_msg->setText("username already exists");
    int flag = 0;
    QString username=ui->register_username->text();
    QString name = ui->register_name->text();
    QString pass = ui->register_pass->text();
    QString address = ui->register_address->text();
    QString district = ui->register_district->text();
    QString pin = ui->register_pin->text();
    QString rno = ui->register_rno_2->text();
    QString capacity = ui->register_cap->text();
    QString contact = ui->register_contact->text();
    ui->register_name->setText("");
    ui->register_pass->setText("");
    ui->register_address->setText("");
    ui->register_cap->setText("");
    ui->register_district->setText("");
    ui->register_pin->setText("");
    ui->register_rno_2->setText("");
    ui->register_contact->setText("");
    ui->register_username->setText("");
    std::string d = rno.toUtf8().constData();
    std::string uname = username.toUtf8().constData();
        int cflag = 0;
    std::string filename = "/home/pape/cold_storage/database/user/admin/admin.csv";
    int w = check_first(filename,uname);
    if(w == 1)
    {
        flag = 1;
    }
    int y = check_third(filename,d);
    if(y == 1)
    {
        flag = 2;
    }
    if(flag == 0)
    {
    try{
            check_for_digits(district);
        }
        catch(int f)
        {
            cflag = 1;
        }
        try
        {
            check_for_digits(name);
        }
        catch(int f)
        {
            cflag = 2;
        }
        try
        {
            check_for_strings(pin);
        }
        catch(int f)
        {
            cflag = 3;
        }
        try
        {
            check_for_strings(contact);
        }
        catch(int f)
        {
            cflag = 4;
        }
        if(cflag == 0)
        {
            user *p;
            user_admin uv;
            p=&uv;
            int c=p->register_(name,username,pass,address,district,pin,contact,rno);
            if(c==1)
            {


                ui->reg_admin_msg->setText("your account has been created.login now");


            }


            else
            {
                ui->reg_admin_msg->setText("registration not succesful");
            }
        }
        else if(cflag == 1)
        {
            ui->reg_admin_msg->setText("enter appropriate region name");

            }
        else if(cflag == 2)
        {
        ui->reg_admin_msg->setText("enter appropriate name");
        }
        else if(cflag == 3)
        {
        ui->reg_admin_msg->setText("enter appropriate pin");
        }
        else if(cflag == 4)
        {
        ui->reg_admin_msg->setText("enter appropriate contact");
        }
        else
        {
        }
    }

    else if(flag == 1)
    {
        ui->reg_admin_msg->setText("username already exists");

    }
    else
    {
        ui->reg_admin_msg->setText("region already exists");

    }
}

void register_window::on_pushButton_4_clicked()
{

}


void register_window::on_pushButton_3_clicked()
{
    int flag = 0;
    QString name = ui->vendor_register_name->text();
    QString user1 = ui->vendor_register_user->text();
    QString pass = ui->vendor_register_pass->text();
    QString address = ui->vendor_register_address->text();
    QString district = ui->vendor_register_distric->text();
    QString pin = ui->vendor_register_pin->text();
    QString coldstore = ui->lineEdit->text();
    QString contact = ui->vendor_register_contact->text();
    ui->vendor_register_name->setText("");
    ui->vendor_register_pass->setText("");
    ui->vendor_register_address->setText("");
    ui->vendor_register_distric->setText("");
    ui->vendor_register_pin->setText("");
    ui->lineEdit->setText("");
    ui->vendor_register_contact->setText("");
    ui->vendor_register_user->setText("");
    std::string uname = user1.toUtf8().constData();
    std::string d =coldstore.toUtf8().constData();
    std::string filename = "/home/pape/cold_storage/database/user/vendor/vendor.csv";
    std::string filename1 = "/home/pape/cold_storage/database/user/admin/admin.csv";
    int w = check_first(filename,uname);
    int cflag = 0;
    if(w == 1)
    {
        flag = 1;
    }
    int y = check_third(filename1,d);
    if(y != 1)
    {
        flag = 2;
    }
    if(flag == 0)
    {
        try{
                check_for_digits(district);
            }
            catch(int f)
            {
                cflag = 1;
            }
            try
            {
                check_for_digits(name);
            }
            catch(int f)
            {
                cflag = 2;
            }
            try
            {
                check_for_strings(pin);
            }
            catch(int f)
            {
                cflag = 3;
            }
            try
            {
                check_for_strings(contact);
            }
            catch(int f)
            {
                cflag = 4;
            }
            if(cflag == 0)
            {
                //user *p;
                user_vendor uv;
                //p=&uv;
                 int c=uv.register_(name,user1,pass,address,district,pin,contact,coldstore);
                if(c==1)
                {
                    ui->label->setText("your account has been created.login now");
                }


                else
                {
                    ui->label->setText("registration not succesful");
                }
            }
            else if(cflag == 1)
            {
                ui->label->setText("enter appropriate district name");

                }
            else if(cflag == 2)
            {
            ui->label->setText("enter appropriate name");
            }
            else if(cflag == 3)
            {
            ui->label->setText("enter appropriate pin");
            }
            else if(cflag == 4)
            {
            ui->label->setText("enter appropriate contact");
            }
            else
            {
            }
    }
    else if(flag == 1)
    {
        ui->label->setText("username already exists");

    }
    else
        ui->label->setText("region coldstorage not available");
}


void register_window::on_pushButton_5_clicked()
{
    int flag = 0;
    QString name = ui->vendor_register_name_3->text();
    QString user1 = ui->vendor_register_user_3->text();
    QString pass = ui->vendor_register_pass_3->text();
    QString address = ui->vendor_register_address_3->text();
    QString district = ui->vendor_register_distric_3->text();
    QString pin = ui->vendor_register_pin_3->text();
    QString coldstore = ui->lineEdit_3->text();
    QString contact = ui->vendor_register_contact_3->text();
    ui->vendor_register_name_3->setText("");
    ui->vendor_register_pass_3->setText("");
    ui->vendor_register_address_3->setText("");
    ui->vendor_register_distric_3->setText("");
    ui->vendor_register_pin_3->setText("");
    ui->lineEdit_3->setText("");
    ui->vendor_register_contact_3->setText("");
    ui->vendor_register_user_3->setText("");
    std::string uname = user1.toUtf8().constData();
    std::string d = coldstore.toUtf8().constData();
    std::string filename = "/home/pape/cold_storage/database/user/farmer/farmer.csv";
    std::string filename1 = "/home/pape/cold_storage/database/user/admin/admin.csv";
    int w = check_first(filename,uname);
    int cflag = 0;
    if(w == 1)
    {
        flag = 1;
    }
    int y = check_third(filename1,d);
    if(y != 1)
    {
        flag = 2;
    }
    if(flag == 0)
    {
        try{
                check_for_digits(district);
            }
            catch(int f)
            {
                cflag = 1;
            }
            try
            {
                check_for_digits(name);
            }
            catch(int f)
            {
                cflag = 2;
            }
            try
            {
                check_for_strings(pin);
            }
            catch(int f)
            {
                cflag = 3;
            }
            try
            {
                check_for_strings(contact);
            }
            catch(int f)
            {
                cflag = 4;
            }
            if(cflag == 0)
            {
                //user *p;
                user_farmer uv;
                //p=&uv;
                 int c=uv.register_(name,user1,pass,address,district,pin,contact,coldstore);
                if(c==1)
                {
                    ui->label_8->setText("your account has been created.login now");
                }


                else
                {
                    ui->label_8->setText("registration not succesful");
                }
            }
            else if(cflag == 1)
            {
                ui->label_8->setText("enter appropriate district name");

                }
            else if(cflag == 2)
            {
            ui->label_8->setText("enter appropriate name");
            }
            else if(cflag == 3)
            {
            ui->label_8->setText("enter appropriate pin");
            }
            else if(cflag == 4)
            {
            ui->label_8->setText("enter appropriate contact");
            }
            else
            {
            }
    }
    else if(flag == 1)
    {
        ui->label_8->setText("username already exists");
    }
    else
        ui->label_8->setText("district name not available");
}
