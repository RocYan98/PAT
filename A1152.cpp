#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int l, k;
    scanf("%d%d", &l, &k);
    string num;
    cin >> num;
    for (int i = 0; i + k <= l; ++i) {
        int temp = stoi(num.substr(i, k));
        if (is_prime(temp)) {
            printf("%s", num.substr(i, k).c_str());
            return 0;
        }
    }
    printf("404");
    return 0;
}
