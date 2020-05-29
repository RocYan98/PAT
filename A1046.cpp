#include <iostream>
#include <algorithm>

using namespace std;
int dis[100010];

int main() {
    int n;
    scanf("%d", &n);
    
    int total = 0;
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &dis[i]);
        total += dis[i];
        dis[i] += dis[i - 1];
    }
    int temp;
    scanf("%d", &temp);
    total += temp;
    
    int m;
    scanf("%d", &m);
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", min(abs(dis[a] - dis[b]), total - abs(dis[a] - dis[b])));
    }
    return 0;
}
