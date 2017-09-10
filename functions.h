#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<fstream>
#include<string>
#include "session.h"
using namespace std;
QString* search_product_name(QString search)
{
    std::string str_ = search.toUtf8().constData();
    std::string username = district_global.toUtf8().constData();
    std::string filename = "";
    filename = filename + "/home/pape/cold_storage/database/admin/product_detail/" + username + ".csv";
    ifstream ff;
    ff.open(filename);
    QString *as = new QString[6];
    std::string s;
    while(! ff.eof())
    {
        getline(ff,s);
        std::string pro_name,pro_name1,upper,lower,ind,cap,price;
        int ic = 0;
        int i,ctr =0;
        int len = s.length();
        for(i=0;i<len;i++)
        {
            if(((s[i]==',') && ic%2 == 0)||(ic== 12))
            {
                ctr = ic/2;
            }
            else if(s[i] == '\"')
            {
                ic++;
            }
            else
            {
                pro_name1 = pro_name1 + s[i];
            }
            if(ctr == 1 )
            {
                pro_name= pro_name1;
                pro_name1 = "";
                ctr = 0;
            }
            else if(ctr == 2)
            {
                upper = pro_name1;
                pro_name1 = "";
                ctr = 0;
            }
            else if(ctr == 3)
            {
                lower = pro_name1;
                pro_name1 = "";
                ctr = 0;
            }
            else if(ctr == 4)
            {
                ind = pro_name1;
                pro_name1 = "";
                ctr = 0;
            }
            else if(ctr == 5)
            {
                cap = pro_name1;
                pro_name1 = "";
                ctr = 0;
            }
            else if(ctr == 6)
            {
                price = pro_name1;
                pro_name1 = "";
                ctr = 0;
            }

        }
        if(pro_name == str_)
        {
            as[0] = QString::fromStdString(pro_name);
            as[1] = QString::fromStdString(upper);
            as[2] = QString::fromStdString(lower);
            as[3] = QString::fromStdString(ind);
            as[4] = QString::fromStdString(cap);
            as[5] = QString::fromStdString(price);
            QString res = QString::fromStdString(upper);
            ff.close();
            return as;
        }
    }
    ff.close();
    return as;
}
QString search_upper_limit(QString search)
{
    std::string str_ = search.toUtf8().constData();
    std::string username = district_global.toUtf8().constData();
    std::string filename = "";
    filename = filename + "/home/pape/cold_storage/database/admin/product_detail/" + username + ".csv";
    ifstream ff;
    ff.open(filename);
    std::string s;
    while(! ff.eof())
    {
        getline(ff,s);

        std::string pro_name,upper,pro_name1;
        int ic = 0;
        int i,ctr =0;
        int len = s.length();
        for(i=0;i<len;i++)
        {
            if(s[i]==',' && ic%2 == 0)
            {
                ctr = ic/2;
            }
            else if(s[i] == '\"')
            {
                ic++;
            }
            else
            {
                pro_name1 = pro_name1 + s[i];
            }
            if(ctr == 1 )
            {
                pro_name= pro_name1;
                pro_name1 = "";
                ctr = 0;
            }
            else if(ctr == 2)
            {
                upper = pro_name1;
                pro_name1 = "";
                ctr = 0;
            }

        }
        if(pro_name == str_)
        {

            QString res = QString::fromStdString(upper);
            ff.close();
            return res;
        }
    }
    ff.close();
    return "false";
}
QString search_lower_limit(QString search)
{
    std::string str_ = search.toUtf8().constData();
    std::string username = district_global.toUtf8().constData();
    std::string filename = "";
    filename = filename + "/home/pape/cold_storage/database/admin/product_detail/" + username + ".csv";
    ifstream ff;
    ff.open(filename);
    std::string s;
    while(! ff.eof())
    {
        getline(ff,s);

        std::string pro_name,lower;
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
                    lower = lower + s[k];
                }
                else
                {
                    ic=1;
                }
            }
            QString res = QString::fromStdString(lower);
            ff.close();
            return res;
        }
    }
    ff.close();
    return "false";
}
QString search_ind_limit(QString search)
{
    std::string str_ = search.toUtf8().constData();
    std::string username = district_global.toUtf8().constData();
    std::string filename = "";
    filename = filename + "/home/pape/cold_storage/database/admin/product_detail/" + username + ".csv";
    ifstream ff;
    ff.open(filename);
    std::string s;
    while(! ff.eof())
    {
        getline(ff,s);

        std::string pro_name,indl;
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
                    indl = indl + s[l];
                }
                else
                {
                    ic=1;
                }
            }
            QString res = QString::fromStdString(indl);
            ff.close();
            return res;
        }
    }
    ff.close();
    return "false";
}
QString search_cap(QString search)
{
    std::string str_ = search.toUtf8().constData();
    std::string username = district_global.toUtf8().constData();
    std::string filename = "";
    filename = filename + "/home/pape/cold_storage/database/admin/product_detail/" + username + ".csv";
    ifstream ff;
    ff.open(filename);
    std::string s;
    while(! ff.eof())
    {
        getline(ff,s);

        std::string pro_name,cap;
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

                }
                else
                {
                    ic=1;
                }
            }
            ic=0;
            int m;
            for(m=l+1;m<len;m++)
            {
                if(s[m]==',' && ic==1)
                {
                    break;
                }
                if(s[m]!='\"')
                {
                    cap = cap + s[m];
                }
                else
                {
                    ic=1;
                }
            }
            QString res = QString::fromStdString(cap);
            ff.close();
            return res;
        }
    }
    ff.close();
    return "false";
}
QString search_price(QString search)
{
    std::string str_ = search.toUtf8().constData();
    std::string username = district_global.toUtf8().constData();
    std::string filename = "";
    filename = filename + "/home/pape/cold_storage/database/admin/product_detail/" + username + ".csv";
    ifstream ff;
    ff.open(filename);
    std::string s;
    while(! ff.eof())
    {
        getline(ff,s);

        std::string pro_name,price;
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

                }
                else
                {
                    ic=1;
                }
            }
            ic=0;
            int m;
            for(m=l+1;m<len;m++)
            {
                if(s[m]==',' && ic==1)
                {
                    break;
                }
                if(s[m]!='\"')
                {

                }
                else
                {
                    ic=1;
                }
            }
            ic=0;
            int n;
            for(n=m+1;n<len;n++)
            {
                if(s[n]==',' && ic==1)
                {
                    break;
                }
                if(s[n]!='\"')
                {
                    price = price + s[n];
                }
                else
                {
                    ic=1;
                }
            }
            QString res = QString::fromStdString(price);
            ff.close();
            return res;
        }
    }
    ff.close();
    return "false";
}
int check_first2(std::string s1,std::string s2)
{
    ifstream ff;
    ff.open(s1);
    std::string s;
    while(! ff.eof())
    {
        getline(ff,s);

        std::string pro_name;
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
        if(pro_name == s2)
        {
            ff.close();
            return 1;

        }
    }
    ff.close();
    return 0;
}
int check_third2(std::string s1,std::string s2)
{
    ifstream ff;
    ff.open(s1);
    std::string s;
    while(! ff.eof())
    {
        getline(ff,s);

        std::string pro_name;
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

            }
            else
            {
                ic=1;
            }
        }
        ic = 0;
        for(j=i+1;j<len;j++)
        {
            if(s[j]==',' && ic==1)
            {
                break;
            }
            if(s[j]!='\"')
            {

            }
            else
            {
                ic=1;
            }
        }
        ic = 0;
        for(k=j+1;k<len;k++)
        {
            if(s[k]==',' && ic==1)
            {
                break;
            }
            if(s[k]!='\"')
            {
            pro_name = pro_name + s[k];
            }
            else
            {
                ic=1;
            }
        }
        if(pro_name == s2)
        {
            ff.close();
            return 1;

        }
    }
    ff.close();
    return 0;
}
int check_for_digitsa(QString s1)
{
    std::string s = s1.toUtf8().constData();
    if (std::string::npos != s.find_first_of("0123456789"))
    return 1;
    else
    {
        return 0;
    }

}
int check_for_stringsa(QString s1)
{
    const std::string &str = s1.toUtf8().constData();
     if(str.find_first_not_of("0123456789") == std::string::npos)
     {
        return 0;
     }
     else
     {
         return 1;
     }
}
#endif // FUNCTIONS_H
