/*
1003 Emergency (25)（25 point(s)）

As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input
Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output
For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.\ All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

Sample Output
2 4

Thought: I use Dijkstra algorithm to get the information including the distance of shortest paths between the city we start at and any city. We can get any information in the searching process.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /*
     @n: 城市数 the number of cities
     @m: 路径数 the number of the way from C1 to C2
     @C1: 出发城市 the city we start at
     @C2: 目的城市 the city we come to
     @e[510][510]: 路径信息 the information of road between each city
     @teams[510]: 第i个城市驻有救援队数 the number of rescue teams in the i-th city
     @dis[510]: 从出发点到第i个城市的最短路径长 the length of shortest paths between C1 and i-th city
     @all_teams[510]: 从出发点到第i个城市走最短路径最多有多少救援队 the maximum amount of rescue teams you can possibly gather between C1 to C2
     @path_num[510]: 从出发点到第i个城市有多少种最短路径 the number of different shortest paths between C1 and i-th city
     @visit[510]: 记录此城市是否被访问过 record whether you have visited the city
     */
    int n, m, C1, C2;
    int e[510][510], teams[510], dis[510], all_teams[510], path_num[510];
    bool visit[510];
    const int max_num = 99999999;
    cin >> n >> m >> C1 >> C2;
    
    fill(e[0], e[0] + 510 * 510, max_num);
    for (int i = 0; i < n; i++) cin >> teams[i];
    fill(dis, dis + 510, max_num);
    fill(all_teams, all_teams + 510, 0);
    fill(path_num, path_num + 510, 0);
    fill(visit, visit + 510, false);
    
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        e[a][b] = e[b][a] = c;
    }
    
    dis[C1] = 0;
    
    all_teams[C1] = teams[C1];
    path_num[C1] = 1;
    
    int min_len, u;
    
    for (int k = 0; k < n; k++) {
        u = -1;
        min_len = max_num;
        for (int i = 0; i < n; i++) {
            if (visit[i] == false && dis[i] < min_len) {
                min_len = dis[i];
                u = i;
            }
        }
        if (u == -1) break;
        visit[u] = true;
        for (int v = 0; v < n; v++) {
            if (visit[v] == false && e[u][v] != max_num) {
                if (dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    all_teams[v] = all_teams[u] + teams[v];
                    path_num[v] = path_num[u];
                } else if (dis[u] + e[u][v] == dis[v]) {
                    path_num[v] = path_num[u] + path_num[v];
                    if (all_teams[v] < all_teams[u] + teams[v])
                        all_teams[v] = all_teams[u] + teams[v];
                }
            }
        }
    }
    
    cout << path_num[C2] << ' ' << all_teams[C2];
}
