//
//  main.cpp
//  小米“找异数”
//
//  Created by 陈泰文 on 2018/9/20.
//  Copyright © 2018年 twchen. All rights reserved.
//  找异数：
//  10#15 表示10进制数15
//  如果和其他数都不相等称为“异数”
//  输入一组数，以"END"结束，输出所有异数
//  如果不存在异数，输出"None"

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
int main()
{
    string str;
    vector<string> v;
    while(cin>>str)
    {
        if(str!="END")
            v.push_back(str);
        else
            break;
    }
    set<int> s;
    for(int i=0;i<v.size();i++)
        for(int j=i+1;j<v.size();j++)
        {
            string str1=v[i];
            string str2=v[j];
            int num1=0,num2=0;
            
            int pos1=str1.find('#');
            int n1=stoi(str1.substr(0,pos1));
            str1=str1.substr(pos1+1);
            int len1=str1.length();
            for(int i=0;i<len1;i++)
                num1+=pow(n1,len1-1-i)*(str1[i]-'0');
            
            int pos2=str2.find('#');
            int n2=stoi(str2.substr(0,pos2));
            str2=str2.substr(pos2+1);
            int len2=str2.length();
            for(int i=0;i<len2;i++)
                num2+=pow(n2,len2-1-i)*(str2[i]-'0');
            
            if(num1==num2)
            {
                s.insert(i);
                s.insert(j);
            }
        }
    vector<string> res;
    for(int i=0;i<v.size();i++)
    {
        if(s.find(i)==s.end())
            res.push_back(v[i]);
    }
    if(res.size()==0)
        cout<<"None"<<endl;
    else
    {
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<endl;
    }
    return 0;
}

