#include <iostream>
#include <vector>
#include <set>

using namespace std;
const int MAX = 100010;
vector<int> ls;
int smallest[MAX], largest[MAX];
set<int> ans;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        ls.push_back(temp);
    }

    int max = ls.front(), min = ls.back();
    for (int i = 0; i < n; ++i) {
        if (ls[i] > max) max = ls[i];
        if (ls[n - i - 1] < min) min = ls[n - i - 1];
        largest[i] = max;
        smallest[n - i - 1] = min;
    }

    for (int i = 0; i < n; ++i) {
        if (largest[i] <= ls[i] && smallest[i] >= ls[i]) ans.insert(ls[i]);
    }
    
    printf("%d\n", ans.size());
    for (auto ite = ans.begin(); ite != ans.end(); ++ite) {
        if (ite != ans.begin()) printf(" ");
        printf("%d", *ite);
    }
    printf("\n");
    return 0;
}
