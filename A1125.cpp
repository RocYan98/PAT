#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> seg(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &seg[i]);
    }
    sort(seg.begin(), seg.end());
    int ans = seg[0];
    for (int i = 1; i < seg.size(); ++i) {
        ans = (ans + seg[i]) / 2;
    }
    printf("%d", ans);
    return 0;
}
