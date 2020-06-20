#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
struct Person {
    int sets, area;
} people[10000];

struct Node {
    int id, sets, area, num;
    double avg_sets, avg_area;
} nodes[10000];
int father[10000];
set<int> ids, ans;

int find_father(int x) {
    int a = x;
    while (father[x] != x) x = father[x];
    while (father[a] != x) {
        int z = father[a];
        father[a] = x;
        a = z;
    }
    return x;
}

void merge(int a, int b) {
    int fa = find_father(a), fb = find_father(b);
    fa < fb ? father[fb] = fa : father[fa] = fb;
}

bool cmp(const Node &a, const Node &b) {
    if (a.avg_area != b.avg_area) return a.avg_area > b.avg_area;
    else return a.id < b.id;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 10000; ++i) {
        father[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        int id, fid, mid, k, cid, sets, area;
        scanf("%d%d%d%d", &id, &fid, &mid, &k);
        ids.insert(id);
        if (fid != -1) {
            merge(id, fid);
            ids.insert(fid);
        }
        if (mid != -1) {
            merge(id, mid);
            ids.insert(mid);
        }
        while (k--) {
            scanf("%d", &cid);
            merge(id, cid);
            ids.insert(cid);
        }
        scanf("%d%d", &sets, &area);
        people[id].sets = sets;
        people[id].area = area;
    }
    for (auto id : ids) {
        int fid = find_father(id);
        nodes[fid].id = fid;
        nodes[fid].area += people[id].area;
        nodes[fid].sets += people[id].sets;
        nodes[fid].num++;
        ans.insert(fid);
    }
    for (auto id : ans) {
        nodes[id].avg_area = nodes[id].area * 1. / nodes[id].num;
        nodes[id].avg_sets = nodes[id].sets * 1. / nodes[id].num;
    }
    sort(nodes, nodes + 10000, cmp);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%04d %d %.3lf %.3lf\n", nodes[i].id, nodes[i].num, nodes[i].avg_sets, nodes[i].avg_area);
    }
    return 0;
}
