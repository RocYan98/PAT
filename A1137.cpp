#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
struct Score {
    string id;
    int gp, gm, gf, g;
} scores[10000];
map<string, int> legal;

bool cmp(const Score &a, const Score &b) {
    if (a.g != b.g) return a.g > b.g;
    else return a.id < b.id;
}

int main() {
    int p, m, n, idx = 0, s;
    string id;
    scanf("%d%d%d", &p, &m, &n);
    for (int i = 0; i < p; ++i) {
        cin >> id >> s;
        if (s >= 200) {
            legal[id] = idx;
            scores[idx++] = {id, s, -1, -1, -1};
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> id >> s;
        if (legal.count(id)) scores[legal[id]].gm = s;
    }
    for (int i = 0; i < n; ++i) {
        cin >> id >> s;
        if (legal.count(id)) scores[legal[id]].gf = s;
    }
    for (int i = 0; i < idx; ++i) {
        int gm = scores[i].gm == -1 ? 0 : scores[i].gm;
        int gf = scores[i].gf == -1 ? 0 : scores[i].gf;
        scores[i].g = gm > gf ? round(gm * 0.4 + gf * 0.6) : gf;
    }
    sort(scores, scores + idx, cmp);
    for (int i = 0; i < idx; ++i) {
        if (scores[i].g < 60) break;
        printf("%s %d %d %d %d\n", scores[i].id.c_str(), scores[i].gp, scores[i].gm, scores[i].gf, scores[i].g);
    }
    return 0;
}
