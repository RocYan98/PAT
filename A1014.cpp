#include <iostream>
#include <queue>

using namespace std;
struct Cus {
    int endtime, process_time;
} cus[1010]; 
int n, m, k, query;
queue<int> q[30];

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &query);
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &cus[i].process_time);
        int min = 20, min_q = -1;
        for (int j = 0; j < n; ++j) {
            if (q[j].size() < m && q[j].size() < min) {
                min = q[j].size();
                min_q = j;
            }
        }
        
        if (min_q != -1) {
            q[min_q].empty() ? q[min_q].push(cus[i].process_time) : q[min_q].push(q[min_q].back() + cus[i].process_time);           
        } else {
            min = 999;
            for (int j = 0; j < n; ++j) {
                if (q[j].front() < min) {
                    min = q[j].front();
                    min_q = j;
                }
            }
            q[min_q].push(q[min_q].back() + cus[i].process_time);
            q[min_q].pop();
        }
        
        cus[i].endtime = q[min_q].back();
    }
    
    for (int i = 0; i < query; ++i) {
        int id;
        scanf("%d", &id);
        cus[id].endtime - cus[id].process_time >= 540 ? printf("Sorry\n") : printf("%02d:%02d\n", cus[id].endtime / 60 + 8, cus[id].endtime % 60);
    }
    return 0;
}
