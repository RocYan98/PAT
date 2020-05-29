#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int INF = 1000000000;
int cmax, n, sp, m;
int bikes[510], gra[510][510], vis[510], dis[510];
vector<int> pre[510];

void dijkstra() {
    fill(dis, dis + n + 1, INF);
    dis[0] = 0;
    for (int i = 0; i <= n; ++i) {
        int u = -1, min = INF;
        for (int j = 0; j <= n; ++j) {
            if (vis[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        
        if (u == -1 || u == sp) return;
        vis[u] = 1;
        
        for (int v = 0; v <= n; ++v) {
            if (vis[v] == 0 && gra[u][v] != 0) {
                if (dis[u] + gra[u][v] < dis[v]) {
                    dis[v] = dis[u] + gra[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[u] + gra[u][v] == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

vector<int> temp, ans;
int ans_sent = INF, ans_back = INF;
void DFS(int s) {
    temp.push_back(s);
    if (s == 0) {
        reverse(temp.begin(), temp.end());
        
        int sent = 0, back = 0;
        for (int i = 1; i < temp.size(); ++i) {
            if (bikes[temp[i]] >= cmax) back += bikes[temp[i]] - cmax;
            else {
                back -= cmax - bikes[temp[i]];
                if (back < 0) {
                    sent += -back;
                    back = 0;
                }
            }
        }
        if (sent < ans_sent) {
            ans_sent = sent;
            ans_back = back;
            ans = temp;
        } else if (sent == ans_sent && back < ans_back) {
            ans_sent = sent;
            ans_back = back;
            ans = temp;
        }
        
        reverse(temp.begin(), temp.end());
    }

    for (auto sta : pre[s]) {
        DFS(sta);
    } 
    temp.pop_back();
}

int main() {
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    cmax /= 2;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &bikes[i]);
    }
    
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        gra[a][b] = gra[b][a] = c;
    }
    
    dijkstra();
    DFS(sp);
    printf("%d ", ans_sent);
    for (int i = 0; i < ans.size(); ++i) {
        if (i) printf("->");
        printf("%d", ans[i]);
    }
    printf(" %d", ans_back);
    return 0;
}
