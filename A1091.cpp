#include <iostream>
#include <queue>

using namespace std;
int m, n, l, t;
struct Node {
    int x, y, z;
    Node(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

int slice[1286][128][60];
int inq[1286][128][60];

bool judge(int x, int y, int z) {
    if (x >= m || y >= n || z >= l) return false;
    if (x < 0 || y < 0 || z < 0) return false;
    if (slice[x][y][z] != 1 || inq[x][y][z]) return false;

    return true;
}

int cx[] = {1, -1, 0, 0, 0, 0};
int cy[] = {0, 0, 1, -1, 0, 0};
int cz[] = {0, 0, 0, 0, 1, -1};

int BFS(int x, int y, int z) {
    int count = 0;
    queue<Node> q;
    q.push(Node(x, y, z));
    inq[x][y][z] = 1;
    while (q.size()) {
        Node top = q.front();
        q.pop();
        count++;
        for (int i = 0; i < 6; ++i) {
            int newx = top.x + cx[i];
            int newy = top.y + cy[i];
            int newz = top.z + cz[i];
            if (judge(newx, newy, newz)) {
                q.push(Node(newx, newy, newz));
                inq[newx][newy][newz] = 1;
            }
        }
    }
    return count >= t ? count : 0;
}

int main() {
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                scanf("%d", &slice[j][k][i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                if (!inq[j][k][i] && slice[j][k][i]) {
                    ans += BFS(j, k, i);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
