#include <iostream>
#include <set>

using namespace std;
int records[101];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &records[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            set<int> liars;
            for (int k = 1; k <= n; ++k) {
                if (records[k] < 0) {
                    if (records[k] != -i && records[k] != -j) liars.insert(k);
                } else if (records[k] == i || records[k] == j) liars.insert(k);
            }
            if (liars.size() == 2) {
                if ((liars.count(i) && !liars.count(j)) || (liars.count(j) && !liars.count(i))) {
                    printf("%d %d", i, j);
                    return 0;
                }
            }
        }
    }
    printf("No Solution");
    return 0;
}
