#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
char ch[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

string change(int x) {
    string res;
    do {
        res.push_back(ch[x % 13]);
        x /= 13;
    } while(x);
    if (res.size() < 2) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    cout << "#" << change(a) << change(b) << change(c);
    return 0;
}
