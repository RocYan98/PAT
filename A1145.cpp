#include <iostream>
#include <cmath>
#include <map>

using namespace std;
map<int, int> hash_table;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int size, n, m, temp;
    scanf("%d%d%d", &size, &n, &m);
    while (!is_prime(size)) size++;
    while (n--) {
        scanf("%d", &temp);
        for (int i = 0; i < size; ++i) {
            int key = temp + i * i;
            if (!hash_table[key % size]) {
                hash_table[key % size] = temp;
                break;
            } else if (i + 1 == size) printf("%d cannot be inserted.\n", temp);
        }
    }
    int times = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &temp);
        int j = 0;
        for (; j < size; ++j) {
            int key = temp + j * j;
            if (hash_table[key % size] == temp || !hash_table[key % size]) break;
        }
        times += j + 1;
    }
    printf("%.1lf", times * 1. / m);
    return 0;
}
