#ifndef USER_ADMIN_H
#define USER_ADMIN_H
#include "user.h"
#include "string"
class user_admin:public user
{
public:
    static int user_admin_id;
    QString rno;
    user_admin();
    QString login(QString username_,QString pass_);
    int register_(QString name_, QString username_, QString pass_, QString address_, QString district_, QString pin_, QString cno_, QString reg_no);
    int add_new(QString product_name,QString upperlimit,QString lowerlimit,QString indlimit,QString caplimit,QString pkg);
    QString* see_all_product(int a);
    int buy_farmer(QString product_name,QString qty,QString farname,QString date_buy,QString pkg,QString price);
    int sell_vendor(QString product_name,QString qty,QString varname,QString date_buy,QString pkg,QString price,QString vendorname);
    QString check_capacity(QString pro);
    QString check_capacity_both(QString pro);
    QString check_ind_limit(QString prod,QString vuname, QString date5, QString qty_enter);
    QString check_upper_limit(QString prod,QString date5,QString qty_enter);
    QString check_delivery_status(QString unique_id);
    QString modify(QString n,QString ul,QString ll,QString il,QString c,QString p);
    ~user_admin();
};
#endif // USER_ADMIN_H
