#include <iostream>
#include <string>

using namespace std;

int main() {
    string num;
    char ch = getchar();
    if (ch == '-') printf("-");
    while (ch != 'E') {
        ch = getchar();
        if (isdigit(ch)) num.push_back(ch);
    }
    ch = getchar();
    
    int exp;
    scanf("%d", &exp);
    
    if (ch == '-') {
        printf("0.");
        for (int i = 1; i < exp; ++i) printf("0");
    } else {
        while (num.size() <= exp) num += '0';
        if (num.size() > exp + 1) {
            num.insert(num.begin() + exp + 1, '.');
        }
    }
    printf("%s", num.c_str());
    return 0;
}
