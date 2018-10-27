//
//  main.cpp
//  比较版本大小
//
//  Created by 陈泰文 on 2018/9/13.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> splitString(string str) {
    int dotnum = count(str.begin(), str.end(), '.');
    vector<string> vec(dotnum + 1);
    for (int i = 0; i < dotnum; i++) {
        int pos = str.find('.');
        vec[i] = str.substr(0,pos);
        str = str.substr(pos + 1);
    }
    vec[dotnum] = str;
    return vec;
}

int compare(vector<string> vec1, vector<string> vec2) {
    for (int i = 0; i < vec1.size(); i++) {
        if (vec1[i] < vec2[i]) {
            return -1;
        }
        if (vec1[i] > vec2[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    string str1;
    string str2;
    while (cin >> str1 >> str2) {
        vector<string> vec1 = splitString(str1);
        vector<string> vec2 = splitString(str2);
        int size1 = vec1.size();
        int size2 = vec2.size();
        int dif = size1 > size2 ? size1 - size2 : size2 -size1;
        for (int i = 0; i < dif; i++) {
            if (size1 > size2) {
                vec2.push_back("0");
            } else {
                vec1.push_back("0");
            }
        }
        cout << compare(vec1, vec2) << endl;
    }
    return 0;
}
