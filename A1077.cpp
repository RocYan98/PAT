#include <iostream>
#include <string>

using namespace std;

string get_common(const string &a, const string &b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    while (i >= 0 && j >= 0) {
        if (a[i] != b[j]) break;
        i--;
        j--;
    }
    string common = a.substr(i + 1);
    return common;
}

int main() {
    int n;
    string a, b, common;
    scanf("%d", &n);
    getchar();
    getline(cin, a);
    getline(cin, b);
    common = get_common(a, b);
    for (int i = 2; i < n; ++i) {
        getline(cin, a);
        common = get_common(a, common);
    }
    printf("%s", common.size() ? common.c_str() : "nai");
    return 0;
}


