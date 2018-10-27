//
//  main.cpp
//  三角数塔
//
//  Created by 陈泰文 on 2018/9/16.
//  Copyright © 2018年 twchen. All rights reserved.
//
//  从塔顶出发，每次只能往下或右下移动一格，求经过数字之和最大值：
//  7
//  2 5
//  5 9 4
//  1 7 3 6
//  4 2 8 5 7

#define MAX 101
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int tower[MAX][MAX]={0};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>tower[i][j];
    int dp[MAX]={0};
    for(int j=1;j<=n;j++)
        dp[j]=tower[n][j];
    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=i;j++)
            dp[j]=tower[i][j]+max(dp[j],dp[j+1]);
    cout<<dp[1]<<endl;
    return 0;
}
