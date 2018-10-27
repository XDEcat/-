//
//  main.cpp
//  test
//
//  Created by 陈泰文 on 2018/9/25.
//  Copyright © 2018年 twchen. All rights reserved.
//
//  输入两行分别是二叉树的先序序列和中序序列，首先重建该二叉树，然后构造其求和二叉树，并输出其中序遍历
//  求和二叉树的每个节点值等于原二叉树对应节点的左右子树所有节点之和
//             10                  18
//           4    -2     ->      6    10
//        -2  8  6  4          0  0  0  0

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct bitnode
{
    int data;
    bitnode *left,*right;
};
bitnode* reconstruct(vector<int> pre,vector<int> in)    //通过先序和中序序列重建二叉树
{
    int len=pre.size();
    bitnode* root=new bitnode();
    root->data=pre[0];
    root->left=root->right=nullptr;
    int rootPosOfIn=0;
    while(rootPosOfIn<len && in[rootPosOfIn]!=root->data)
        rootPosOfIn++;
    vector<int> leftTreePre,rightTreePre,leftTreeIn,rightTreeIn;
    for(int i=0;i<rootPosOfIn;i++)
    {
        leftTreePre.push_back(pre[i+1]);
        leftTreeIn.push_back(in[i]);
    }
    for(int i=rootPosOfIn+1;i<len;i++)
    {
        rightTreePre.push_back(pre[i]);
        rightTreeIn.push_back(in[i]);
    }
    if(!leftTreePre.empty())
        root->left=reconstruct(leftTreePre,leftTreeIn);
    if(!rightTreePre.empty())
        root->right=reconstruct(rightTreePre,rightTreeIn);
    return root;
}
int sumOfTree(bitnode* root)    //对一颗二叉树求和
{
    int sum=0;
    if(root)
    {
        sum+=root->data;
        sum+=sumOfTree(root->left);
        sum+=sumOfTree(root->right);
    }
    return sum;
}
bitnode* constructSumTree(bitnode* root)    //构造求和二叉树
{
    bitnode* newroot=new bitnode();
    newroot->data=sumOfTree(root->left)+sumOfTree(root->right);     //新节点值等于源节点左子树求和加上右子树求和
    newroot->left=newroot->right=nullptr;
    if(root->left!=nullptr)
        newroot->left=constructSumTree(root->left);
    if(root->right!=nullptr)
        newroot->right=constructSumTree(root->right);
    return newroot;
}
void inorder(bitnode* root)     //中序遍历
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<' ';
        inorder(root->right);
    }
}
int main()
{
    vector<int> pre,in;
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    int blanks=count(str1.begin(),str1.end(),' ');
    for(int i=0;i<blanks;i++)
    {
        int pos=str1.find(' ');
        pre.push_back(stoi(str1.substr(0,pos)));
        str1=str1.substr(pos+1);
        pos=str2.find(' ');
        in.push_back(stoi(str2.substr(0,pos)));
        str2=str2.substr(pos+1);
    }
    pre.push_back(stoi(str1));
    in.push_back(stoi(str2));
    bitnode* root=reconstruct(pre,in);
    bitnode* newroot=constructSumTree(root);
    inorder(newroot);
    cout<<endl;
    return 0;
}
