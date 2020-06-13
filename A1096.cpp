#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> temp, ans;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= sqrt(n); ++i) {
        int m = n, j = i;
        temp.clear();
        while (m) {
            if (m % j == 0) temp.push_back(j);
            else break;
            m /= j;
            j++;
        }
        if (temp.size() > ans.size()) ans = temp;
    }
    if (ans.size() == 0) {
        printf("1\n%d", n);
        return 0;
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        if (i) printf("*");
        printf("%d", ans[i]);
    }
    return 0;
}
