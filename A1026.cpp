#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
const int INF = 1000000000;
struct Player {
	int come, stay, wait, vip, served;
}player[10010];
struct Table {
	int end, usednum, vip;
}table[110];
int n, m, k;

bool cmp(Player a, Player b) {
	return a.come < b.come;
}

bool cmp2(Player a, Player b) {
	return a.come + a.wait < b.come + b.wait;
}

int empty_table() {
	int min = INF;
	int mi;
	for (int i = 0; i < m; ++i) {
		if (table[i].end < min) {
			min = table[i].end;
			mi = i;
		}
	}
	return mi;
}

int empty_vip_table() {
	int min = INF;
	int mi = -1;
	for (int i = 0; i < m; ++i) {
		if (table[i].end < min && table[i].vip) {
			min = table[i].end;
			mi = i;
		}
	}
	return mi;
}

int vip_player(int st, int time) {
	for (int i = st; i < n; ++i) {
		if (player[i].vip && player[i].come <= time && player[i].served == 0) return i;
	}
	return -1;
}

void print(int i) {
	int come = player[i].come;
	int start = come + player[i].wait;
	printf("%02d:%02d:%02d", come / 3600, come / 60 % 60, come % 60);
	printf(" %02d:%02d:%02d", start / 3600, start / 60 % 60, start % 60);
	printf(" %d\n", (int)round(player[i].wait / 60.));
}

int main() {
	scanf("%d", &n);
	int num = 0;
	for (int i = 0; i < n; ++i) {
		int hh, mm, ss, stay, vip;
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &stay, &vip);
		if (stay > 120) stay = 120;
		if (hh >= 21) continue;  
		player[num].come = hh * 3600 + mm * 60 + ss;
		player[num].stay = stay * 60;
		player[num].vip = vip;
		num++;
	}
	sort(player, player + num, cmp);
	scanf("%d%d", &m, &k);
	for (int i = 0; i < k; ++i) {
		int temp;
		scanf("%d", &temp);
		table[temp-1].vip = 1;
	}
	
	int i = 0;
	while (i < num) {
		if (player[i].served) {
			i++;
			continue;
		}
		int tb = empty_table();
		if (table[tb].end >= 21 * 3600) break;
		if (table[tb].vip) {
			// is vip table
			if (player[i].vip) {
				// is vip player
				player[i].wait = max(0, table[tb].end - player[i].come);
				player[i].served = 1;
				table[tb].usednum++;
				table[tb].end = player[i].come + player[i].wait + player[i].stay;
			} else {
				// not vip player but vip table
				int vip = vip_player(i, table[tb].end);
				if (vip == -1) {
					// there is not vip player in the queue now
					player[i].wait = max(0, table[tb].end - player[i].come);
					player[i].served = 1;
					table[tb].usednum++;
					table[tb].end = player[i].come + player[i].wait + player[i].stay;
				} else {
					// there is vip player in the queue
					player[vip].wait = max(0, table[tb].end - player[vip].come);
					player[vip].served = 1;
					table[tb].usednum++;
					table[tb].end = player[vip].come + player[vip].wait + player[vip].stay;
				}
			}
		} else {
			// not vip table
			if (player[i].vip) {
				// is vip player
				int vip_tb = empty_vip_table();
				if (vip_tb != -1 && player[i].come >= table[vip_tb].end) tb = vip_tb;
				player[i].wait = max(0, table[tb].end - player[i].come);
				player[i].served = 1;
				table[tb].usednum++;
				table[tb].end = player[i].come + player[i].wait + player[i].stay;
			} else {
				// not vip player
				player[i].wait = max(0, table[tb].end - player[i].come);
				player[i].served = 1;
				table[tb].usednum++;
				table[tb].end = player[i].come + player[i].wait + player[i].stay;
			}
		}
	}
	sort(player, player + num, cmp2);
	
	for (int i = 0; i < num; ++i) {
		if (player[i].served) {
			print(i);
		}
	}
	
	for (int i = 0; i < m; ++i) {
		if (i) printf(" ");
		printf("%d", table[i].usednum);
	}
	return 0;
}
