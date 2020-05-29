#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int n1, n2 = 3;
    while (n2 <= str.size()) {
        if ((str.size() + 2 - n2) % 2 == 0) {
            n1 = (str.size() + 2 - n2) / 2;
            if (n1 <= n2) break;
        }
        n2++;
    }
    
    int i = 0;
    for (; i < n1 - 1; ++i) {
        printf("%c", str[i]);
        for (int j = 0; j < n2 - 2; ++j) printf(" ");
        printf("%c\n", str[str.size() - 1 - i]);
    }
    
    while(n2--) printf("%c", str[i++]);
    return 0;
}
