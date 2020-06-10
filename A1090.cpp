#include <iostream>
#include <vector>
#include <queue>

using namespace std;
double p, r;
vector<int> sup[100010];
double price[100010];

double max_price = -1;
int count = 0;
void BFS(int root) {
    queue<int> q;
    q.push(root);
    while (q.size()) {
        int top = q.front();
        q.pop();
        if (price[top] > max_price) {
            count = 1;
            max_price = price[top];
        } else if (price[top] == max_price) {
            count++;
        }
        for (auto i : sup[top]) {
            price[i] = price[top] * (1 + r / 100);
            q.push(i);
        }
    }
}

int main() {
    int n, root;
    scanf("%d%lf%lf", &n, &p, &r);
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        if (temp == -1) {
            root = i;
            continue;
        }
        sup[temp].push_back(i);
    }
    price[root] = p;
    BFS(root);
    printf("%.2lf %d", max_price, count);
    return 0;
}
