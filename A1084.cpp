#include <iostream>
#include <set>

using namespace std;
set<char> has_print;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    for (auto c : str1) {
        if (str2.find(c) == string::npos && has_print.find(toupper(c)) == has_print.end()) {
            printf("%c", toupper(c));
            has_print.insert(toupper(c));
        }
    }
    return 0;
}
