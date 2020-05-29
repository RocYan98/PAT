#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Account {
    string username, pwd;
} temp;
vector<Account> arr;

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        string username, pwd;
        cin >> username >> pwd;
        temp.username = username;
        temp.pwd = pwd;
        for (auto &ch : temp.pwd) {
            if (ch == '1') ch = '@';
            if (ch == '0') ch = '%';
            if (ch == 'l') ch = 'L';
            if (ch == 'O') ch = 'o';
        }
        if (temp.pwd != pwd) {
            arr.push_back(temp);
            ans++;
        }
    }
    
    if (arr.size()) {
        printf("%d\n", arr.size());
        for (auto account : arr) {
            printf("%s %s\n", account.username.c_str(), account.pwd.c_str());
        }
    } else if (n == 1) {
        printf("There is 1 account and no account is modified");
    } else printf("There are %d accounts and no account is modified", n);
    return 0;
}
