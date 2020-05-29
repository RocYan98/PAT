#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAX = 1020;
const int INF = 1000000000;
int n, m, k, ds;
int gra[MAX][MAX], dis[MAX], vis[MAX];

int get_num(const string &str) {
	if (str[0] == 'G') {
		int temp;
		sscanf(str.c_str(), "G%d", &temp);
		return n + temp;
	} else return stoi(str);
}

void dijkstra(int s) {
	fill(dis, dis + n + m + 1, INF);
	fill(vis, vis + n + m + 1, 0);
	dis[s] = 0;
	for (int i = 0; i < n + m; ++i) {
		int u = -1, min = INF;
		for (int j = 1; j <= n + m; ++j) {
			if (dis[j] < min && !vis[j]) {
				u = j;
				min = dis[j];
			}
		}
		
		if (u == -1) return;
		vis[u] = 1;
		
		for (int v = 1; v <= n + m; ++v) {
			if (gra[u][v] && !vis[v]) {
				if (dis[u] + gra[u][v] < dis[v]) {
					dis[v] = dis[u] + gra[u][v];
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	for (int i = 0; i < k; ++i) {
		string sa, sb;
		int dis;
		cin >> sa >> sb >> dis;
		int a = get_num(sa);
		int b = get_num(sb);
		gra[a][b] = gra[b][a] = dis;
	}
	
	int sum_dis = INF, ans_gas, min_dis = 0;
	for (int i = 1; i <= m; ++i) {
		dijkstra(i + n);
		int sum = 0;
		int min = INF;
		for (int j = 1; j <= n; ++j) {
			if (dis[j] > ds) {
				sum = 0;
				break;
			}
			if (dis[j] < min) min = dis[j];
			sum += dis[j];
		}
		if (sum) {
			if (min > min_dis) {
				sum_dis = sum;
				min_dis = min;
				ans_gas = i;
			} else if (min == min_dis && sum < sum_dis) {
				sum_dis = sum;
				min_dis = min;
				ans_gas = i;
			}
		}
	}
	if (sum_dis != INF) printf("G%d\n%d.0 %.1lf", ans_gas, min_dis, round((sum_dis * 1. / n) * 10) / 10);
	else printf("No Solution");
	return 0;
}
