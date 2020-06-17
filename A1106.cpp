#include <iostream>
#include <vector>

using namespace std;
struct Node {
    double price;
    vector<int> next;
} nodes[100010];
double p, r;

double lowest = 1000000000;
int count = 0;
void DFS(int root) {
    if (nodes[root].next.size() == 0) {
        if (nodes[root].price < lowest) {
            lowest = nodes[root].price;
            count = 1;
        } else if (nodes[root].price == lowest) count++;
    }
    for (auto next : nodes[root].next) {
        nodes[next].price = nodes[root].price * (1 + r / 100);
        DFS(next);
    }
}

int main() {
    int n;
    scanf("%d%lf%lf", &n, &p, &r);
    nodes[0].price = p;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        while (k--) {
            int id;
            scanf("%d", &id);
            nodes[i].next.push_back(id);
        }
    }
    DFS(0);
    printf("%.4lf %d", lowest, count);
    return 0;
}
