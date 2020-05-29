#include <iostream>

using namespace std;
struct Node {
    char data;
    int next, flag;
} nodes[100010];

int main() {
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d ", &temp);
        scanf("%c %d", &nodes[temp].data, &nodes[temp].next);
    }
    
    int p = a;
    while (p != -1) {
        nodes[p].flag = 1;
        p = nodes[p].next;
    }
    
    p = b;
    while (p != -1) {
        if (nodes[p].flag) {
            printf("%05d", p);
            return 0;
        }
        p = nodes[p].next;
    }
    
    printf("-1");
    return 0;
}
