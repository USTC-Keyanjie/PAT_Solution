/*
1004 Counting Leaves (30)（30 point(s)）Questions

A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.

Input
Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.

Output
For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input
2 1
01 1 02

Sample Output
0 1

Thought:
Firstly, I use a vector<int> to store the information of the tree.
Secondly, I use DFS algorithm to traverse this tree. In this processing, I will update the book array when I visited a node.
Lastly, all the information we need have been in our hand(the book array). Just print them.
*/
#include <iostream>
#include <vector>
using namespace std;

/*
  @tree[n + 1]: 用vector<int>存储一棵树。 The information of the tree
  @book: book[i]表示第i层有几个叶子结点 the number of leaf-nodes in i-th level
  @maxlevel: 共有多少层 the number of the tree's level
*/
vector<int> tree[100];
int book[100];
int maxlevel = 1;

void DFS(int ID, int level) {
    maxlevel = max(maxlevel, level);
    if (tree[ID].size() == 0) {
        book[level]++;
        return;
    } else {
        for (int i = 0; i < tree[ID].size(); i++) {
            DFS(tree[ID][i], level + 1);
        }
    }
}

int main() {
    /*
     @n: 总结点数 the number of all nodes
     @m: 非叶子结点数 the number of non-leaf nodes
     @parent: 父节点 the ID of parent node
     @k: 子节点数 the number of child nodes
     @child: 子节点 the ID of child node
    */
    int n, m, parent, k, child;
    scanf("%d%d", &n, &m);

    
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &parent, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            tree[parent].push_back(child);
        }
    }
    
    DFS(1, 1);
    printf("%d", book[1]);
    for (int i = 2; i <= maxlevel; i++) {
        printf(" %d", book[i]);
    }
    
    return 0;
}
