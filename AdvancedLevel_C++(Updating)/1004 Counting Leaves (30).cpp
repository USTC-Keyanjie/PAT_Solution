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
Secondly, I use BFS algorithm to traverse this tree layer by layer. In this processing, I use the level array to record the i-th node in which level and the book array to record the number of leaf-nodes in i-th level.
Lastly, all the information we need have been in our hand(the book array). Just print them.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    /*
     @n: 总结点数 the number of all nodes
     @m: 非叶子结点数 the number of non-leaf nodes
     @parent: 父节点 the ID of parent node
     @k: 子节点数 the number of child nodes
     @child: 子节点 the ID of child node
     @tree[n + 1]: 用vector<int>存储一棵树。 The information of the tree
     */
    int n, m, parent, k, child;
    scanf("%d %d", &n, &m);
    vector<int> tree[n + 1];
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d ", &parent, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            tree[parent].push_back(child);
        }
    }
    
    /*
     @q: 广度优先搜索的缓冲队列 buffer queue for BFS
     @p: 广度优先搜索遍历指针 BFS traversal pointer
     @maxlevel: 共有多少层 the number of the tree's level
     @level: level[i]表示第i个节点位于第几层 which level the i-th node at
     @book: book[i]表示第i层有几个叶子结点 the number of leaf-nodes in i-th level
     */
    queue<int> q;
    q.push(1);
    int p, maxlevel = 1;
    int level[100] = {0}, book[100] = {0};
    level[1] = 1;
    
    while (!q.empty()) {
        p = q.front();
        q.pop();
        
        maxlevel = max(level[p], maxlevel);
        
        if (tree[p].size() == 0){
            book[level[p]]++;
        } else {
            for (int i = 0; i < tree[p].size(); i++) {
                q.push(tree[p][i]);
                level[tree[p][i]] = level[p] + 1;
            }
        }
    }
    
    printf("%d", book[1]);
    for (int i = 2; i <= maxlevel; i++) {
        printf(" %d", book[i]);
    }
        
    return 0;
}
