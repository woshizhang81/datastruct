#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
//删除 头尾空格，删除全部空格
void  trimc_c( char* str)
{
    char * p = str;
    while (*p)
    {
        if (*p == ' ')
        {
            char * p1 = p;
            char * p2 = p + 1;
            //strcpy(p,p1);
            while(*p1++ = *p2++)  ;
            continue;
        }
        p++;
    }
}

void  trimc_cpp(string &str)
{
    size_t res;
    while((res = str.find(' ')) != string::npos)
    {
        str.erase(res,1);
    }
}

int main()
{
    char pbuf[] = " nihao xiexie ~~ ";
    trimc_c(pbuf);
    printf("pbuf = '%s'\n" , pbuf);
    string str = " nihao xiexie ~~ ";
    trimc_cpp(str);
    cout << '\''<<str<<'\''<<endl;
}
