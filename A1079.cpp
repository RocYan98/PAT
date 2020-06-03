#include <iostream>
#include <vector>

using namespace std;
struct Sale {
    double amount, price;
    vector<int> next;
} sales[100010];
double p, r;

double ans;
void DFS(int root) {
    if (sales[root].next.empty()) {
        ans += sales[root].price * sales[root].amount;
        return;
    }
    for (auto next : sales[root].next) {
        sales[next].price = sales[root].price * (1 + r / 100);
        DFS(next);
    }
}

int main() {
    int n;
    scanf("%d%lf%lf", &n, &p, &r);
    sales[0].price = p;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        if (k) {
            while (k--) {
                int temp;
                scanf("%d", &temp);
                sales[i].next.push_back(temp);
            }
        } else {
            scanf("%lf", &sales[i].amount);
        }
    }

    DFS(0);
    printf("%.1lf", ans);
    return 0;
}


