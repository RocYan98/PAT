#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct Record {
    string id;
    int score;

    bool operator<(const Record &other) const {
        if (this->score != other.score) return this->score > other.score;
        else return this->id < other.id;
    }
} temp;

set<Record> level[3];
pair<int, int> site[1000];
map<int, int> date[1000000];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (n--) {
        string id;
        int score;
        cin >> id;
        scanf("%d", &score);

        temp = {id, score};
        if (id[0] == 'B') level[0].insert(temp);
        else if (id[0] == 'A') level[1].insert(temp);
        else level[2].insert(temp);

        int st = stoi(id.substr(1, 3));
        site[st].first++;
        site[st].second += score;

        int dt = stoi(id.substr(4, 6));
        date[dt][st]++;
    }
    for (int i = 1; i <= m; ++i) {
        int type;
        string term;
        scanf("%d", &type);
        cin >> term;
        printf("Case %d: %d %s\n", i, type, term.c_str());
        if (type == 1) {
            int l;
            if (term == "B") l = 0;
            else if (term == "A") l = 1;
            else l = 2;
            if (!level[l].size()) printf("NA\n");
            for (auto record : level[l]) printf("%s %d\n", record.id.c_str(), record.score);
        } else if (type == 2) {
            int l = stoi(term);
            site[l].first ? printf("%d %d\n", site[l].first, site[l].second) : printf("NA\n");
        } else {
            vector<pair<int, int>> ans;
            for (auto s : date[stoi(term)]) {
                ans.push_back(s);
            }
            sort(ans.begin(), ans.end(), cmp);
            if (ans.size() == 0) printf("NA\n");
            for (auto s : ans) {
                printf("%d %d\n", s.first, s.second);
            }
        }
    }
    return 0;
}
