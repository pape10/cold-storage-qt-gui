#include "user_admin.h"
#include<string.h>
#include<QFile>
#include<string>
#include<iostream>
#include<fstream>
#include <cstdio>
#include "session.h"
#include "search_string.h"
#include<QMessageBox>
#include "generate_rand2.h"
using namespace std;
user_admin::user_admin()
{

}
QString user_admin::login(QString username_p,QString pass_p)
{
    QString notTrue = "login_failed";
    QString u,p,d;
    std::string username_ =username_p.toUtf8().constData();
    std::string pass_ = pass_p.toUtf8().constData();
    ifstream i;
    int checkeq=0;

        i.open("/home/pape/cold_storage/database/user/admin/admin.csv");
        std::string s;
        while(! i.eof())
        {
            checkeq=0;
            getline(i,s);

            std::string username,password,district_2;
            int ic = 0;
            int i,j,k;
            int len = s.length();
            for(i=1;i<len;i++)
            {
                if(s[i]==',' && ic==1)
                {
                    break;
                }
                if(s[i]!='\"')
                {
                username = username + s[i];
                }
                else
                {
                    ic=1;
                }
            }
            ic=0;
            for(j=i+1;j<len;j++)
            {
                if(s[j]==',' && ic==2)
                {
                    break;
                }
                 if(s[j]!='\"')
                {
                password = password + s[j];
                }
                else{
                    ic++;
                }
            }
            ic = 0;
            for(k=j+1;k<len;k++)
            {
                if(s[k]==',' && ic==2)
                {
                    break;
                }
                 if(s[k]!='\"')
                {
                district_2 = district_2 + s[k];
                }
                else{
                    ic++;
                }
            }
            d = QString::fromStdString(district_2);
            u = QString::fromStdString(username);
            p = QString::fromStdString(password);
            if(p == pass_p && u == username_p)
            {
                           checkeq=1;
                        break;
            }

          }
        if(checkeq==1)
        {
        username = u;
        pass = p;
        district = d;
        i.close();

        return d;
        }
        else
        {
            i.close();
            return notTrue;
        }
}

