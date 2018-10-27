//
//  main.cpp
//  大数相乘
//
//  Created by 陈泰文 on 2018/9/12.
//  Copyright © 2018年 twchen. All rights reserved.
//
//  大数加减乘除要用字符串操作，否则会整型溢出

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int count=0;
    if(str1[0]=='-')
    {
        count++;
        str1=str1.substr(1);
    }
    if(str2[0]=='-')
    {
        count++;
        str2=str2.substr(1);
    }
    int len1=str1.length();
    int len2=str2.length();
    vector<int> v(len1+len2-1);     //如果不给初始大小，v.size()=0，将找不到v[i+j]的内存地址
    for(int i=0;i<len1;i++)
        for(int j=0;j<len2;j++)
        {
            int a=str1[i]-'0';
            int b=str2[j]-'0';
            v[i+j]+=a*b;
        }
    int x=0;
    for(int i=v.size()-1;i>=0;i--)
    {
        int y=v[i]+x;
        v[i]=y%10;
        x=y/10;
    }
    if(x!=0)
    {
        v.insert(v.begin(),x);
    }
    string out;
    for(auto a:v)
        out=out+to_string(a);
    if(count==1)
        out='-'+out;
    cout<<out;
    return 0;
}

