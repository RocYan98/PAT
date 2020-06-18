#include <iostream>
#include <string>

using namespace std;

bool is_legal(const string &num) {
    int point = 0;
    if (num[0] != '-' && !isdigit(num[0])) return false;
    for (int i = 1; i < num.size(); ++i) {
        if (!isdigit(num[i]) && num[i] != '.') return false;
        if (num[i] == '.') {
            if (point) return false;
            point++;
            if (num.size() - 1 - i > 2) return false;
        }
    }
    double temp = stod(num);
    return temp <= 1000 && temp >= -1000;
}

int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        string num;
        cin >> num;
        if (is_legal(num)) {
            count++;
            sum += stod(num);
        } else printf("ERROR: %s is not a legal number\n", num.c_str());
    }
    printf("The average of %d ", count);
    printf("%s is ", count == 1 ? "number" : "numbers");
    count ? printf("%.2lf", sum / count) : printf("Undefined");
    return 0;
}
