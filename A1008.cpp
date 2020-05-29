#include <iostream>
#include <vector>

using namespace std;
vector<int> list;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int temp;
        scanf("%d", &temp);
        list.push_back(temp);
    }
    
    int cur = 0, ans = 0;
    for (auto floor : list) {
        int move = floor - cur;
        ans += move < 0 ? 4 * -move : 6 * move;
        ans += 5;
        cur = floor;
    }
    printf("%d", ans);
    return 0;
}
