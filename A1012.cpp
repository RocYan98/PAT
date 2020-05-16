#include <iostream>
#include <algorithm>

using namespace std;
struct Score {
	int id;
	int grade[4];
} scores[2010];
char courses[]= {'A', 'C', 'M', 'E'};
int ans[1000000][4];

int type;
bool cmp(Score a, Score b) {
	if (a.grade[type] != b.grade[type]) return a.grade[type] > b.grade[type];
	else return a.id < b.id;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", &scores[i].id, &scores[i].grade[1], &scores[i].grade[2], &scores[i].grade[3]);
		scores[i].grade[0] = scores[i].grade[1] + scores[i].grade[2] + scores[i].grade[3];
	}
	
	for (int i = 0; i < 4; ++i) {
		type = i;
		sort(scores, scores + n, cmp);
		ans[scores[0].id][i] = 1;
		for (int j = 1; j < n; ++j) {
			ans[scores[j].id][i] = scores[j].grade[i] == scores[j - 1].grade[i] ? ans[scores[j - 1].id][i] : j + 1;
		}
	}
	
	for (int i = 0; i < m; ++i) {
		int min = 2010;
		char course;
		int id;
		scanf("%d", &id);
		for (int j = 0; j < 4; ++j) {
			if (ans[id][j] < min) {
				min = ans[id][j];
				course = courses[j];
			}
		}
		!min ? printf("N/A\n") : printf("%d %c\n", min, course);
	}
	return 0;
}
