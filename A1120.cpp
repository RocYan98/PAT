#include <iostream>
#include <string>
#include <set>

using namespace std;
set<int> ans;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int sum = 0;
        string str;
        cin >> str;
        for (auto i : str) {
            sum += i - '0';
        }
        ans.insert(sum);
    }
    printf("%d\n", ans.size());
    for (auto ite = ans.begin(); ite != ans.end(); ++ite) {
        if (ite != ans.begin()) printf(" ");
        printf("%d", *ite);
    }
    return 0;
}
