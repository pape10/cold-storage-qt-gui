#ifndef FARMER_FUNCTION_H
#define FARMER_FUNCTION_H
#ifndef FUNCTION3_H
#define FUNCTION3_H
#include<fstream>
#include<string>
#include "session.h"
using namespace std;
QString search_product_namef(QString search)
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
        if(pro_name == str_)
        {
            QString res = QString::fromStdString(pro_name);
            ff.close();
            return res;

        }
    }
    ff.close();
    return "false";
}
QString search_upper_limitf(QString search)
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

        std::string pro_name,upper;
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
                upper = upper + s[j];
                }
                else
                {
                    ic=1;
                }
            }

            QString res = QString::fromStdString(upper);
            ff.close();
            return res;
        }
    }
    ff.close();
    return "false";
}
QString search_lower_limitf(QString search)
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
QString search_ind_limitf(QString search)
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
QString search_capf(QString search)
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
QString search_pricef(QString search)
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
int check_first3f(std::string s1,std::string s2)
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
int check_for_digitsf(QString s1)
{
    std::string s = s1.toUtf8().constData();
    if (std::string::npos != s.find_first_of("0123456789"))
    return 1;
    else
    {
        return 0;
    }

}
int check_for_stringsf(QString s1)
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
#endif // FUNCTION3_H

#endif // FARMER_FUNCTION_H
