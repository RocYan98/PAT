#include <iostream>
#include <set>

using namespace std;
int gra[210][210];

int main() {
    int nv, ne;
    scanf("%d%d", &nv, &ne);
    for (int i = 0; i < ne; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        gra[a][b] = gra[b][a] = 1;
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        int k, flag = 0, temp;
        scanf("%d", &k);
        set<int> subset;
        for (int i = 0; i < k; ++i) {
            scanf("%d", &temp);
            subset.insert(temp);
        }
        for (auto a : subset) {
            for (auto b : subset) {
                if (a != b && !gra[a][b]) flag = 1;
            }
        }
        if (flag) printf("Not a Clique\n");
        else {
            for (int i = 1; i <= nv; ++i) {
                if (!subset.count(i)) {
                    int num = 0;
                    for (auto j : subset) {
                        if (gra[i][j]) num++;
                    }
                    if (num == subset.size()) flag = 1;
                }
            }
            printf("%s\n", flag ? "Not Maximal" : "Yes");
        }
    }
    return 0;
}
