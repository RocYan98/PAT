#include <iostream>
#include <set>

using namespace std;
int times[50010];
set<int> ans[50010];

int main() {
    int n, k, max = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int id;
        scanf("%d", &id);
        if (max) {
            printf("%d:", id);
            int count = 0, idx = max;
            while (count < k && idx) {
                for (auto item : ans[idx]) {
                    if (count >= k) break;
                    printf(" %d", item);
                    count++;
                }
                idx--;
            }
            printf("\n");
        }
        times[id]++;
        if (times[id] > max) max = times[id];
        ans[times[id]].insert(id);
        if (times[id] > 1) ans[times[id] - 1].erase(id);
    }
    return 0;
}
