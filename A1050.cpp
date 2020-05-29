#include <iostream>
#include <string>
#include <set>

using namespace std;
set<char> s;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (auto ch : s2) s.insert(ch);
    
    for (auto ite = s1.begin(); ite != s1.end();) {
        s.find(*ite) != s.end() ? ite = s1.erase(ite) : ite++;
    }
    
    printf("%s", s1.c_str());
    return 0;
}
