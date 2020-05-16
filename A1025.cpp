#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct Record {
	string id;
	int score, localtion, final_rank, local_rank;
} records[30010];
int n, k;

bool cmp(const Record &a, const Record &b) {
	if (a.score != b.score) return a.score > b.score;
	else return a.id < b.id;
}

int main() {
	scanf("%d", &n);
	int index = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			string id;
			cin >> id;
			scanf("%d", &records[index].score);
			records[index].id = id;
			records[index].localtion = i;
			index++;
		}
		sort(records + index - k, records + index, cmp);
		records[index - k].local_rank = 1;
		for (int j = 1; j < k; ++j) {
			int idx = index - k + j;
			records[idx].local_rank = records[idx].score == records[idx - 1].score ? records[idx - 1].local_rank : j + 1;
		}
	}
	
	sort(records, records + index, cmp);
	records[0].final_rank = 1;
	for (int i = 1; i < index; ++i) {
		records[i].final_rank = records[i].score == records[i - 1].score ? records[i - 1].final_rank : i + 1;
	}
	
	printf("%d\n", index);
	for (int i = 0; i < index; ++i) {
		printf("%s %d %d %d\n", records[i].id.c_str(), records[i].final_rank, records[i].localtion, records[i].local_rank);
	}
	
	return 0;
}
