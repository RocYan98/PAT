#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1000000000;
int n, m, s, d;
int length[510][510], times[510][510], vis[510], dis[510], cost[510];
vector<int> pre_dis[510], pre_cost[510];

void dijkstra_dis() {
    fill(dis, dis + n, INF);
    dis[s] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, min = INF;
        for (int j = 0; j < n; ++j) {
            if (vis[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        if (u == -1 || u == d) return;
        vis[u] = 1;
        for (int v = 0; v < n; ++v) {
            if (vis[v] == 0 && length[u][v]) {
                if (dis[u] + length[u][v] < dis[v]) {
                    dis[v] = dis[u] + length[u][v];
                    pre_dis[v].clear();
                    pre_dis[v].push_back(u);
                } else if (dis[u] + length[u][v] == dis[v]) {
                    pre_dis[v].push_back(u);
                }
            }
        }
    }
}

void dijkstra_cost() {
    fill(cost, cost + n, INF);
    fill(vis, vis + n, 0);
    cost[s] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, min = INF;
        for (int j = 0; j < n; ++j) {
            if (vis[j] == 0 && cost[j] < min) {
                min = cost[j];
                u = j;
            }
        }
        if (u == -1 || u == d) return;
        vis[u] = 1;
        for (int v = 0; v < n; ++v) {
            if (vis[v] == 0 && times[u][v]) {
                if (cost[u] + times[u][v] < cost[v]) {
                    cost[v] = cost[u] + times[u][v];
                    pre_cost[v].clear();
                    pre_cost[v].push_back(u);
                } else if (cost[u] + times[u][v] == cost[v]) {
                    pre_cost[v].push_back(u);
                }
            }
        }
    }
}

vector<int> ans_len, ans_times, temp;
int fastest = INF;
void DFS_dis(int end) {
    temp.push_back(end);
    if (end == s) {
        int last = 0;
        for (int i = temp.size() - 1; i > 0; --i) {
            last += times[temp[i]][temp[i - 1]];
        }
        if (last < fastest) {
            fastest = last;
            ans_len = temp;
        }
    }
    for (auto i : pre_dis[end]) {
        DFS_dis(i);
    }
    temp.pop_back();
}

int fewest = INF;
void DFS_cost(int end) {
    temp.push_back(end);
    if (end == s) {
        if (temp.size() < fewest) {
            fewest = temp.size();
            ans_times = temp;
        }
    }
    for (auto i : pre_cost[end]) {
        DFS_cost(i);
    }
    temp.pop_back();
}

void print(const vector<int> vec) {
    for (int i = vec.size() - 1; i >= 0; --i) {
        printf(" %d", vec[i]);
        if (i) printf(" ->");
    }
    printf("\n");
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b, one_way, l, t;
        scanf("%d%d%d%d%d", &a, &b, &one_way, &l, &t);
        length[a][b] = l;
        times[a][b] = t;
        if (!one_way) {
            length[b][a] = l;
            times[b][a] = t;
        }
    }
    scanf("%d%d", &s, &d);
    dijkstra_dis();
    dijkstra_cost();
    DFS_dis(d);
    DFS_cost(d);

    if (ans_len == ans_times) {
        printf("Distance = %d; Time = %d:", dis[d], cost[d]);
        print(ans_times);
    } else {
        printf("Distance = %d:", dis[d]);
        print(ans_len);
        printf("Time = %d:", cost[d]);
        print(ans_times);
    }
    return 0;
}
