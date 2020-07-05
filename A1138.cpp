#include <iostream>

using namespace std;
int pre[50010], in[50010];

void find(int preL, int inL, int inR) {
    if (inL == inR || (inR - inL == 1 && in[inL] == pre[preL])) {
        printf("%d", in[inR]);
        return;
    }
    int x = inL;
    while (x <= inR && in[x] != pre[preL]) x++;
    if (x == inL) {
        find(preL + 1, inL + 1, inR);
        return;
    }
    find(preL + 1, inL, x - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }
    find(0, 0, n - 1);
    return 0;
}
