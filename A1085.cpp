#include <iostream>
#include <algorithm>

using namespace std;
int ls[100010];

int main() {
    int n, p, res = 0;
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ls[i]);
    }
    sort(ls, ls + n);
    for (int i = n - 1; i >= 0; --i) {
        int max = ls[i];
        int temp = max / p;
        int min = max % p == 0 ? temp : temp + 1;
        temp = lower_bound(ls, ls + i + 1, min) - ls;
        if (i + 1 - temp > res) res = i + 1 - temp;
    }
    printf("%d", res);
    return 0;
}
