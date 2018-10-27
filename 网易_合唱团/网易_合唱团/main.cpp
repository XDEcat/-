//
//  main.cpp
//  网易“合唱团”
//
//  Created by 陈泰文 on 2018/9/18.
//  Copyright © 2018年 twchen. All rights reserved.
//
//  N个学生能力值分别为ai(可正可负)，从中取k个学生，且相邻学生编号不得超过d，求能力值乘积的最大值

#include <iostream>
using namespace std;
int main()
{
    int n,k,d;
    cin>>n>>k>>d;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    long long dpmax[k+1][n+1],dpmin[k+1][n+1];
    for(int i=1;i<=n;i++)
        dpmax[1][i]=dpmin[1][i]=a[i];
    for(int kk=2;kk<=k;kk++)
        for(int i=kk;i<=n;i++)
        {
            dpmax[kk][i]=max(a[i]*dpmax[kk-1][i-1],a[i]*dpmin[kk-1][i-1]);
            dpmin[kk][i]=min(a[i]*dpmax[kk-1][i-1],a[i]*dpmin[kk-1][i-1]);
            for(int j=i-1;j>=kk-1&&j>=i-d;j--)
            {
                dpmax[kk][i]=max(dpmax[kk][i],max(a[i]*dpmax[kk-1][j],a[i]*dpmin[kk-1][j]));
                dpmin[kk][i]=min(dpmin[kk][i],min(a[i]*dpmax[kk-1][j],a[i]*dpmin[kk-1][j]));
            }
        }
    long long res=dpmax[k][k];
    for(int i=k;i<=n;i++)
        res=max(res,dpmax[k][i]);
    cout<<res;
    return 0;
}
