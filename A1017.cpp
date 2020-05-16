#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int OPEN = 8 * 3600;
const int CLOSE = 17 * 3600;
const int INF = 1000000000;
struct Record {
	int start, time;
} temp;
vector<Record> arr;
int n, k;
int window[110];

bool cmp(Record a, Record b) {
	return a.start < b.start;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		scanf("%d:%d:%d%d", &a, &b, &c, &d);
		int arrive = a * 3600 + b * 60 + c;
		if (arrive > CLOSE) continue;
		temp.start = arrive;
		if (d > 60) d = 60;
		temp.time = d;
		arr.push_back(temp);
	}
	
	sort(arr.begin(), arr.end(), cmp);
	
	int wait = 0;
	for (int i = 0; i < k && i < arr.size(); ++i) {
		if (arr[i].start < OPEN) {
			window[i] = OPEN;
			wait += OPEN - arr[i].start;
		} else window[i] = arr[i].start;
		window[i] += arr[i].time * 60;
	}
	
	for (int i = k; i < arr.size(); ++i) {
		int min = INF, w;
		for (int j = 0; j < k; ++j) {
			if (window[j] < min) {
				min = window[j];
				w = j;
			}
		}
		
		int t = window[w] - arr[i].start;
		if (t > 0) {
			wait += t;
			window[w] += arr[i].time * 60;
		} else {
			window[w] = arr[i].start + arr[i].time * 60;
		}
	}
	if (arr.size() == 0) printf("0.0");
	else printf("%.1lf", 1. * wait / 60 / arr.size());
	return 0;
}
