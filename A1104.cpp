#include<iostream>
#include <vector>

#define LL long long
using namespace std;
vector<LL> seq;

int main() {
    int n;
    LL ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        double temp;
        scanf("%lf", &temp);
        seq.push_back(temp * 1000);
    }

    ans = seq[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        seq[i] = seq[i + 1] + seq[i] * (n - i);
        ans += seq[i];
    }

    printf("%.2lf", ans / 1000.);
    return 0;
}
