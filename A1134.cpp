#include <iostream>
#include <vector>
#include <set>

using namespace std;
struct Edge {
    int v1, v2;
};
vector<Edge> edges;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        Edge temp = {v1, v2};
        edges.push_back(temp);
    }
    int k;
    scanf("%d", &k);
    while (k--) {
        set<int> vertex;
        int num;
        scanf("%d", &num);
        while (num--) {
            int temp;
            scanf("%d", &temp);
            vertex.insert(temp);
        }
        int flag = 1;
        for (auto edge : edges) {
            if (!vertex.count(edge.v1) && !vertex.count(edge.v2)) {
                flag = 0;
                break;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}
