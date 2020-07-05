#include <iostream>
#include <set>
#include <string>

using namespace std;
int sex[10000];
set<int> friends[10000];
set<pair<int, int> > ans;

int main() {
    int n, m, k;
    string x, y;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        int a = abs(stoi(x)), b = abs(stoi(y));
        sex[a] = x[0] == '-' ? 0 : 1;
        sex[b] = y[0] == '-' ? 0 : 1;
        friends[a].insert(b);
        friends[b].insert(a);
    }
    scanf("%d", &k);
    while (k--) {
        ans.clear();
        cin >> x >> y;
        int a = abs(stoi(x)), b = abs(stoi(y));
        for (auto c : friends[a]) {
            if (sex[c] == sex[a] && c != b) {
                for (auto d : friends[c]) {
                    if (sex[d] == sex[b] && friends[b].count(d) && d != a) ans.insert({c, d});
                }
            }
        }
        printf("%d\n", ans.size());
        for (auto p : ans) {
            printf("%04d %04d\n", p.first, p.second);
        }
    }
    return 0;
}
