#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cmath>

#define LL long long
using namespace std;

int al2dig(char ch) {
    if (isdigit(ch)) {
        return ch - '0';
    } else {
        return ch - 'a' + 10;
    }
}


LL to_dec(int radix, string num) {
    LL res = 0;
    for (auto c : num) {
        res = res * radix + al2dig(c);
        if (res < 0) return -1;
    }
    return res;
}

int main() {
    string n1, n2;
    int tag, radix;
    cin >> n1 >> n2 >> tag >> radix;

    LL num;
    string rest;
    if (tag == 1) {
        num = to_dec(radix, n1);
        rest = n2;
    } else {
        num = to_dec(radix, n2);
        rest = n1;
    }
    
    char max_c = '0';
    for (auto c : rest) {
        if (c > max_c) max_c = c;
    }
    
    int r = al2dig(max_c) + 1;
    
    LL left = r;
    LL right = left > num ? left : num;
    while (left <= right) {
        LL mid = (left + right) / 2;
        LL temp = to_dec(mid, rest);
        if (temp > num || temp < 0) {
            right = mid - 1;
        } else if (temp < num) {
            left = mid + 1;
        } else if (temp == num) {
            cout << mid;
            break;
        }
        if (left > right) {
            cout << "Impossible";
        }
    }
    
    return 0;
}
