#include <stack>
#include <iostream>
//#include <conio.h>
//#include <stdio.h>

using namespace std;

typedef struct node {
    char val;
    struct node *lchild;
    struct node *rchild;
}BiTree;

BiTree *creat(BiTree *root);
void PreOrder(BiTree *root);
void InOrder(BiTree *root);
void PostOrder(BiTree *root);
void pre_tree(BiTree *root);
void in_order(BiTree *root);
void post_order(BiTree *root);

int main() {
    BiTree *root = NULL;
    int i = -1;
    cout << "please enter a tree :";
    root = creat(root);
    while(1){
        cout << "二叉树创建成功" << endl;
        cout << "请选择进行的操作" << endl;
        cout << "0.二叉树先序递归遍历" << endl;
        cout << "1.二叉树中序递归遍历" << endl;
        cout << "2.二叉树后序递归遍历" << endl;
        cout << "3.二叉树先序遍历" << endl;
        cout << "4.二叉树中序遍历" << endl;
        cout << "5.二叉树后序遍历" << endl;
        cin >> i;
        switch(i) {
            case 0 :
                PreOrder(root);
                cout << endl;
                break;
            case 1 :
                InOrder(root);
                cout << endl;
                break;
            case 2 :
                PostOrder(root);
                cout << endl;
                break;
            case 3 :
                pre_tree(root);
                cout << endl;
                break;
            case 4 :
                in_order(root);
                cout << endl;
                break;
            case 5 :
                post_order(root);
                cout << endl;
                break;
            default:
                cout << "无效选项" << endl;
                break;
        }
        cout << "是否继续" << endl;
        int j = -1;
        cin >> j;
        if(j == 1)
            break;
    }
    return 0;
}

BiTree *creat(BiTree *root) {
    char ch;
    //BiTree *root = NULL;
    cin >> ch;
    if(ch != '#') { 
        root = (BiTree *)malloc(sizeof(BiTree));
        root->val = ch;
        root->lchild = NULL;
        root->rchild = NULL;
        root->lchild = creat(root->lchild);
        root->rchild = creat(root->rchild);
    }
    return root;
}

void PreOrder(BiTree *root) {
    if(root) {
        cout << root->val;
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
    return;
}

void InOrder(BiTree *root) {
    if(root) {
        InOrder(root->lchild);
        cout << root->val;
        InOrder(root->rchild);
    }
    return;
}

void PostOrder(BiTree *root) {
    if(root) {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        cout << root->val;
    }
    return;
}

void pre_tree(BiTree *root) {
    stack<BiTree *> s;
    BiTree *p = root;

    while(!s.empty() || p != NULL) {
        while(p != NULL) {
            cout << p->val;
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty()) {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
    return;
}

void in_order(BiTree *root) {
    stack<BiTree *> s;
    BiTree *p = root;
    while(p != NULL || !s.empty()) {
        while(p != NULL) {
            s.push(p);
            p = p->lchild;
        }
        if(!s.empty()) {
            p = s.top();
            cout << p->val;
            s.pop();
            p = p->rchild;
        }
    }
}

void post_order(BiTree *root) {
    stack<BiTree *> s;
    BiTree *cur;
    BiTree *pre = NULL;
    s.push(root);
    while(!s.empty()) {
        cur = s.top();
        if((cur->lchild == NULL && cur->rchild == NULL) || (pre != NULL && (pre == cur->lchild || pre == cur->rchild))) {
            cout << cur->val;
            s.pop();
            pre = cur;
        }
        else {
            if(cur->rchild != NULL) {
                s.push(cur->rchild);
            }
            if(cur->lchild != NULL) {
                s.push(cur->lchild);
            }
        }
    }
}
