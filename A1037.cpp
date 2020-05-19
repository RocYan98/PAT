#include <iostream>
#include <vector>
#include <algorithm>

#define LL long long
using namespace std;
vector<LL> coupon;
vector<LL> product;

int main() {
	int nc, np;
	scanf("%d", &nc);
	for (int i = 0; i < nc; ++i) {
		LL temp;
		scanf("%lld", &temp);
		coupon.push_back(temp);
	}
	scanf("%d", &np);
	for (int i = 0; i < np; ++i) {
		LL temp;
		scanf("%lld", &temp);
		product.push_back(temp);
	}
	
	sort(coupon.begin(), coupon.end());
	sort(product.begin(), product.end());
	
	int i = 0, j = 0;
	LL ans = 0;
	while (i < nc && j < np && coupon[i] < 0 && product[j] < 0) {
		ans += coupon[i++] * product[j++];
	}
	i = coupon.size() - 1;
	j = product.size() - 1;
	while (i >= 0 && j >= 0 && coupon[i] > 0 && product[j] > 0) {
		ans += coupon[i--] * product[j--];
	}
	
	printf("%lld", ans);
	return 0;
}
