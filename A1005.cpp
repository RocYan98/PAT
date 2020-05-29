#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
char digit[][10] = {{"zero"}, {"one"}, {"two"}, {"three"}, {"four"}, {"five"}, {"six"}, {"seven"}, {"eight"}, {"nine"}};

int main() {
    string str;
    cin >> str;
    int sum = 0;
    for (auto s : str) {
        sum += s - '0';
    }
    
    vector<int> ans;
    do {
        ans.push_back(sum % 10);
        sum /= 10;
    } while(sum);
    
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        if (i) printf(" ");
        printf("%s", digit[ans[i]]);
    }
    return 0;
}
