#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_pal(const string &str) {
    string a = str.substr(0, str.size() / 2);
    string b = str.substr((str.size() + 1) / 2, str.size() / 2);
    reverse(a.begin(), a.end());
    return a == b;
}

int main() {
    string str;
    cin >> str;
    int i = 10;
    while (!is_pal(str) && i--) {
        string res, a = str;
        reverse(str.begin(), str.end());
        string b = str;
        int carry = 0;
        for (int j = 0; j < str.size(); ++j) {
            int temp = a[j] - '0' + b[j] - '0' + carry;
            carry = temp / 10;
            res.push_back(temp % 10 + '0');
        }
        if (carry) res.push_back('1');
        reverse(res.begin(), res.end());
        printf("%s + %s = %s\n", a.c_str(), b.c_str(), res.c_str());
        str = res;
    }
    is_pal(str) ? printf("%s is a palindromic number.", str.c_str()) : printf("Not found in 10 iterations.");
    return 0;
}
