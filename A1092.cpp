#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int miss = 0;
    int extra = a.size() - b.size();
    for (auto c : b) {
        if (a.find(c) == string::npos) miss++;
        else a.erase(a.find(c), 1);
    }
    miss ? printf("No %d", miss) : printf("Yes %d", extra);
    return 0;
}
