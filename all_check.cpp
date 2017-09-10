#include "all_check.h"
#include "QString"
#include "session.h"
#include "fstream"
using namespace std;
all_check::all_check()
{

}
int all_check::check_first(std::string filename,std::string check)
{
    ifstream ff;
    ff.open(filename);
    std::string s;
    while(! ff.eof())
    {
        getline(ff,s);

        std::string pro_name;
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
        if(pro_name == check)
        {
            ff.close();
            return 1;

        }
    }
    ff.close();
    return 0;
}
int all_check::check_second(std::string filename,std::string check)
{
    ifstream ff;
    ff.open(filename);
    std::string s;
    while(! ff.eof())
    {
        getline(ff,s);

        std::string upper;
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
            }
            else
            {
                ic=1;
            }
        }
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
            if(upper == check)
            ff.close();
            return 1;
    }
    ff.close();
    return 0;
}
int all_check::check_third(std::string filename,std::string check)
{
    ifstream ff;
    ff.open(filename);
    std::string s;
    while(! ff.eof())
    {
        getline(ff,s);
        std::string lower;
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
            }
            else
            {
                ic=1;
            }
        }
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
            if(lower == check)
            {
                return 1;
            ff.close();
        }
    }
    ff.close();
    return 0;
}
