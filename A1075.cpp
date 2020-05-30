#include <iostream>
#include <algorithm>

using namespace std;
struct User {
    int id, ttl, perfect, score[5], rank, pass;
} users[10010];
int n, k, m;
int full[5];

bool cmp(const User &a, const User &b) {
    if (a.ttl != b.ttl) return a.ttl > b.ttl;
    else if (a.perfect != b.perfect) return a.perfect > b.perfect;
    else if (a.pass != b.pass) return a.pass > b.pass;
    else return a.id < b.id;
}

void init() {
    for (int i = 0; i <= n; ++i) {
        users[i].id = i;
        fill(users[i].score, users[i].score + 5, -2);
    }
}

void print(int rank, int i) {
    users[i].rank = rank;
    printf("%d %05d %d", rank, users[i].id, users[i].ttl);
    for (int j = 0; j < k; ++j) {
        users[i].score[j] == -2 ? printf(" -") : printf(" %d", users[i].score[j]);
    }
    printf("\n");
}

int main() {
    scanf("%d%d%d", &n, &k, &m);
    init();
    for (int i = 0; i < k; ++i) {
        scanf("%d", &full[i]);
    }
    for (int i = 0; i < m; ++i) {
        int uid, pid, score;
        scanf("%d%d%d", &uid, &pid, &score);
        if (score == full[pid - 1] && users[uid].score[pid - 1] != full[pid - 1]) users[uid].perfect++;
        if (score > users[uid].score[pid - 1]) users[uid].score[pid - 1] = score;
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (users[i].score[j] >= 0) {
                users[i].ttl += users[i].score[j];
                users[i].pass = 1;
            }
            if (users[i].score[j] == -1) users[i].score[j] = 0;
        }
    }
    
    sort(users, users + n + 1, cmp);
    
    print(1, 0);
    for (int i = 1; i <= n; ++i) {
        if (users[i].pass == 0) break;
        users[i].ttl == users[i - 1].ttl ? print(users[i - 1].rank, i) : print(i + 1, i);
    }
    return 0;
}
