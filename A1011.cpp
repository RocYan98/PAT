#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double ans = 1;
    for (int i = 0; i < 3; ++i) {
        double a, b, c;
        scanf("%lf%lf%lf", &a, &b, &c);
        if (a > b && a > c) printf("W ");
        else if (b > a && b > c) printf("T ");
        else printf("L ");
        
        ans *= max(max(a, b), c);
    }   
    printf("%.2lf", (ans * 0.65 - 1) * 2);
    return 0;
}
