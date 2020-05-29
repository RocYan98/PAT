#include <iostream>
#include <string>

using namespace std;
string day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int i = 0;
	while (!(a[i] >= 'A' && a[i] <= 'G') || a[i] != b[i]) i++;
	printf("%s ", day[a[i] - 'A'].c_str());
	i++;
	while (!(isdigit(a[i]) || (a[i] >= 'A' && a[i] <= 'N')) || a[i] != b[i]) i++;
	printf("%02d:", isdigit(a[i]) ? a[i] - '0' : a[i] - 'A' + 10);
	
	i = 0;
	while (!isalpha(c[i]) || c[i] != d[i]) i++;
	printf("%02d", i);
	return 0; 
}
