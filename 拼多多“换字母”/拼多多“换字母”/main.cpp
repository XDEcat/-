//
//  main.cpp
//  debug
//
//  Created by 陈泰文 on 2018/9/27.
//  Copyright © 2018年 twchen. All rights reserved.
//
//  已知一个由小写英文字母a-z组成的字符串，分别统计其中各个英文字母出现的次数，该字符串s的价值分为所有字母出现次数的平方和。 现在你可以将其中的一个
//  字母 全部 换成另一个任意的字母，修改后字符串的最大价值为多少？

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> getCountsArray(string str) {
    map<char, int> m;
    for (int i = 0; i < str.size(); i++) {
        m[str[i]]++;
    }
    vector<int> v;
    for (auto it = m.begin(); it != m.end(); it++) {
        v.push_back(it -> second);
    }
    return v;
}

int main() {
    string str;
    while (cin >> str) {
        vector<int> v = getCountsArray(str);
        int max1Index = 0;
        int max2Index = v.size() - 1;
        for (int i = 0; i < v.size(); i++) {
            max1Index = v[i] > v[max1Index] ? i : max1Index;
        }
        for (int i = 0; i < max1Index; i++) {
            max2Index = v[i] > v[max2Index] ? i : max2Index;
        }
        for (int i = max1Index + 1; i < v.size(); i++) {
            max2Index = v[i] > v[max2Index] ? i : max2Index;
        }
        int temp = v[max2Index];
        v[max1Index] += temp;
        v[max2Index] -= temp;
        int res = 0;
        for (int i = 0; i < v.size(); i++) {
            res += v[i] * v[i];
        }
        cout << res << endl;
    }
    return 0;
}

