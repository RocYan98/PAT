#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a, b, c;

vector<int> add(const vector<int> &a, const vector<int> &b) {
    vector<int> res;
    int curry = 0;
    for (int i = 0; i < a.size(); ++i) {
        int temp = a[i] + b[i] + curry;
        res.push_back(temp % 10);
        curry = temp / 10;
    }
    if (curry) res.push_back(curry);
    return res;
}

bool is_pal(const vector<int> &x) {
    int left = 0, right = x.size() - 1;
    while (left < right) {
        if (x[left] != x[right]) return false;
        left++;
        right--;
    }
    return true;
}


int main() {
    long long n;
    int k;
    scanf("%lld%d", &n, &k);
    
    do {
        c.push_back(n % 10);
        n /= 10;
    } while(n);
    
    if (is_pal(c)) {
        for (auto x : c) {
            printf("%d", x);
        }
        printf("\n0");
        return 0;
    }
    
    for (int i = 0; i < k; ++i) {
        a = b = c;
        reverse(b.begin(), b.end());
        c = add(a, b);
        if (is_pal(c)) {
            for (auto x : c) {
                printf("%d", x);
            }
            printf("\n%d", i + 1);
            return 0;
        }
    }
    reverse(c.begin(), c.end());
    for (auto x : c) {
        printf("%d", x);
    }
    printf("\n%d", k);
    return 0;
}
