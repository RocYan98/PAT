#include <iostream>
#include <string>

using namespace std;
int n;

string zero() {
    string res = "0.";
    for (int i = 0; i < n; ++i) {
        res += '0';
    }
    res += "*10^0";
    return res;
}

string standard(string &x) {
    string res = "0.";
    while (!x.empty() && x[0] == '0') x.erase(x.begin());
    if (x.empty()) return zero();
    if (x[0] != '.') {
        int i = 0;
        while (i < x.size() && x[i] != '.') i++;
        x.erase(i, 1);
        int j = 0;
        while (j < x.size() && j < n) {
            res.push_back(x[j++]);
        }
        while (j < n) {
            res += '0';
            j++;
        }
        res += "*10^";
        res += to_string(i);
    } else {
        int i = 1;
        while (i < x.size() && x[i] == '0') i++;
        if (i == x.size()) {
            return zero();
        }
        int j = i;
        while (j < x.size() && j - i < n) {
            res.push_back(x[j++]);
        }
        while (j - i < n) {
            res += '0';
            j++;
        }
        res += "*10^-";
        res += to_string(i - 1);
    }
    return res;
}

int main() {
    string a, b;
    scanf("%d", &n);
    cin >> a >> b;
    string sa = standard(a);
    string sb = standard(b);
    if (sa == sb) printf("YES %s", sa.c_str());
    else printf("NO %s %s", sa.c_str(), sb.c_str());
    return 0; 
}
