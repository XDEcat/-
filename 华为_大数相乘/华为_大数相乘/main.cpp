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

int main() {
    string str1;
    string str2;
    while (cin >> str1 >> str2) {
        int neg = 0;
        if (str1[0] == '-') {
            neg++;
            str1 = str1.substr(1);
        }
        if (str2[0] == '-') {
            neg++;
            str2 = str2.substr(1);
        }
        int len1=str1.size();
        int len2=str2.size();
        vector<int> vec(len1 + len2 - 1);
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                int a = str1[i] - '0';
                int b = str2[j] - '0';
                vec[i + j] += a * b;
            }
        }
        int x = 0;  // 进位值
        for (int i = vec.size() - 1; i >= 0; i--) {
            int y = vec[i] + x;
            vec[i] = y % 10;
            x = y / 10;
        }
        if(x != 0) {
            vec.insert(vec.begin(), x);
        }
        string res;
        for (auto a : vec) {
            res = res + to_string(a);
        }
        if (neg == 1) {
            res = '-' + res;
        }
        cout << res << endl;
    }
    return 0;
}
