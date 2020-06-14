#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int n, k, p;
vector<int> ans, temp;

int get_sum(const vector<int> &vec) {
    int sum = 0;
    for (auto i : vec) {
        sum += i;
    }
    return sum;
}

bool need_change() {
    int temp_sum = get_sum(temp);
    int ans_sum = get_sum(ans);
    return temp_sum != ans_sum ? temp_sum > ans_sum : temp > ans;
}

void DFS(int fac, int sum) {
    if (sum > n || fac < 1) return;
    if (temp.size() == k) {
        if (sum == n && need_change()) ans = temp;
        return;
    }
    temp.push_back(fac);
    int pw = pow(fac, p);
    DFS(fac, sum + pw);
    temp.pop_back();
    DFS(fac - 1, sum);
}

int main() {
    scanf("%d%d%d", &n, &k, &p);
    DFS(sqrt(n), 0);
    if (ans.size() == 0) printf("Impossible");
    else {
        printf("%d = ", n);
        for (int i = 0; i < ans.size(); ++i) {
            if (i) printf(" + ");
            printf("%d^%d", ans[i], p);
        }
    }
    return 0;
}
