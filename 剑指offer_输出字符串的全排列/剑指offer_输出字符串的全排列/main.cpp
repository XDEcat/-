//
//  main.cpp
//  输出字符串的全排列
//
//  Created by 陈泰文 on 2018/9/25.
//  Copyright © 2018年 twchen. All rights reserved.
//
//  用sort和next_permutation生成全排列(自动去重)
//  递归实现(可重)
//  Test: abc/acb/abbc

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void STL_permutation(string str) {
    sort(str.begin(), str.end());
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}

void recursive_permutation(string str, int rest_str_first_index) {
    if (rest_str_first_index == str.size() - 1) {
        cout << str << endl;
    } else {
        for (int i = rest_str_first_index; i < str.size(); i++) {
            swap(str[rest_str_first_index], str[i]);
            recursive_permutation(str, rest_str_first_index+1);
            swap(str[rest_str_first_index], str[i]);
        }
    }
}

int main() {
    string str;
    cin >> str;
    cout << "STL: " << endl;
    STL_permutation(str);
    cout << "recursive: " << endl;
    recursive_permutation(str, 0);
    return 0;
}
