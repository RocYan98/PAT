#include <iostream>

#define LL long long
using namespace std;
struct Rational {
    LL num, den;
} ans, temp;

LL gcd(LL a, LL b) {
    return !b ? a : gcd(b, a % b);
}

void init(Rational &rat) {
    if (rat.num == 0) {
        rat.den = 1;
        return;
    }
    if (rat.den < 0) {
        rat.den = -rat.den;
        rat.num = -rat.num;
    }
    LL tp = gcd(abs(rat.num), abs(rat.den));
    rat.num /= tp;
    rat.den /= tp;
}

int main() {
    int n;
    ans.den = 1;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld/%lld",&temp.num, &temp.den);
        init(temp);
        ans.num = ans.num * temp.den + ans.den * temp.num;
        ans.den = temp.den * ans.den;
        init(ans);
    }
    LL dec = ans.num / ans.den;
    if (dec) printf("%lld",dec);
    LL nu = ans.num % ans.den;
    if (nu) {
        if (dec) printf(" ");
        printf("%lld/%lld", nu, ans.den);
    }
    if (dec==0 && nu==0) printf("0");
    return 0;
}
