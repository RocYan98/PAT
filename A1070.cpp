#include <iostream>
#include <algorithm>

using namespace std;
struct MK {
    double amount, price;
} mk[1010];

bool cmp(const MK &a, const MK &b) {
    if (a.price != b.price) return a.price > b.price;
    else return a.amount > b.amount;
}

int main() {
    int n;
    double d;
    scanf("%d%lf", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &mk[i].amount);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &mk[i].price);
        mk[i].price /= mk[i].amount;
    }
    
    sort(mk, mk + n, cmp);
    double ans = 0;
    int i = 0;
    while (d && i < n) {
        if (d >= mk[i].amount) {
            ans += mk[i].amount * mk[i].price;
            d -= mk[i].amount;
        } else {
            ans += d * mk[i].price;
            d = 0;
        }
        i++;
    }
    printf("%.2lf", ans);
    return 0;
}
