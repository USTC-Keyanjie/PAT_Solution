/*
1021 Deepest Root（25 point(s)）

A graph which is connected and acyclic can be considered a tree. The hight of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (≤10
​4
​​ ) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N−1 lines follow, each describes an edge by given the two adjacent nodes' numbers.

Output Specification:

For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print Error: K components where K is the number of connected components in the graph.

分析：
我先看看有多少连通分量，再算深度最大的根结点
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, height;
vector<vector<int> > e;
vector<bool> visit;

void dfs(int node){
    visit[node] = true;
    for (int i = 0; i < e[node].size(); i++) {
        if (!visit[e[node][i]]) {
            dfs(e[node][i]);
        }
    }
}

void get_height(int node, int h) {
    visit[node] = true;
    if (h > height)
        height = h;
    
    for (int i = 0; i < e[node].size(); i++) {
        if (!visit[e[node][i]]) {
            get_height(e[node][i], h + 1);
        }
    }
}

int main () {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    visit.resize(n + 1);
    e.resize(n + 1);
    int a, b;
    for(int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    
    // 求连通分量数
    fill(visit.begin(), visit.end(), false);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visit[i]){
            count++;
            dfs(i);
        }
    }
    if (count > 1) {
        printf("Error: %d components\n", count);
        return 0;
    }

    vector<int> result;
    // 所有节点作为根时的最大深度
    int max_height = 0;
    for (int i = 1; i <= n; i++) {
        // 当前节点作为根时的最大深度
        height = 0;
        fill(visit.begin(), visit.end(), false);
        get_height(i, 0);

        if (max_height < height) {
            max_height = height;
            result.clear();
            result.push_back(i);
        } else if (max_height == height) {
            result.push_back(i);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        printf("%d\n", result[i]);
    }
    
    return 0;
}
