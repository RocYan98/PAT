#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Player {
	int id, weight, turn, rank;
} p[100010];

bool cmp(Player a, Player b) {
	return a.turn > b.turn;
}

bool cmp2(Player a, Player b) {
	return a.id < b.id;
}

int main() {
	int np, ng;
	queue<Player> que;
	scanf("%d%d", &np, &ng);
	for (int i = 0; i < np; ++i) {
		scanf("%d", &p[i].weight);
		p[i].id = i;
	}
	for (int i = 0; i < np; ++i) {
		int temp;
		scanf("%d", &temp);
		que.push(p[temp]);
	}
	int count = np;
	int i = 0, max = -1, id, turn = 1;
	while(!que.empty()) {
		if ((i % ng == 0 && i != 0) || count == 0) {
			que.push(p[id]);
			max = -1;
			if (count == 0) {
				i = 0;
				count = que.size();
				turn++;
				continue;
			}
		}
		if (max < que.front().weight) {
			max = que.front().weight;
			id = que.front().id;
		}
		p[que.front().id].turn = turn;
		que.pop();
		i++;
		count--;
	}
	p[id].turn = turn + 1;
	
	sort(p, p + np, cmp);
	
	for (int j = 0; j < np; ++j) {
		if (j > 0 && p[j].turn == p[j-1].turn) {
			p[j].rank = p[j-1].rank;
		} else {
			p[j].rank = j + 1;
		}
	}
	
	sort(p, p + np, cmp2);
	for (int j = 0; j < np; ++j) {
		printf("%d", p[j].rank);
		if (j != np - 1) printf(" ");
	}
	return 0; 
}
