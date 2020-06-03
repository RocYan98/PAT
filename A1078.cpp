#include <iostream>
#include <cmath>

using namespace std;
int hash_table[10010];

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n, m;
    scanf("%d%d", &m, &n);
    while (!is_prime(m)) m++;
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        int temp;
        scanf("%d", &temp);
        int key = temp % m;
        if (hash_table[key] == 0) {
            hash_table[key] = 1;
            printf("%d", key);
        } else {
            int step = 1;
            while (step <= m / 2 && hash_table[key]) {
                key = (temp + step * step) % m;
                step++;
            }
            if (hash_table[key]) {
                printf("-");
            } else {
                hash_table[key] = 1;
                printf("%d", key);
            }
        }
    }
    return 0;
}


