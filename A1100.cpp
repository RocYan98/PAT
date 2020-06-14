#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
string digit[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec", "tam",
                  "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

vector<string> split(string str) {
    vector<string> res;
    string temp;
    stringstream ss;
    ss << str;
    while (getline(ss, temp, ' ')) {
        res.push_back(temp);
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        string str;
        getline(cin, str);
        if (isdigit(str[0])) {
            int num = stoi(str);
            if (num > 12) {
                printf("%s", digit[12 + num / 13].c_str());
                num %= 13;
                if (num) printf(" %s", digit[num].c_str());
            } else {
                printf("%s", digit[num].c_str());
            }
            printf("\n");
        } else {
            vector<string> temp = split(str);
            int ans = 0;
            for (int i = 0; i < temp.size(); ++i) {
                int idx = 0;
                while (digit[idx] != temp[i]) idx++;
                ans += idx > 12 ? (idx - 12) * 13 : idx;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
