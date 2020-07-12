#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;
vector<pair<int, int> > edges;

int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        edges.push_back({a, b});
    }
    scanf("%d", &k);
    while (k--) {
        set<int> color;
        vector<int> v(n);
        int flag = 1;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
            color.insert(v[i]);
        }
        for (auto edge : edges) {
            if (v[edge.first] == v[edge.second]) {
                flag = 0;
                break;
            }
        }
        flag ? printf("%d-coloring\n", color.size()) : printf("No\n");
    }
}
