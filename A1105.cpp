#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int ans[10010][10010], init[10010];

int main() {
    int m, n, N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &init[i]);
    }
    sort(init, init + N, greater<int>());
    for (int i = 1; i <= sqrt(N); ++i) {
        if (N % i == 0) n = i;
    }
    m = N / n;

    int a = n, b = m - 1, i = 0, j = 0, index = 0, turn = 0;
    while (index < N) {
        int x = a, y = b;
        while (x--) {
            ans[i][j] = init[index++];
            if (x) {
                turn % 2 == 0 ? j++ : j--;
            } else {
                turn % 2 == 0 ? i++ : i--;
            }
        }
        while (y--) {
            ans[i][j] = init[index++];
            if (y) {
                turn % 2 == 0 ? i++ : i--;
            } else {
                turn % 2 == 0 ? j-- : j++;
            }
        }
        a--;
        b--;
        turn++;
    }
    for (int u = 0; u < m; ++u) {
        for (int v = 0; v < n; ++v) {
            if (v) printf(" ");
            printf("%d", ans[u][v]);
        }
        printf("\n");
    }
    return 0;
}
