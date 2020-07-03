#include <iostream>
#include <string>
#include <set>

using namespace std;
set<string> winner;

int main() {
    int m, n, s, idx = 0;
    scanf("%d%d%d", &m, &n, &s);
    for (int i = 1; i <= m; ++i) {
        string name;
        cin >> name;
        if (i >= s && idx % n == 0) {
            if (winner.find(name) == winner.end()) {
                printf("%s\n", name.c_str());
                winner.insert(name);
                idx = 1;
            }
        } else if (i > s) idx++;
    }
    if (m < s) printf("Keep going...");
    return 0;
}
