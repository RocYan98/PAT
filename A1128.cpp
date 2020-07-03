#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    while (k--) {
        int n, flag = 1;
        scanf("%d", &n);
        vector<int> vec(n + 1);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &vec[i]);
            for (int j = 1; j < i; ++j) {
                if (abs(i - j) == abs(vec[i] - vec[j]) || vec[i] == vec[j]) flag = 0;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
