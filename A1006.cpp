#include <iostream>
#include <cstring>

using namespace std;
struct Time {
    int hh, mm, ss;
    
    bool operator<(const Time &other) const{
        if (this->hh != other.hh) return this->hh < other.hh;
        else if (this->mm != other.mm) return this->mm < other.mm;
        else return this->ss < other.mm;
    }
    
    bool operator>(const Time &other) const{
        if (this->hh != other.hh) return this->hh > other.hh;
        else if (this->mm != other.mm) return this->mm > other.mm;
        else return this->ss > other.mm;
    }
} temp;

int main() {
    int m;
    Time max, min;
    max.hh = max.mm = max.ss = -1;
    min.hh = min.mm = min.ss = 25;
    string unlock, lock;
    scanf("%d", &m);
    while (m--) {
        string id;
        cin >> id;
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        temp.hh = hh;
        temp.mm = mm;
        temp.ss == ss;
        if (temp < min) {
            min = temp;
            unlock = id;
        }
        
        scanf("%d:%d:%d", &hh, &mm, &ss);
        temp.hh = hh;
        temp.mm = mm;
        temp.ss == ss;
        if (temp > max) {
            max = temp;
            lock = id;
        }
    }
    
    cout << unlock << " " << lock;
    return 0;
}
