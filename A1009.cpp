#include <iostream>
#include <set>

using namespace std;
double exp[1010], ans[2010];
set<int> s;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a;
        double b;
        scanf("%d%lf", &a, &b);
        exp[a] = b;
        s.insert(a);
    }
    
    scanf("%d", &n);
    while (n--) {
        int a;
        double b;
        scanf("%d%lf", &a, &b);
        for (auto i : s) {
            ans[a + i] += b * exp[i];
        }
    }
    
    int count = 0;
    for (int i = 0; i <= 2010; ++i) {
        if (ans[i]) count++;
    }
    
    printf("%d", count);
    for (int i = 2010; i >= 0; --i) {
        if(ans[i]) printf(" %d %.1lf", i, ans[i]);
    }
    return 0;
}
