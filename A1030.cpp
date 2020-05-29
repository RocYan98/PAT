#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 510;
const int INF = 1000000000;
struct Edge {
    int dis, cost;
} gra[MAX][MAX];
int dis[MAX], vis[MAX], cost[MAX], pre[MAX];
int n, m, s, d;

void dijkstra() {
    dis[s] = 0;
    for (int i = 0; i < n; ++i) {
        int min = INF, u = -1;
        for (int j = 0; j < n; ++j) {
            if (vis[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        
        if (u == -1 || u == d) return;
        vis[u] = 1;
        
        for (int v = 0; v < n; ++v) {
            if (vis[v] == 0 && gra[u][v].dis) {
                if (dis[u] + gra[u][v].dis < dis[v]) {
                    dis[v] = dis[u] + gra[u][v].dis;
                    cost[v] = cost[u] + gra[u][v].cost;
                    pre[v] = u;
                } else if (dis[u] + gra[u][v].dis == dis[v] && cost[u] + gra[u][v].cost < cost[v]) {
                    cost[v] = cost[u] + gra[u][v].cost;
                    pre[v] = u;
                }
            }
        }
    }
}

vector<int> ans;
void DFS(int city) {
    ans.push_back(city);
    if (city == s) return;
    DFS(pre[city]);
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < m; ++i) {
        int a, b, dis, cost;
        scanf("%d%d%d%d", &a, &b, &dis, &cost);
        gra[a][b].dis = gra[b][a].dis = dis;
        gra[a][b].cost = gra[b][a].cost = cost;
    }
    
    fill(dis, dis + n, INF);
    dijkstra();
    DFS(d);
    
    reverse(ans.begin(), ans.end());
    for (auto a : ans) {
        printf("%d ", a);
    }
    printf("%d %d", dis[d], cost[d]);
    return 0;
}
