//
//  main.cpp
//  北大“放苹果”
//
//  Created by 陈泰文 on 2018/9/19.
//  Copyright © 2018年 twchen. All rights reserved.
//
//  把 M 个同样的苹果放在 N 个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？
//  注意：5、1、1 和 1、5、1 是同一种分法，即顺序无关。

#include <iostream>
using namespace std;
int dp(int m,int n)
{
    if(m==0||n==1)
        return 1;
    else if(n>m)
        return dp(m,m);
    else
        return dp(m-n,n)+dp(m,n-1);     //dp(m-n,n)意思是n个盘子都至少放一个苹果，否则先去掉一个不放苹果的盘子即dp(m,n-1)
}
int main()
{
    int m,n;
    while(cin>>m)
    {
        cin>>n;
        cout<<dp(m,n)<<endl;
    }
    return 0;
}
