#include <iostream>

using namespace std;
int father[10010];

int find_father(int x) {
    int a = x;
    while (father[x] != x) x = father[x];
    while (father[a] != x) {
        int z = father[a];
        father[a] = x;
        a = z;
    }
    return x;
}

void merge(int a, int b) {
    int fa = find_father(a), fb = find_father(b);
    if (fa != fb) father[fb] = fa;
}

int main() {
    int n, max = -1;
    scanf("%d", &n);
    for (int i = 0; i <= 10000; ++i) {
        father[i] = i;
    }
    while (n--) {
        int k, first;
        scanf("%d%d", &k, &first);
        if (first > max) max = first;
        for (int i = 1; i < k; ++i) {
            int temp;
            scanf("%d", &temp);
            if (temp > max) max = temp;
            merge(first, temp);
        }
    }
    int ans = 0;
    for (int i = 1; i <= max; ++i) {
        if (father[i] == i) ans++;
    }
    printf("%d %d\n", ans, max);
    int q;
    scanf("%d", &q);
    while (q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%s\n", find_father(a) == find_father(b) ? "Yes" : "No");
    }
    return 0;
}
