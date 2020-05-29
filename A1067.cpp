#include <iostream>

using namespace std;
int pos[100010];
int n;

bool is_sorted(int i) {
    for (;i < n; ++i) {
        if (pos[i] != i) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        pos[temp] = i;
    }
    
    int ans = 0;
    int i = 1;
    while (!is_sorted(i)) {
        if (pos[0] == 0) {
            while (pos[i] == i) i++;
            swap(pos[0], pos[i]);
            ans++;
        }
        while (pos[0]) {
            swap(pos[0],pos[pos[0]]);
            ans++;
        }
    }
    printf("%d", ans);
    return 0; 
}
