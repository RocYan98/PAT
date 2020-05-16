#include <iostream>
#include <string>

using namespace std;
struct Num {
	int d[30];
	int len;
} num, db;
int digit[10], ans[10];

bool judge(const Num &x) {
	if (db.len != num.len) return false;
	for (int i = 0; i < x.len; ++i) {
		ans[x.d[i]]++;
		if (ans[x.d[i]] > digit[x.d[i]]) return false;
	}
	for (int i = 0; i < 10; ++i) {
		if (digit[i] != ans[i]) return false;
	}
	return true;
}

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		num.d[i] = str[str.size() - 1 - i] - '0';
		digit[num.d[i]]++;
	}
	num.len = str.size();
	
	int curry = 0;
	for (int i = 0; i < num.len; ++i) {
		db.d[i] = num.d[i] * 2 % 10 + curry;
		curry = num.d[i] * 2 / 10;
	}
	
	db.d[num.len] = curry;
	db.len = curry ? num.len + 1 : num.len;
	
	printf("%s\n", judge(db) ? "Yes" : "No");
	for (int i = db.len - 1; i >= 0; --i) {
		printf("%d", db.d[i]);
	}
	return 0;
}
