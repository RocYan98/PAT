#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> coins;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        if (temp < m) coins.push_back(temp);
    }
    
    sort(coins.begin(), coins.end());
    
    for (int i = 0; i < coins.size(); ++i) {
        int left = i + 1, right = coins.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (coins[i] + coins[mid] == m) {
                printf("%d %d", coins[i], coins[mid]);
                return 0;
            } else if (coins[i] + coins[mid] > m) right = mid - 1;
            else left = mid + 1;
        }
    }
    printf("No Solution");
    return 0;
}
