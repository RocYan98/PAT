#include <iostream>

using namespace std;
int favour[210], stripe[10010];
int dp[210][10010];

int main() {
    int n, m, l;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &favour[i]);
    }
    scanf("%d", &l);
    for (int i = 1; i <= l; ++i) {
        scanf("%d", &stripe[i]);
    }
    
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= l; ++j) {
        dp[0][j] = 0;
    }
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= l; ++j) {
            if (favour[i] == stripe[j]) dp[i][j] = dp[i][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    printf("%d", dp[m][l]);
    return 0;
}
