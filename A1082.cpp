#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string digit[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string bit[4] = {"", "Shi", "Bai", "Qian"};
string unit[3] = {"", "Wan", "Yi"};

int main() {
    int num, have_print = 0;
    scanf("%d", &num);
    if (num < 0) {
        printf("Fu");
        have_print = 1;
        num = -num;
    }
    if (num == 0) {
        printf("ling");
        return 0;
    }
    string nums[3];
    int len = 0;
    do {
        nums[len++] = to_string(num % 10000);
        num /= 10000;
    } while (num);
    for (int i = len - 1; i >= 0; --i) {
        while (!nums[i].empty() && nums[i].front() == '0') nums[i].erase(nums[i].begin());
        if (!nums[i].empty()) {
            int size = nums[i].size();
            size--;
            if (i != len - 1 && size < 3) printf(" ling");
            for (int j = 0; j < nums[i].size(); ++j) {
                if (nums[i][j] == '0') {
                    size--;
                    continue;
                }
                else if (j && nums[i][j - 1] == '0') printf(" ling");
                have_print ? printf(" ") : have_print = 1;
                printf("%s", digit[nums[i][j] - '0'].c_str());
                if(size) printf(" %s", bit[size--].c_str());
            }
            if (i) printf(" %s", unit[i].c_str());
        }
    }
    return 0;
}
