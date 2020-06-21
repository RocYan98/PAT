#include <iostream>
#include <algorithm>

using namespace std;
int arr[100010];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n, greater<int>());
    int ans = 0;
    while (arr[ans] > ans + 1) ans++;
    printf("%d", ans);
    return 0;
}
