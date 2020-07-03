#include <iostream>
#include <vector>

const int INF = 1000000000;
using namespace std;
vector<int> sta[10000];
int n, k, s, d;
int inq[10000], line[10000][10000];

int compute_trans(const vector<int> &vec) {
    int temp = 0;
    for (int i = 1; i < vec.size() - 1; ++i) {
        if (line[vec[i]][vec[i - 1]] != line[vec[i]][vec[i + 1]]) temp++;
    }
    return temp;
}

vector<int> ans, temp;
int transfers;
void DFS(int rt) {
    temp.push_back(rt);
    inq[rt] = 1;
    if (rt == d) {
        if (ans.size() == 0 || temp.size() < ans.size()) {
            ans = temp;
            transfers = compute_trans(temp);
        } else if (temp.size() == ans.size()) {
            int temp_trans = compute_trans(temp);
            if (temp_trans < transfers) {
                transfers = temp_trans;
                ans = temp;
            }
        }
    }
    for (auto id : sta[rt]) {
        if (!inq[id]) DFS(id);
    }
    temp.pop_back();
    inq[rt] = 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int m, pre;
        scanf("%d%d", &m, &pre);
        m--;
        while (m--) {
            int id;
            scanf("%d", &id);
            sta[id].push_back(pre);
            sta[pre].push_back(id);
            line[pre][id] = line[id][pre] = i;
            pre = id;
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &s, &d);
        transfers = INF;
        ans.clear();
        DFS(s);
        printf("%d\n", ans.size() - 1);
        int pre = ans[0], ans_line = line[ans[0]][ans[1]];
        for (int i = 1; i < ans.size() - 1; ++i) {
            if (line[ans[i]][ans[i - 1]] != line[ans[i]][ans[i + 1]]) {
                printf("Take Line#%d from %04d to %04d.\n", ans_line, pre, ans[i]);
                pre = ans[i];
                ans_line = line[ans[i]][ans[i + 1]];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", ans_line, pre, ans.back());
    }
    return 0;
}
