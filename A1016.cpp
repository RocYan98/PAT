#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct Record {
	string name, status;
	int month, day, hour, minute;
} records[1010];
int n;
int price[24];

bool cmp(Record a, Record b) {
	if (a.name != b.name) return a.name < b.name;
	else if (a.month != b.month) return a.month < b.month;
	else if (a.day != b.day) return a.day < b.day;
	else if (a.hour != b.hour) return a.hour < b.hour;
	else return a.minute < b.minute;
}

int main() {
	for (int i = 0; i < 24; ++i) {
		scanf("%d", &price[i]);
	}
	
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		string name, status;
		cin >> name;
		records[i].name = name;
		scanf("%d:%d:%d:%d", &records[i].month, &records[i].day, &records[i].hour, &records[i].minute);
		cin >> status;
		records[i].status = status;
	}
	
	sort(records, records + n, cmp);
	
	int total = 0;
	for (int i = 0; i + 1 < n; ++i) {
		if (records[i].status == "on-line" && records[i + 1].status == "off-line" && records[i].name == records[i + 1].name) {
			Record* a = &records[i];
			Record* b = &records[i + 1];
			if (total == 0) {
				printf("%s %02d\n", records[i].name.c_str(), records[i].month);
			}
			int time = (b->day * 24 * 60 + b->hour * 60 + b->minute) - (a->day * 24 * 60 + a->hour * 60 + a->minute);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d", a->day, a->hour, a->minute, b->day, b->hour, b->minute, time);
			
			int cost = 0;
			while (a->day < b->day || a->hour < b->hour || a->minute < b->minute) {
				a->minute++;
				cost += price[a->hour];
				if (a->minute >= 60) {
					a->minute = 0;
					a->hour++;
				}
				if (a->hour >= 24) {
					a->hour = 0;
					a->day++;
				}
			}
			
			printf(" $%.2lf\n", cost / 100.);
			total += cost;	
		}
		
		if (total && (records[i + 2].name != records[i].name || i + 2 >= n)) {
			printf("Total amount: $%.2lf\n", total / 100.);
			total = 0;
		}
	}
	return 0;
}
