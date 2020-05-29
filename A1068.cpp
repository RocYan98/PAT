#include <iostream>
#include <algorithm>

using namespace std;
int a[10010];
int dp[10010] = {0};
int choice[10010][10010] = {0};

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i) {
        for (int v = m; v >= a[i]; --v) {
            if (dp[v] <= dp[v - a[i]] + a[i]) {
                dp[v] = dp[v - a[i]] + a[i];
                choice[i][v] = 1;
            }
        }
    }
    
    if (dp[m] != m) {
        printf("No Solution");
    } else {
        int v = m;
        for (int i = n - 1; i >= 0; --i) {
            if (choice[i][v]) {
                printf("%d", a[i]);
                v -= a[i];
                if (v) printf(" ");
            }
        }
    }
    return 0;
}
