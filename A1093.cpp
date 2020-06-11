#include <iostream>
#include <string>

#define LL long long
using namespace std;
const int mod = 1000000007;
int p[100010], t[100010];

int main() {
    string str;
    cin >> str;
    int len = str.size();
    p[0] = str.front() == 'P' ? 1 : 0;
    t[len - 1] = str.back() == 'T' ? 1 : 0;
    for (int i = 1; i < len; ++i) {
        p[i] = str[i] == 'P' ? p[i - 1] + 1 : p[i - 1];
        t[len - i - 1] = str[len - i - 1] == 'T' ? t[len - i] + 1 : t[len - i];
    }

    LL ans = 0;
    for (int i = 0 ; i < len; ++i) {
        if (str[i] == 'A') ans += p[i] * t[i];
        ans %= mod;
    }
    printf("%d", ans);
    return 0;
}
