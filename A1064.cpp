#include <iostream>
#include <algorithm>

using namespace std;
int n;
int init[1010], nodes[1010];

int ini = 0;
void insert(int i) {
    if (i > n) return;
    insert(i * 2);
    nodes[i] = init[ini++];
    insert(i * 2 + 1); 
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &init[i]);
    }
    sort(init, init + n);
    insert(1);
    
    for (int i = 1; i <= n; ++i) {
        if (i > 1) printf(" ");
        printf("%d", nodes[i]);
    }
    return 0; 
}
