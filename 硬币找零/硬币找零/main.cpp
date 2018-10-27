//
//  main.cpp
//  硬币找零
//
//  Created by 陈泰文 on 2018/9/22.
//  Copyright © 2018年 twchen. All rights reserved.
//
//  有N种面值的硬币，面值分别为value[i]，如果需要找零money，求使用的最少硬币数，若找不开则输出"None"

#include <iostream>
using namespace std;
int main()
{
    int types,money;
    cin>>types>>money;
    int value[types];
    for(int i=0;i<types;i++)
        cin>>value[i];
    int dp[money+1];
    int MinType=value[0];
    for(int i=0;i<types;i++)
        MinType=min(MinType,value[i]);
    for(int i=1;i<MinType;i++)
        dp[i]=1000000000;
    dp[0]=0;
    for(int i=MinType;i<=money;i++)
    {
        for(int j=0;j<types;j++)
        {
            if(i>=value[j])
            {
                dp[i]=dp[i-value[j]]+1;
                break;
            }
        }
        for(int j=0;j<types;j++)
        {
            if(i>=value[j])
                dp[i]=min(dp[i],dp[i-value[j]]+1);
        }
    }
    for(int i=0;i<=money;i++)
    {
        if(dp[i]<1000000000)
            cout<<dp[i]<<endl;
        else
            cout<<"None"<<endl;
    }
    return 0;
}
