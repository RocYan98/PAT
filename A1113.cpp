#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> seq;

int main() {
    int n;
    scanf("%d", &n);
    seq.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &seq[i]);
    }
    sort(seq.begin(), seq.end());
    printf("%d ", n % 2 == 0 ? 0 : 1);
    int ans = 0;
    for (int i = 0; i < n / 2; ++i) {
        ans += seq[n - 1 - i] - seq[i];
    }
    printf("%d", n % 2 == 0 ? ans : ans + abs(seq[n / 2]));
    return 0;
}
