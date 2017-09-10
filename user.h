#ifndef USER_H
#define USER_H
#include<QString>

class user
{
public:
    QString username;
    QString pass;
    QString district;
    user();
    virtual QString login(QString username_,QString pass_)=0;
    virtual int register_(QString name_,QString username_,QString pass_,QString address_,QString district_,QString pin_, QString cno_,QString rno)=0;
    virtual QString* see_all_product(int a) = 0;
    virtual QString check_capacity(QString pro) = 0;
    virtual QString check_capacity_both(QString pro) = 0;
    virtual QString check_ind_limit(QString prod,QString vuname, QString date5, QString qty_enter)= 0;
    virtual QString check_upper_limit(QString prod,QString date5,QString qty_enter) = 0;
};

#endif // USER_H
