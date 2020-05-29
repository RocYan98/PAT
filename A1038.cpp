#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> arr;

bool cmp(const string &a, const string &b) {
    return a + b < b + a;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end(), cmp);
    
    string ans;
    for (auto str : arr) ans += str;
    while(ans[0] == '0') ans.erase(ans.begin());
    printf("%s", ans.size() == 0 ? "0" : ans.c_str());
    return 0;
}
