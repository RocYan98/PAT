#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

const int MAX = 10010;
struct Record {
    string plate, status;
    int time;
} records[MAX], vailed[MAX];

int change(int hh, int mm, int ss) {
    return hh * 3600 + mm * 60 + ss;
}

bool cmp(const Record &a, const Record &b) {
    return a.time < b.time;
}

bool cmp_plate(const Record &a, const Record &b) {
    if (a.plate != b.plate) return a.plate < b.plate;
    else return a.time < b.time;
}

map<string, int> last_time;
int car_count[86400];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int hh, mm, ss;
        string plate, status;
        cin >> plate;
        records[i].plate = plate;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        cin >> status;
        records[i].status = status;
        int temp = change(hh, mm, ss);
        records[i].time = temp;
    }

    sort(records, records + n, cmp_plate);
    int count = 0;
    int max = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (records[i].plate == records[i + 1].plate && records[i].status == "in" && records[i + 1].status == "out") {
            vailed[count++] = records[i];
            vailed[count++] = records[i + 1];
            int park_time = records[i + 1].time - records[i].time;

            last_time[records[i].plate] += park_time;
            if (max < last_time[records[i].plate]) max = last_time[records[i].plate];
        }
    }

    sort(vailed, vailed + count, cmp);
    fill(car_count, car_count + 86400, -1);
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        if (vailed[i].status == "in") sum++;
        else sum--;
        car_count[vailed[i].time] = sum;
    }

    for (int i = 0; i < k; ++i) {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int temp = change(hh, mm, ss);
        while (car_count[temp] == -1) {
            temp--;
        }
        printf("%d\n", car_count[temp]);
    }
    for (auto pair : last_time) {
        if (pair.second == max) printf("%s ", pair.first.c_str());
    }
    printf("%02d:%02d:%02d", max / 3600, max % 3600 / 60, max % 60);
    return 0;
}
