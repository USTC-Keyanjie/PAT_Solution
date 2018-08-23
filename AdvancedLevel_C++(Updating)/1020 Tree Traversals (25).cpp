/*
1020 Tree Traversals (25)（25 point(s)）

Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7

Sample Output:
4 1 6 3 5 7 2

题目大意：
给出一棵二叉树的后序和中序遍历的结果，要求将此二叉树按层序遍历输出。

分析：
这里我只想到了一个比较笨的方法，就是先把按后序遍历和中序遍历的结果，构造起这个二叉树，然后再将它按层序遍历结果输出。
*/
#include <iostream>
#include <queue>
using namespace std;

int postorder[40], inorder[40];

typedef struct node{
    int data;
    struct node * lchild;
    struct node * rchild;
} node;

/* 
分割函数
因为后序遍历中，根节点很好找（就是最后一个），但是无法区分左右子树的部分
此函数可以找到后序遍历中，区分左右子树的分割点。
返回值是相较于左端点的偏移值
*/
int divide(int root_data, int in_l) {
    int div = in_l;
    while (inorder[div] != root_data) div++;
    return div - in_l;
}

/*
建立二叉树
*/
void build (node *father, int post_l, int post_r, int in_l, int in_r) {
    // 寻找分割点，offset是分割点相较于左端点的偏移值
    int offset = divide(father->data, in_l);
    //如果偏移值为0，就说明没有左子树
    if (offset == 0) {
        father->lchild = NULL;
    } else {
        node *lchild = new node();
        //  postorder[post_l + offset - 1]为左子树的父节点的数据
        lchild->data = postorder[post_l + offset - 1];
        father->lchild = lchild;
        // 对左子树进行递归
        build(lchild, post_l, post_l + offset - 1, in_l, in_l + offset - 1);
    }
    //如果偏移值为整个长度，就说明没有右子树
    if (offset == post_r - post_l) {
        father->rchild = NULL;
    } else {
        node *rchild = new node();
        rchild->data = postorder[post_r - 1];
        father->rchild = rchild;
        // 对右子树进行递归
        build(rchild, post_l + offset, post_r - 1, in_l + offset + 1, in_r);
    }
    return;
}

// BFS方法层序遍历
void level_order (node *root) {
    queue<node *> q;
    printf("%d", root->data);
    if(root->lchild) q.push(root->lchild);
    if(root->rchild) q.push(root->rchild);
    while (!q.empty()) {
        printf(" %d", q.front()->data);
        if(q.front()->lchild) q.push(q.front()->lchild);
        if(q.front()->rchild) q.push(q.front()->rchild);
        q.pop();
    }
    return;
}

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", postorder + i);
    for (int i = 0; i < n; i++) scanf("%d", inorder + i);
    node root;
    root.data = postorder[n - 1];
    build(&root, 0, n - 1, 0, n - 1);
    level_order(&root);
    return 0;
}
