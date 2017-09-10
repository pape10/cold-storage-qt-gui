#ifndef USER_FARMER_H
#define USER_FARMER_H
#include<QString>
#include "user_admin.h"
#include "user.h"
class user_farmer:public user
{
public:
    user_farmer();
    QString login(QString username_p, QString pass_p);
    int register_(QString name_,QString username_,QString pass_,QString address_,QString district_,QString pin_, QString cno_,QString rno);
    QString get_address();
    QString* see_all_product(int a);
    QString check_capacity(QString pro);
    QString check_capacity_both(QString pro);
    QString check_ind_limit(QString prod,QString vuname, QString date5, QString qty_enter);
    QString check_upper_limit(QString prod,QString date5,QString qty_enter);
    int sell_vendor(QString product_name,QString qty,QString varname,QString date_buy,QString pkg,QString price,QString vendorname);
    int rent(QString product_name,QString qty,QString farname,QString date_buy,QString pkg,QString price);
};

#endif // USER_FARMER_H
