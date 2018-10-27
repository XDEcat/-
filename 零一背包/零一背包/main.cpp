//
//  main.cpp
//  零一背包
//
//  Created by 陈泰文 on 2018/9/18.
//  Copyright © 2018年 twchen. All rights reserved.
//
//  有N件物品，重量和价值分别为Wi、Vi，用载重为M的背包装，可以不装满，求得到物品最大价值

#define MAX_things 101
#define MAX_bagweight 100001
#include <iostream>
using namespace std;
int dp[MAX_things][MAX_bagweight]={0};  //大数组要在函数外定义，防止栈溢
int main()
{
    int things,bagweight;
    cin>>things>>bagweight;
    int weight[things+1],value[things+1];
    for(int i=1;i<=things;i++)
        cin>>weight[i];
    for(int i=1;i<=things;i++)
        cin>>value[i];
//    int dp[MAX_things][MAX_bagweight]={0};
    for(int i=1;i<=things;i++)
        for(int j=weight[i];j<=bagweight;j++)
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
    cout<<dp[things][bagweight];
    return 0;
}
