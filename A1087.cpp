#include <iostream>
#include <map>
#include <vector>

using namespace std;
const int INF = 1000000000;
const int MAX = 210;
int n, k;
int happy[MAX], dis[MAX], vis[MAX], gra[MAX][MAX];
vector<int> pre[MAX];
map<string, int> s2i;
map<int, string> i2s;

void disjkstra(int start) {
    fill(dis, dis + n, INF);
    dis[start] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, min = INF;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }

        if (u == -1) return;
        vis[u] = 1;
        for (int v = 0; v < n; ++v) {
            if (!vis[v] && gra[u][v]) {
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

int count, happiness = -1, avg_happiness = -1;
vector<int> ans, temp;
void DFS(int city) {
    temp.push_back(city);
    if (city == 0) {
        count++;
        int temp_happiness = 0;
        for (auto c : temp) {
            temp_happiness += happy[c];
        }
        if (temp_happiness > happiness) {
            happiness = temp_happiness;
            ans = temp;
            avg_happiness = temp_happiness / (temp.size() - 1);
        } else if (temp_happiness == happiness && temp.size() < ans.size()) {
            happiness = temp_happiness;
            ans = temp;
            avg_happiness = temp_happiness / (temp.size() - 1);
        }
    }
    for (auto c : pre[city]) {
        DFS(c);
    }
    temp.pop_back();
}

int main() {
    scanf("%d%d", &n, &k);
    string start;
    cin >> start;
    s2i[start] = 0;
    i2s[0] = start;
    for (int i = 1; i < n; ++i) {
        string city;
        cin >> city;
        int h;
        scanf("%d", &h);
        s2i[city] = i;
        i2s[i] = city;
        happy[i] = h;
    }
    for (int i = 0; i < k; ++i) {
        string c1, c2;
        cin >> c1 >> c2;
        int d;
        scanf("%d", &d);
        gra[s2i[c1]][s2i[c2]] = gra[s2i[c2]][s2i[c1]] = d;
    }
    disjkstra(0);
    DFS(s2i["ROM"]);
    printf("%d %d %d %d\n", count, dis[s2i["ROM"]], happiness, avg_happiness);
    for (auto ite = ans.rbegin(); ite != ans.rend(); ++ite) {
        if (ite != ans.rbegin()) printf("->");
        printf("%s", i2s[*ite].c_str());
    }
    return 0;
}
