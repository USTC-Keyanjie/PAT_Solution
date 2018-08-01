/*
1013 Battle Over Cities (25)（25 point(s)）

It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city~1~-city~2~ and city~1~-city~3~. Then if city~1~ is occupied by the enemy, we must have 1 highway repaired, that is the highway city~2~-city~3~.

Input
Each input file contains one test case. Each case starts with a line containing 3 numbers N (&lt1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

Output
For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

Sample Input
3 2 3
1 2
1 3
1 2 3

Sample Output
1
0
0

题目大意：现在有很多城市，城市与城市之间有道路。如果打仗了，有个城市被敌军占了，那么这个城市我们肯定不能经过。求需要加几条路，才能让剩下的城市保持连通。

分析：要让剩下的连通分量加上边连通起来，而题目没有规定边要加在哪个点上，能连通就可以了，这样连通分量就可以弱化为点的模型。
这就等同于问一个简单的问题：一个无向图有n个节点，至少需要多少条边才能使得这个无向图保持连通。
答案是n-1。
所以我们只要找到去除这个点后，还有多少连通分量，那么用连通分量数减一就是答案。

思路：
1、输入n、m、k，再用二维数组e存储边的信息，将边的信息录入，另外创建visit数组做标记数组；
2、这里使用need_repair函数来求的需要修剪的路数，每传入一个丢失的城市，就要初始化一下visit数组；
3、由于丢失的城市是一定不能访问的，所以首先把丢失的城市访问标记置为true，再使用dfs算法来求的有几个连通分量，count变量用以记数；
4、count-1即为所求。
*/
#include <iostream>
using namespace std;

int n, m, k;
int e[1000][1000];
bool visit[1000];

void dfs (int city) {
	visit[city] = true;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false && e[city][i] == 1) 
			dfs(i);
	}
	return;
}

int need_repair (int lost_city) {
	fill(visit, visit + 1000, false);
	
	visit[lost_city] = true;
	int count = 0;
	
	for (int p = 1; p <= n; p++) {
		if (visit[p] == false) {
			dfs(p);
			count++;
		}
	}
	
	return count - 1;
}

int main () {

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int city_begin, city_end;
		scanf("%d%d", &city_begin, &city_end);
		e[city_begin][city_end] = 1;
		e[city_end][city_begin] = 1;
	}
	
	for (int i = 1; i <= k; i++) {
		int temp;
		scanf("%d", &temp);
		printf("%d\n", need_repair(temp));
	}
	
	return 0;
}