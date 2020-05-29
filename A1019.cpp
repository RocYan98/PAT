#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int n, radix;

bool judge(vector<int> x) {
    int len = x.size() / 2;
    for (int i = 0; i < len; ++i) {
        if (x[i] != x[x.size() - 1 - i]) return false;
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &radix);
    
    vector<int> num;
    do {
        num.push_back(n % radix);
        n /= radix;
    } while(n);
    
    reverse(num.begin(), num.end());
    printf("%s\n", judge(num) ? "Yes" : "No");
    for (int i = 0; i < num.size(); ++i) {
        if (i) printf(" ");
        printf("%d", num[i]);
    }
    return 0;
}
