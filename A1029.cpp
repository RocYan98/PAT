#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long
using namespace std;
vector<LL> arr;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        while (n--) {
            int temp;
            scanf("%lld", &temp);
            arr.push_back(temp);
        }
    }
    sort(arr.begin(), arr.end());
    printf("%lld", arr[(arr.size() - 1) / 2]);
    return 0;
}
