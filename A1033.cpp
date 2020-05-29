#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 1000000000;
struct Station {
    double price, dis;
} station[510];
double cmax, dis, avg;
int n;
double per_max;

bool cmp(const Station &a, const Station &b) {
    return a.dis < b.dis;
}

int main() {
    scanf("%lf%lf%lf%d", &cmax, &dis, &avg, &n);
    per_max = cmax * avg;
    
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &station[i].price, &station[i].dis);
    }
    station[n].dis = dis;
    station[n].price = 0;
    sort(station, station + n + 1, cmp);
    
    if (station[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    
    double ans = 0, rest_gas = 0;
    int cur_sta = 0;
    while (cur_sta < n) {
        int i = cur_sta + 1;
        int min_sta = cur_sta;
        while (i <= n && station[i].dis - station[cur_sta].dis <= per_max) {
            if (station[i].price <= station[cur_sta].price) {
                min_sta = i;
                break;
            }
            i++;
        }
        
        if (min_sta == cur_sta) {
            if (station[cur_sta + 1].dis - station[cur_sta].dis > per_max) {
                printf("The maximum travel distance = %.2lf", station[cur_sta].dis + per_max);
                return 0;
            }
            
            int j = cur_sta + 1;
            double min_price = INF;
            while (j <= n && station[j].dis - station[cur_sta].dis < per_max) {
                if (station[j].price < min_price) {
                    min_price = station[j].price;
                    min_sta = j;
                }
                j++;
            }
            
            ans += station[cur_sta].price * (cmax - rest_gas);
            rest_gas = cmax - (station[min_sta].dis - station[cur_sta].dis) / avg;
            cur_sta = min_sta;
        } else {
            ans += station[cur_sta].price * (station[min_sta].dis - station[cur_sta].dis - rest_gas * avg) / avg;
            rest_gas = 0;
            cur_sta = min_sta;
        }
    }
    
    printf("%.2lf", ans);
    return 0;
}
