#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 510;
const int INF = 1000000000;
int n, m, c1, c2;
int rt[MAX], gra[MAX][MAX], dis[MAX], vis[MAX], res[MAX], ans[MAX];

void dijkstra() {
    fill(dis, dis + MAX, INF);
    dis[c1] = 0;
    res[c1] = rt[c1];
    ans[c1] = 1;
    for (int i = 0; i < n; ++i) {
        int u = -1, min = INF;
        for (int j = 0; j < n; ++j) {
            if (vis[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        
        if (u == -1 || u == c2) return;
        vis[u] = 1;
        for (int v = 0; v < n; ++v) {
            if (vis[v] == 0 && gra[u][v]) {
                if (dis[u] + gra[u][v] < dis[v]) {
                    dis[v] = dis[u] + gra[u][v];
                    res[v] = res[u] + rt[v];
                    ans[v] = ans[u];
                } else if (dis[u] + gra[u][v] == dis[v]) {
                    ans[v] += ans[u];
                    if (res[v] < res[u] + rt[v]) res[v] = res[u] + rt[v];
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &rt[i]);
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        gra[a][b] = gra[b][a] = c;
    }
    dijkstra();
    printf("%d %d", ans[c2], res[c2]);
    return 0;
}
