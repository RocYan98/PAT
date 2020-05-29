#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool is_prime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int to_dec(string x, int radix) {
    int res = 0;
    for (int i = 0; i < x.size(); ++i) {
        res = res * radix + x[i];
    }
    return res;
}

int reverse(int x, int radix) {
    string res;
    do {
        res.push_back(x % radix);
        x /= radix;
    } while (x);
    return to_dec(res, radix);
}

int main() {
    while (true) {
        int x, radix;
        scanf("%d", &x);
        if (x < 0) break;
        scanf("%d", &radix);
        if (is_prime(x)) {
            printf("%s\n", is_prime(reverse(x, radix)) ? "Yes" : "No");
        } else printf("No\n");
    }
    return 0;
}
