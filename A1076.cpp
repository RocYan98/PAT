#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
struct Node {
    int depth;
    vector<int> fans;
} nodes[1010];
int n, l;

set<int> ans;
int inq[1010];
void BFS(int s) {
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int top = q.front();
        if (nodes[top].depth > l) break;
        q.pop();
        ans.insert(top);
        for (auto next : nodes[top].fans) {
            if (inq[next] == 0) {
                nodes[next].depth = nodes[top].depth + 1;
                q.push(next);
                inq[next] = 1;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; ++i) {
        int num;
        scanf("%d", &num);
        while (num--) {
            int temp;
            scanf("%d", &temp);
            nodes[temp].fans.push_back(i);
        }
    }
    int query_num;
    scanf("%d", &query_num);
    while (query_num--) {
        int query;
        scanf("%d", &query);
        ans.clear();
        fill(inq, inq + n + 1, 0);
        nodes[query].depth = 0;
        BFS(query);
        printf("%d\n", ans.size() - 1);
    }
    return 0;
}