int user_admin::register_(QString name_,QString username_,QString pass_,QString address_,QString district_,QString pin_,QString cno_,QString reg_no)
{
    user_admin_id++;
    std::string name_1 =name_.toUtf8().constData();
    std::string username_1 = username_.toUtf8().constData();
    std::string pass_1 =pass_.toUtf8().constData();
    std::string address_1 =address_.toUtf8().constData();
    std::string district_1 = district_.toUtf8().constData();
    std::string pin_1 = pin_.toUtf8().constData();
    std::string cno_1 = cno_.toUtf8().constData();
    std::string region = reg_no.toUtf8().constData();
    ofstream m;
        m.open("/home/pape/cold_storage/database/user/admin/admin.csv",ios::app);
        m<<"\""<<username_1<<"\""<<","<<"\""<<pass_1<<"\""<<","<<"\""<<region<<"\""<<","<<"\""<<address_1<<"\""<<","<<"\""<<name_1<<"\""<<","<<"\""<<pin_1<<"\""<<","<<"\""<<cno_1<<"\""<<","<<"\""<<district_1<<"\""<<std::endl;
        m.close();
        std::string filename1 = "";
        filename1 = filename1 + "/home/pape/cold_storage/database/admin/product_detail/" + region + ".csv";
        ofstream o1;
        o1.open(filename1,ios::app);
        o1.close();
        std::string filename2 = "";
        filename2 = filename2 + "/home/pape/cold_storage/database/admin/transaction/buy_farmer/" + region + ".csv";
        ofstream i;
        i.open(filename2,ios::app);
        i.close();
        std::string filename12 = "";
        filename12 = filename12 + "/home/pape/cold_storage/database/admin/transaction/sell_vendor/" + region + ".csv";
        ifstream ff2;
        ff2.open(filename12,ios::app);
        ff2.close();
        return 1;
}
int user_admin::add_new(QString product_name, QString upperlimit, QString lowerlimit, QString indlimit, QString caplimit, QString pkg)
{
    std::string product_name_1 =product_name.toUtf8().constData();
    std::string upper_limit_1 = upperlimit.toUtf8().constData();
    std::string lower_limit_1 = lowerlimit.toUtf8().constData();
    std::string ind_limit_1 = indlimit.toUtf8().constData();
    std::string capacity = caplimit.toUtf8().constData();
    std::string price = pkg.toUtf8().constData();
    std::string filename = "";
    std::string username = district_global.toUtf8().constData();
    filename = filename + "/home/pape/cold_storage/database/admin/product_detail/" + username + ".csv";
    ofstream o;
    o.open(filename,ios::app);
    o<<"\""<<product_name_1<<"\""<<","<<"\""<<upper_limit_1<<"\""<<","<<"\""<<lower_limit_1<<"\""<<","<<"\""<<ind_limit_1<<"\""<<","<<"\""<<capacity<<"\""<<","<<"\""<<price<<"\""<<std::endl;
    o.close();

    return 1;
}
QString* user_admin::see_all_product(int a)
{
    std::string username = district_global.toUtf8().constData();
    std::string filename = "";
    filename = filename + "/home/pape/cold_storage/database/admin/product_detail/" + username + ".csv";
    ifstream i;
    i.open(filename);
    std::string s;
    int ctr=0;
    while( !i.eof())
    {
        getline(i,s);
        ctr++;
    }
    i.close();
    QString* pro = new QString[ctr];
    std::string p;
    ifstream q;
    int j=0;
    q.open(filename);
    int f=0;
    while (!q.eof()) {
        getline(q,p);
        int i,ic=0;
        std::string ppp;
         int len = p.length();
        for(i=1;i<len;i++)
        {
            if(p[i]==',' && ic==1)
            {
                break;
            }
            if(p[i]!='\"')
            {
            ppp= ppp + p[i];
            }
            else
            {
                ic=1;
            }
        }
        if(f>=a)
        {
            pro[j] = QString::fromStdString(ppp);
            j++;
        }
        f++;
    }
    q.close();
    return pro;
}
int user_admin::buy_farmer(QString product_name, QString qty, QString farname, QString date_buy, QString pkg, QString price)
{
    std::string pname = product_name.toUtf8().constData();
    std::string quantity = qty.toUtf8().constData();
    std::string farmer = farname.toUtf8().constData();
    std::string buydate = date_buy.toUtf8().constData();
    std::string pricekg = pkg.toUtf8().constData();
    std::string price_ = price.toUtf8().constData();
    std::string username = district_global.toUtf8().constData();
    std::string filename = "";
    filename = filename + "/home/pape/cold_storage/database/admin/transaction/buy_farmer/" + username + ".csv";
    ofstream i;
    i.open(filename,ios::app);
    i<<"\""<<pname<<"\""<<","<<"\""<<quantity<<"\""<<","<<"\""<<farmer<<"\""<<","<<"\""<<buydate<<"\""<<","<<"\""<<pricekg<<"\""<<","<<"\""<<price_<<"\""<<std::endl;
    i.close();
    return 1;
}
int user_admin::sell_vendor(QString product_name, QString qty, QString varname, QString date_buy, QString pkg, QString price, QString vendorname)
{
    std::string pname = product_name.toUtf8().constData();
    std::string quantity = qty.toUtf8().constData();
    std::string vendor = varname.toUtf8().constData();
    std::string buydate = date_buy.toUtf8().constData();
    std::string pricekg = pkg.toUtf8().constData();
    std::string price_ = price.toUtf8().constData();
    std::string vendor_name = vendorname.toUtf8().constData();
    std::string username = district_global.toUtf8().constData();
    std::string filename = "";
    std::string random1 = generate_rand12();
    filename = filename + "/home/pape/cold_storage/database/admin/transaction/sell_vendor/" + username + ".csv";
    ofstream i;
    i.open(filename,ios::app);
    i<<"\""<<pname<<"\""<<","<<"\""<<quantity<<"\""<<","<<"\""<<vendor<<"\""<<","<<"\""<<buydate<<"\""<<","<<"\""<<pricekg<<"\""<<","<<"\""<<price_<<"\""<<","<<"\""<<vendor_name<<"\""<<","<<"\""<<random1<<"\""<<std::endl;
    i.close();
    QMessageBox msgBox;
    std::string resul = "your unique transaction id is " + random1;
    QString result =QString::fromStdString(resul);
    msgBox.setText(result);
    msgBox.exec();
    return 1;
}
QString user_admin::check_capacity(QString pro)
{
        std::string str_ = pro.toUtf8().constData();
        std::string username = district_global.toUtf8().constData();
        std::string filename = "";
        filename = filename + "/home/pape/cold_storage/database/admin/transaction/buy_farmer/" + username + ".csv";
        ifstream ff;
        ff.open(filename);
        std::string s;
        int cap=0;
        while(! ff.eof())
        {
            getline(ff,s);

            std::string pro_name,qty;
            int ic = 0;
            int i,j;
            int len = s.length();
            for(i=1;i<len;i++)
            {
                if(s[i]==',' && ic==1)
                {
                    break;
                }
                if(s[i]!='\"')
                {
                pro_name = pro_name + s[i];
                }
                else
                {
                    ic=1;
                }
            }
            if(pro_name == str_)
            {
                ic=0;
                int j;
                for(j=i+1;j<len;j++)
                {
                    if(s[j]==',' && ic==1)
                    {
                        break;
                    }
                    if(s[j]!='\"')
                    {
                    qty = qty + s[j];
                    }
                    else
                    {
                        ic=1;
                    }
                }
                int qty1 = atoi(qty.c_str());
                cap = cap + qty1;

            }
        }
        ff.close();
        std::string filename1 = "";
        filename1 = filename1 + "/home/pape/cold_storage/database/admin/transaction/sell_vendor/" + username + ".csv";
        ifstream ff2;
        ff2.open(filename1);
        std::string s1;
        while(! ff2.eof())
        {
            getline(ff2,s1);

            std::string pro_name,qty;
            int ic = 0;
            int i,j;
            int len = s1.length();
            for(i=1;i<len;i++)
            {
                if(s1[i]==',' && ic==1)
                {
                    break;
                }
                if(s1[i]!='\"')
                {
                pro_name = pro_name + s1[i];
                }
                else
                {
                    ic=1;
                }
            }
            if(pro_name == str_)
            {
                ic=0;
                int j;
                for(j=i+1;j<len;j++)
                {
                    if(s1[j]==',' && ic==1)
                    {
                        break;
                    }
                    if(s1[j]!='\"')
                    {
                    qty = qty + s1[j];
                    }
                    else
                    {
                        ic=1;
                    }
                }
                int qty1 = atoi(qty.c_str());
                cap = cap - qty1;

            }
        }
        ff2.close();
        std::string ss = std::to_string(cap);
        return QString::fromStdString(ss);
}
QString user_admin::check_capacity_both(QString pro)
{
        std::string str_ = pro.toUtf8().constData();
        std::string username = district_global.toUtf8().constData();
        std::string filename = "";
        filename = filename + "/home/pape/cold_storage/database/admin/transaction/buy_farmer/" + username + ".csv";
        ifstream ff;
        ff.open(filename);
        std::string s;
        int cap=0;
        while(! ff.eof())
        {
            getline(ff,s);

            std::string pro_name,qty;
            int ic = 0;
            int i,j;
            int len = s.length();
            for(i=1;i<len;i++)
            {
                if(s[i]==',' && ic==1)
                {
                    break;
                }
                if(s[i]!='\"')
                {
                pro_name = pro_name + s[i];
                }
                else
                {
                    ic=1;
                }
            }
            if(pro_name == str_)
            {
                ic=0;
                int j;
                for(j=i+1;j<len;j++)
                {
                    if(s[j]==',' && ic==1)
                    {
                        break;
                    }
                    if(s[j]!='\"')
                    {
                    qty = qty + s[j];
                    }
                    else
                    {
                        ic=1;
                    }
                }
                int qty1 = atoi(qty.c_str());
                cap = cap + qty1;

            }
        }
        ff.close();
        std::string filename3 = "";
        filename3 = filename3 + "/home/pape/cold_storage/database/admin/rent_farmer/" + username + ".csv";
        ifstream ff3;
        ff3.open(filename3);
        std::string s3;
        while(! ff3.eof())
        {
            getline(ff3,s3);

            std::string pro_name,qty;
            int ic = 0;
            int i,j;
            int len = s3.length();
            for(i=1;i<len;i++)
            {
                if(s3[i]==',' && ic==1)
                {
                    break;
                }
                if(s3[i]!='\"')
                {
                pro_name = pro_name + s3[i];
                }
                else
                {
                    ic=1;
                }
            }
            if(pro_name == str_)
            {
                ic=0;
                int j;
                for(j=i+1;j<len;j++)
                {
                    if(s3[j]==',' && ic==1)
                    {
                        break;
                    }
                    if(s3[j]!='\"')
                    {
                    qty = qty + s3[j];
                    }
                    else
                    {
                        ic=1;
                    }
                }
                int qty1 = atoi(qty.c_str());
                cap = cap + qty1;

            }
        }
        ff.close();
        std::string filename1 = "";
        filename1 = filename1 + "/home/pape/cold_storage/database/admin/transaction/sell_vendor/" + username + ".csv";
        ifstream ff2;
        ff2.open(filename1);
        std::string s1;
        while(! ff2.eof())
        {
            getline(ff2,s1);

            std::string pro_name,qty;
            int ic = 0;
            int i,j;
            int len = s1.length();
            for(i=1;i<len;i++)
            {
                if(s1[i]==',' && ic==1)
                {
                    break;
                }
                if(s1[i]!='\"')
                {
                pro_name = pro_name + s1[i];
                }
                else
                {
                    ic=1;
                }
            }
            if(pro_name == str_)
            {
                ic=0;
                int j;
                for(j=i+1;j<len;j++)
                {
                    if(s1[j]==',' && ic==1)
                    {
                        break;
                    }
                    if(s1[j]!='\"')
                    {
                    qty = qty + s1[j];
                    }
                    else
                    {
                        ic=1;
                    }
                }
                int qty1 = atoi(qty.c_str());
                cap = cap - qty1;

            }
        }
        ff2.close();
        std::string ss = std::to_string(cap);
        return QString::fromStdString(ss);
}
QString user_admin::check_ind_limit(QString prod,QString vuname,QString date5,QString qty_enter)
{
    std::string pro_str = prod.toUtf8().constData();
    std::string str_ = vuname.toUtf8().constData();
    std::string date1 = date5.toUtf8().constData();
    std::string qty_e = qty_enter.toUtf8().constData();
    std::string username = district_global.toUtf8().constData();
    std::string filename = "";
    filename = filename + "/home/pape/cold_storage/database/admin/transaction/sell_vendor/" + username + ".csv";
    ifstream ff;
    ff.open(filename);
    std::string s;

    int ind=0;
    while(! ff.eof())
    {
        getline(ff,s);
        std::string pro_name,qty,vendor_name,date_file;
        int ic = 0;
        int i;
        int len = s.length();
        for(i=1;i<len;i++)
        {
            if(s[i]==',' && ic==1)
            {
                break;
            }
            if(s[i]!='\"')
            {
                pro_name = pro_name + s[i];
            }
            else
            {
                ic=1;
            }
        }
        if(pro_name == pro_str)
        {
            ic=0;
            int j;
            for(j=i+1;j<len;j++)
            {
                if(s[j]==',' && ic==1)
                {
                    break;
                }
                if(s[j]!='\"')
                {
                    qty = qty + s[j];
                }
                else
                {
                    ic=1;
                }
            }
            ic=0;
            int k;
            for(k=j+1;k<len;k++)
            {
                if(s[k]==',' && ic==1)
                {
                    break;
                }
                if(s[k]!='\"')
                {
                    vendor_name = vendor_name + s[k];
                }
                else
                {
                    ic=1;
                }
            }
            if(vendor_name == str_)
            {

            ic=0;
            int l;
            for(l=k+1;l<len;l++)
            {
                if(s[l]==',' && ic==1)
                {
                    break;
                }
                if(s[l]!='\"')
                {
                    date_file = date_file + s[l];
                }
                else
                {
                    ic=1;
                }
            }
            if(date_file == date1)
            {
                int qty1 = atoi(qty.c_str());
                ind = ind + qty1;
            }
        }
        }
    }
    ff.close();
    int qty1 = atoi(qty_e.c_str());
    ind = ind + qty1;
    std::string ss = std::to_string(ind);
    return QString::fromStdString(ss);
}
QString user_admin::check_upper_limit(QString prod,QString date5,QString qty_enter)
{
    std::string pro_str = prod.toUtf8().constData();
    std::string date1 = date5.toUtf8().constData();
    std::string qty_e = qty_enter.toUtf8().constData();
    std::string username = district_global.toUtf8().constData();
    std::string filename = "";
    filename = filename + "/home/pape/cold_storage/database/admin/transaction/sell_vendor/" + username + ".csv";
    ifstream ff;
    ff.open(filename);
    std::string s;

    int ind=0;
    while(! ff.eof())
    {
        getline(ff,s);
        std::string pro_name,qty,date_file;
        int ic = 0;
        int i;
        int len = s.length();
        for(i=1;i<len;i++)
        {
            if(s[i]==',' && ic==1)
            {
                break;
            }
            if(s[i]!='\"')
            {
                pro_name = pro_name + s[i];
            }
            else
            {
                ic=1;
            }
        }
        if(pro_name == pro_str)
        {
            ic=0;
            int j;
            for(j=i+1;j<len;j++)
            {
                if(s[j]==',' && ic==1)
                {
                    break;
                }
                if(s[j]!='\"')
                {
                    qty = qty + s[j];
                }
                else
                {
                    ic=1;
                }
            }
            ic=0;
            int k;
            for(k=j+1;k<len;k++)
            {
                if(s[k]==',' && ic==1)
                {
                    break;
                }
                if(s[k]!='\"')
                {

                }
                else
                {
                    ic=1;
                }
            }
            ic=0;
            int l;
            for(l=k+1;l<len;l++)
            {
                if(s[l]==',' && ic==1)
                {
                    break;
                }
                if(s[l]!='\"')
                {
                    date_file = date_file + s[l];
                }
                else
                {
                    ic=1;
                }
            }
            if(date_file == date1)
            {
                int qty1 = atoi(qty.c_str());
                ind = ind + qty1;
            }
        }
    }
    ff.close();
    int qty1 = atoi(qty_e.c_str());
    ind = ind + qty1;
    std::string ss = std::to_string(ind);
    return QString::fromStdString(ss);
}
QString user_admin::check_delivery_status(QString unique_id)
{
    std::string search = unique_id.toUtf8().constData();
    std::string username = district_global.toUtf8().constData();
    std::string filename = "";
    filename = filename + "/home/pape/cold_storage/database/admin/transaction/sell_vendor/" + username + ".csv";
    ifstream ff;
    ff.open(filename);
    std::string s;
    while(! ff.eof())
    {
        std::string res = "the product name is ";
        getline(ff,s);


        int ic = 0;
        int i;
        int len = s.length();
        for(i=1;i<len;i++)
        {
            if(s[i]==',' && ic==1)
            {
                break;
            }
            if(s[i]!='\"')
            {
                res  = res + s[i];
            }
            else
            {
                ic=1;
            }
        }
        res = res + "\n second field ";
        ic = 0;
        int j;

        for(j=i+1;j<len;j++)
        {
            if(s[j]==',' && ic==1)
            {
                break;
            }
            if(s[j]!='\"')
            {
                res = res + s[j];
            }
            else
            {
                ic=1;
            }
        }

        res = res + "\n third field ";
        ic = 0;
        int k;

        for(k=j+1;k<len;k++)
        {
            if(s[k]==',' && ic==1)
            {
                break;
            }
            if(s[k]!='\"')
            {
                res = res + s[k];
            }
            else
            {
                ic=1;
            }
        }

        res = res + "\n fourth field ";
       ic = 0;
        int l;

        for(l=k+1;l<len;l++)
        {
            if(s[l]==',' && ic==1)
            {
                break;
            }
            if(s[l]!='\"')
            {
                res = res + s[l];
            }
            else
            {
                ic=1;
            }
        }
        res = res + "\n fifth field ";
       ic = 0;
        int m;

        for(m=l+1;m<len;m++)
        {
            if(s[m]==',' && ic==1)
            {
                break;
            }
            if(s[m]!='\"')
            {
                res = res + s[m];
            }
            else
            {
                ic=1;
            }
        }
        res = res + "\n sixth field ";
       ic = 0;
        int n;

        for(n=m+1;l<len;n++)
        {
            if(s[n]==',' && ic==1)
            {
                break;
            }
            if(s[n]!='\"')
            {
                res = res + s[n];
            }
            else
            {
                ic=1;
            }
        }
        res = res + "\n seventh field ";
       ic = 0;
        int o;

        for(o=n+1;o<len;o++)
        {
            if(s[o]==',' && ic==1)
            {
                break;
            }
            if(s[o]!='\"')
            {
                res = res + s[o];
            }
            else
            {
                ic=1;
            }
        }

        res = res + "\n eight field ";
       ic = 0;
        int p;
        std::string uid;
        for(p=o+1;p<len;p++)
        {
            if(s[p]==',' && ic==1)
            {
                break;
            }
            if(s[p]!='\"')
            {
                res = res + s[p];
                uid = uid + s[p];
            }
            else
            {
                ic=1;
            }
        }

        if(uid == search)
        {
        QString dis = QString::fromStdString(res);
        ff.close();
        return dis;
}
    }
    ff.close();
    return "not true";
}
QString user_admin::modify(QString n,QString ul,QString ll,QString il,QString c,QString p)
{
    std::string name = n.toUtf8().constData();
    std::string upper = ul.toUtf8().constData();
    std::string lower = ll.toUtf8().constData();
    std::string ind = il.toUtf8().constData();
    std::string cap = c.toUtf8().constData();
    std::string price = p.toUtf8().constData();
ofstream o;
std::string filename = "";
std::string username = district_global.toUtf8().constData();
filename = filename + "/home/pape/cold_storage/database/admin/product_detail/" + "temp" + ".csv";
o.open(filename,ios::app);
std::string filename1 = "";
filename1 = filename1 + "/home/pape/cold_storage/database/admin/product_detail/" + username + ".csv";
ifstream in;
in.open(filename1);
std::string s;
int ctr = 1;
while(! in.eof())
{
    std::string pn;
    getline(in,s);
    int i,ic=0;
    int len = s.length();
    for(i=1;i<len;i++)
    {
        if(s[i]==',' && ic==1)
        {
            break;
        }
        if(s[i]!='\"')
        {
        pn = pn + s[i];
        }
        else
        {
            ic=1;
        }
    }
    if(pn != name)
    {
        o<<s<<std::endl;
    }
    else if(pn == name)
    {
        o<<"\""<<name<<"\""<<","<<"\""<<upper<<"\""<<","<<"\""<<lower<<"\""<<","<<"\""<<ind<<"\""<<","<<"\""<<cap<<"\""<<","<<"\""<<price<<"\""<<std::endl;
        ctr = 2;
    }


}
in.close();
o.close();
QString fff = QString::fromStdString(filename1);
QFile::remove(fff);
QString fff1 = QString::fromStdString(filename);
QFile::rename(fff1,fff);
if(ctr == 2)
{
    return "true";
}
else
{
    return "false";
}

}

user_admin::~user_admin()
{

}
