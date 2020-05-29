#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string num;
    cin >> num;
    while (1) {
        while (num.size() < 4) num += '0';
        sort(num.begin(), num.end(), greater<char>());
        int a = stoi(num);
        sort(num.begin(), num.end());
        int b = stoi(num);
        
        int res = a - b;
        printf("%04d - %04d = %04d\n", a, b, res);
        
        if (res == 6174 || res == 0) break;
        num = to_string(res);
    }
    return 0;
}
