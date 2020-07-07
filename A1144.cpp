#include <iostream>
#include <set>

using namespace std;
set<int> arr;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int temp;
        scanf("%d", &temp);
        arr.insert(temp);
    }
    int i = 1;
    while (arr.count(i)) i++;
    printf("%d", i);
    return 0;
}
