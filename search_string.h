#ifndef SEARCH_STRING_H
#define SEARCH_STRING_H
#include "QString"
#include "string"
std::string search(std::string substr,std::string str)
{
    int i,j,temp;
    for(i=0;str[i]!='\0';i++)
    {
        j=0;
        if(str[i]==substr[j])
        {
            temp=i+1;
            while(str[i]==substr[j])
            {
                i++;
                j++;
            }
            if(substr[j]=='\0')
            {
                return str;
            }
            else
            {
                i=temp;
                temp=0;
            }
        }
    }
    if(temp==0)
        return "NotMatch";

}

#endif // SEARCH_STRING_H
