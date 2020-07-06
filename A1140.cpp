#include <iostream>
#include <string>

using namespace std;

int main() {
    string d;
    int n;
    cin >> d >> n;
    while (--n) {
        int i = 0;
        string temp;
        while (i < d.size()) {
            int j = i + 1;
            while (j < d.size() && d[j] == d[i]) j++;
            temp.push_back(d[i]);
            temp.push_back(j - i + '0');
            i = j;
        }
        d = temp;
    }
    printf("%s", d.c_str());
    return 0;
}
