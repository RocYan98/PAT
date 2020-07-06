#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
struct School {
    string name;
    int num, rank;
    double score;
} schools[100010];
map<string, int> s2i;

bool cmp(const School &a, const School &b) {
    if ((int)a.score != (int)b.score) return a.score > b.score;
    else if (a.num != b.num) return a.num < b.num;
    else return a.name < b.name;
}

int main() {
    int n, idx = 0;
    scanf("%d", &n);
    while (n--) {
        string id, sch;
        int s, i;
        cin >> id >> s >> sch;
        for (auto &c : sch) c = tolower(c);
        if (!s2i.count(sch)) {
            s2i[sch] = idx++;
            schools[s2i[sch]].name = sch;
        }
        i = s2i[sch];
        if (id[0] == 'B') schools[i].score += s / 1.5;
        else if (id[0] == 'A') schools[i].score += s;
        else schools[i].score += s * 1.5;
        schools[i].num++;
    }
    sort(schools, schools + idx, cmp);
    printf("%d\n", idx);
    for (int i = 0; i < idx; ++i) {
        if (!i) {
            schools[i].rank = 1;
            printf("%d %s %d %d\n", schools[i].rank, schools[i].name.c_str(), (int)schools[i].score, schools[i].num);
        } else {
            schools[i].rank = (int)schools[i].score == (int)schools[i - 1].score ? schools[i - 1].rank : i + 1;
            printf("%d %s %d %d\n", schools[i].rank, schools[i].name.c_str(), (int)schools[i].score, schools[i].num);
        }

    }
    return 0;
}
