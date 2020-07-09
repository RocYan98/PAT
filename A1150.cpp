#include <iostream>
#include <vector>
#include <set>

using namespace std;
int gra[210][210];

int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b, dis;
        scanf("%d%d%d", &a, &b, &dis);
        gra[a][b] = gra[b][a] = dis;
    }
    int shortest = 1000000000, id = 0;
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
        int num, total_dis = 0;
        scanf("%d", &num);
        vector<int> route(num);
        set<int> vis;
        scanf("%d", &route[0]);
        for (int j = 1; j < num; ++j) {
            scanf("%d", &route[j]);
            if (total_dis != -1){
                gra[route[j - 1]][route[j]] ? total_dis += gra[route[j - 1]][route[j]] : total_dis = -1;
                vis.insert(route[j]);
            }
        }
        printf("Path %d: ", i);
        total_dis == -1 ? printf("NA ") : printf("%d ", total_dis);
        if (vis.size() == n && route.front() == route.back()) {
            printf("(TS%scycle)\n", route.size() == n + 1 ? " simple " : " ");
            if (total_dis < shortest) {
                shortest = total_dis;
                id = i;
            }
        } else printf("(Not a TS cycle)\n");
    }
    printf("Shortest Dist(%d) = %d", id, shortest);
    return 0;
}
