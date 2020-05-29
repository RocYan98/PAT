#include <iostream>
#include <set>

using namespace std;
set<int> s[60];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int num;
        scanf("%d", &num);
        while (num--) {
            int temp;
            scanf("%d", &temp);
            s[i].insert(temp);
        }
    }
    
    int k;
    scanf("%d", &k);
    while (k--) {
        int a, b, nc = 0, nt;
        scanf("%d%d", &a, &b);
        for (auto it : s[a]) {
            if (s[b].count(it)) nc++;
        }
        nt = s[a].size() + s[b].size() - nc;
        printf("%.1lf%%\n", nc * 1. / nt * 100);
    }
    return 0; 
}
