#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        string str, s1, s2;
        cin >> str;
        s1 = str.substr(0, str.size() / 2);
        s2 = str.substr(str.size() / 2, str.size() / 2);
        int a = stoi(s1), b = stoi(s2), z = stoi(str);
        printf("%s\n", a * b != 0 && z % (a * b) == 0 ? "Yes" : "No");
    }
    return 0;
}
