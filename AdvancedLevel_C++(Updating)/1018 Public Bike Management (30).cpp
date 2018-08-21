/*
1018 Public Bike Management (30)（30 point(s)）

There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.

\ Figure 1

Figure 1 illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S~3~, we have 2 different shortest paths:

1. PBMC -> S~1~ -> S~3~. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S~1~ and then take 5 bikes to S~3~, so that both stations will be in perfect conditions.

2. PBMC -> S~2~ -> S~3~. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 numbers: C~max~ (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), the total number of stations; S~p~, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers C~i~ (i=1,...N) where each C~i~ is the current number of bikes at S~i~ respectively. Then M lines follow, each contains 3 numbers: S~i~, S~j~, and T~ij~ which describe the time T~ij~ taken to move betwen stations S~i~ and S~j~. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in the format: 0-&gtS~1~->...-&gtS~p~. Finally after another space, output the number of bikes that we must take back to PBMC after the condition of S~p~ is adjusted to perfect.

Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data guarantee that such a path is unique.

Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

Sample Output:
3 0->2->3 0

我觉得这题挺难的，首先这题需要用Dijkstra算法求出多条最短路径，然后再使用DFS搜索算法求出所要求的路径，并输出。
如果要把两个过程混杂在一起进行处理难度太大，也不利于debug，所以最好分开进行。
代码没写出来，我这题的解答基本是按照柳婼女神的答案造的轮子，我也就来补充补充注释吧。
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 c_max：每个站点最多存储自行车量
 n：站点数
 sp：出问题的站点号
 minneed：最少所需送出自行车量
 minback：最少所需返回自行车量
 e：道路信息
 dis：距离信息
 weight：每个站点的自行车量信息
 visit：访问标记
 pre：路径集合，pre[i]表示i节点在最短路线上的的前驱节点，有多个就依次存储
 path：最终路径
 temppath：临时选中路径
*/
int c_max, n, sp, m, minneed = INT_MAX, minback = INT_MAX;
int e[510][510], dis[510], weight[510];
bool visit[510];
vector<int> pre[510];
vector<int> path, temppath;

/*
这里的dfs搜索算法从末尾开始，一路搜索到0节点（PBMC）的路径。
如果到达0节点，那么这条路径已经保存完毕。
此时，从0节点出发，一路维护need和back两个变量。
如果遇到一个站的自行车比半数多，那么加入到back里。
如果遇到一个站的自行车比半数少，那么先看看back够不够补充，够补充就将back相应减少，不够的话，back置0，send补充剩余的。
*/
void dfs(int v) {
    temppath.push_back(v);
    if (v == 0) {
        int need = 0, back = 0;
        for (int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            if (weight[id] > 0) {
                back += weight[id];
            } else {
                if (back > (0 - weight[id])) {
                    back += weight[id];
                } else {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }
        
        if (need < minneed) {
            minneed = need;
            minback = back;
            path = temppath;
        } else if (need == minneed && back < minback) {
            minback = back;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    temppath.pop_back();
}

int main () {
    fill(e[0], e[0] + 510 * 510, INT_MAX);
    fill(dis, dis + 510, INT_MAX);
    scanf("%d%d%d%d", &c_max, &n, &sp, &m);
    
    // 这里将每个站点自行车量按与最大存储量的一半之差来存储
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] -= (c_max / 2);
    }

    for (int i = 0; i < m; i++) {
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);
        e[a][b] = e[b][a] = l;
    }

    // 从这里开始是Dijkstra算法求最短路径
    dis[0] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, minn = INT_MAX;
        for (int j = 0; j <= n; j++) {
            if (!visit[j] && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1) break;
        visit[u] = true;
        for (int v = 0; v <= n; v++) {
            // 如果有更短的路径出现，那么清空此节点的pre信息，重新装入
            if (!visit[v] && e[u][v] != INT_MAX) {
                if (dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                    // 如果有相同长度的路径出现，那么直接装入
                } else if (dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(sp);
    printf("%d 0", minneed);
    for (int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minback);
    return 0;
}
