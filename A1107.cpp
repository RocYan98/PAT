#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 1010;
int father[MAX], hobby[MAX], clusters[MAX];
vector<int> ans;

int find_father(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    while (a != father[a]) {
        int z = father[a];
        father[a] = x;
        a = z;
    }
    return x;
}

void merge(int a, int b) {
    int fa = find_father(a);
    int fb = find_father(b);
    if (fa != fb) {
        father[fa] = fb;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
        int k;
        scanf("%d:", &k);
        while (k--) {
            int idx;
            scanf("%d", &idx);
            if (hobby[idx] == 0) hobby[idx] = i;
            else merge(i, hobby[idx]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        clusters[find_father(i)]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (clusters[i]) ans.push_back(clusters[i]);
    }
    sort(ans.rbegin(), ans.rend());
    printf("%d\n", ans.size());
    for (auto ite = ans.begin(); ite != ans.end(); ++ite) {
        if (ite != ans.begin()) printf(" ");
        printf("%d", *ite);
    }
    return 0;
}
