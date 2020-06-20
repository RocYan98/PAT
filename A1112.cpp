#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;
set<char> good;
vector<char> ans;
int inq[128];

int main() {
    int k;
    scanf("%d", &k);
    string str;
    cin >> str;
    int i = 0;
    while (i < str.size()) {
        int count = 1, j = i + 1;
        while (j < str.size() && str[j] == str[i]) {
            count++;
            j++;
        }
        if (count % k == 0 && inq[str[i]] == 0) {
            ans.push_back(str[i]);
            inq[str[i]] = 1;
        } else if (count % k != 0) good.insert(str[i]);
        i = j;
    }

    for (auto ite = ans.begin(); ite != ans.end();) {
        good.find(*ite) != good.end() ? ite = ans.erase(ite) : ite++;
    }
    for (auto ch : ans) {
        printf("%c", ch);
    }
    i = 0;
    while (i < str.size()) {
        if (good.find(str[i]) == good.end()) str.erase(i, k - 1);
        i++;
    }
    printf("\n%s", str.c_str());
    return 0;
}
