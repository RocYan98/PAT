#include <iostream>
#include <map>

using namespace std;
int arr[100010];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    arr[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
    
    int flag = 0;
    while (!flag) {
        for (int i = 0; i < n; ++i) {
            int left = i, right = n;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (arr[mid] - arr[i] == m) {
                    printf("%d-%d\n", i + 1, mid);
                    flag = 1;
                    break;
                } else if (arr[mid] - arr[i] > m) right = mid - 1;
                else left = mid + 1;
            }
        }
        m++;
    }
    
    return 0;
}
