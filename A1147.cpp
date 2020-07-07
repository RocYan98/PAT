#include <iostream>

using namespace std;
int m, n;
int nodes[1001];

void post_order(int idx) {
    if (idx > n) return;
    post_order(idx * 2);
    post_order(idx * 2 + 1);
    printf("%d%s", nodes[idx], idx == 1 ? "\n" : " ");
}

int main() {
    scanf("%d%d", &m, &n);
    while (m--) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &nodes[i]);
        }
        int min = 1, max = 1;
        for (int i = 2; i <= n; ++i) {
            if (nodes[i] > nodes[i / 2]) max = 0;
            if (nodes[i] < nodes[i / 2]) min = 0;
        }
        printf("%s Heap\n", !max && !min ? "Not" : max ? "Max" : "Min");
        post_order(1);
    }
    return 0;
}
