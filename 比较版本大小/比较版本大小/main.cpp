//
//  main.cpp
//  比较版本大小
//
//  Created by 陈泰文 on 2018/9/13.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int dot1=count(str1.begin(),str1.end(),'.');
    int dot2=count(str2.begin(),str2.end(),'.');
    int dot=max(dot1,dot2);
    string a[dot+1];
    string b[dot+1];
    for(int i=0;i<dot+1;i++)
    {
        a[i]="0";
        b[i]="0";
    }
    for(int i=0;i<dot1;i++)
    {
        int pos=str1.find('.');
        a[i]=str1.substr(0,pos);
        str1=str1.substr(pos+1);
    }
    a[dot1]=str1;
    for(int i=0;i<dot2;i++)
    {
        int pos=str2.find('.');
        b[i]=str2.substr(0,pos);
        str2=str2.substr(pos+1);
    }
    b[dot2]=str2;
    int count=0;
    for(int i=0;i<dot+1;i++)
    {
        if(a[i]<b[i])
        {
            cout<<-1;
            count=1;
            break;
        }
        if(a[i]>b[i])
        {
            cout<<1;
            count=1;
            break;
        }
    }
    if(count==0)
        cout<<0;
    return 0;
}
