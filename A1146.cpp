#include <iostream>
#include <map>
#include <vector>

using namespace std;
map<int, int> in_degree, temp;
vector<int> gra[1001], ans;

int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        in_degree[b]++;
        gra[a].push_back(b);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int flag = 1, u;
        temp = in_degree;
        for (int j = 0; j < n; ++j) {
            scanf("%d", &u);
            if (temp[u]) flag = 0;
            if (flag) {
                for (auto v : gra[u]) temp[v]--;
            }
        }
        if (!flag) ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); ++i) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}
