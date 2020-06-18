#include <iostream>

#define LL long long
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    LL sum = 0;
    for (int i = 1; i <= n; i++) { 
        double temp;
        scanf("%lf", &temp);
        sum += (LL)(temp * 1000) * i * (n - i + 1);
    }
    printf("%.2f", sum / 1000.);
    return 0;
}
