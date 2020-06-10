#include <iostream>

#define LL long long
using namespace std;
struct Rational {
    LL num, den;
} a, b, c;

LL gcd(LL x, LL y) {
    return y ? gcd(y, x % y) : x;
}

LL lcd(LL x, LL y) {
    return x * y / gcd(x, y);
}

void init(Rational &rat) {
    if (rat.den < 0) {
        rat.den = -rat.den;
        rat.num = -rat.num;
    }
    if (rat.num == 0) {
        rat.den = 1;
    } else {
        LL cd = gcd(abs(rat.num), abs(rat.den));
        rat.num /= cd;
        rat.den /= cd;
    }
}

void add() {
    c.den = lcd(a.den, b.den);
    c.num = a.num * (c.den / a.den) + b.num * (c.den / b.den);
    init(c);
}

void sub() {
    c.den = lcd(a.den, b.den);
    c.num = a.num * (c.den / a.den) - b.num * (c.den / b.den);
    init(c);
}

void mul() {
    c.den = a.den * b.den;
    c.num = a.num * b.num;
    init(c);
}

void div() {
    c.den = a.den * b.num;
    c.num = a.num * b.den;
    if (c.den) init(c);
}

void print(const Rational &rat) {
    LL num = abs(rat.num);
    LL den = abs(rat.den);
    if (rat.num < 0) printf("(-");
    if (num >= den) printf("%lld", num / den);
    if (num >= den && num % den) printf(" ");
    if (num % den) printf("%lld/%lld", num % den, den);
    if (rat.num < 0) printf(")");
    if (num == 0) printf("0");
}

void print(char ch) {
    print(a);
    printf(" %c ", ch);
    print(b);
    printf(" = ");
    if (c.den) print(c);
    else printf("Inf");
    printf("\n");
}

int main() {
    scanf("%lld/%lld %lld/%lld", &a.num, &a.den, &b.num, &b.den);
    init(a);
    init(b);

    add();
    print('+');

    sub();
    print('-');

    mul();
    print('*');

    div();
    print('/');
    return 0;
}
