//
//  main.cpp
//  判断二叉树是否为二叉搜索树
//
//  Created by 陈泰文 on 2018/10/10.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>
using namespace std;
struct bitnode
{
    int data;
    bitnode* left;
    bitnode* right;
};
bitnode* construct()
{
    bitnode* root=nullptr;
    int i;
    while(cin>>i)
    {
        root=new bitnode();
        root->data=i;
        root->left=construct();
        root->right=construct();
    }
    return root;
}
bool is_larger(int i,bitnode* root)
{
    if(root)
    {
        int j=root->data;
        if(i>=j && is_larger(i,root->left) && is_larger(i,root->right))
            return true;
        else
            return false;
    }
    else
        return true;
}
bool is_smaller(int i,bitnode* root)
{
    if(root)
    {
        int k=root->data;
        if(i<=k && is_smaller(i,root->left) && is_smaller(i,root->right))
            return true;
        else
            return false;
    }
    else
        return true;
}
bool is_BST(bitnode* root)
{
    if(root)
    {
        int i=root->data;
        if(is_larger(i,root->left) && is_smaller(i,root->right) && is_BST(root->left) && is_BST(root->right))
            return true;
        else
            return false;
    }
    else
        return true;
}
int main()
{
    bitnode* root=construct();
    if(is_BST(root))
        cout<<"is BST"<<endl;
    else
        cout<<"is not BST"<<endl;
    return 0;
}
