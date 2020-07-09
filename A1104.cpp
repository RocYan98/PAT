#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    long double sum = 0;
    for (int i = 1; i <= n; i++) { 
        long double temp;
        scanf("%llf", &temp);
        sum += temp * i * (n - i + 1);
    }
    printf("%.2llf", sum);
    return 0;
}
