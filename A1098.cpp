#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> init, part, ls;

void insert_sort(int i) {
    int temp = ls[i];
    while (i && ls[i - 1] > temp) {
        ls[i] = ls[i - 1];
        i--;
    }
    ls[i] = temp;
}

void down_adjust(int low, int high) {
    int i = low;
    int j = 2 * i + 1;
    while (j < high) {
        if (j + 1 < high && ls[j + 1] > ls[j]) j++;
        if (ls[i] < ls[j]) swap(ls[i], ls[j]);
        i = j;
        j = 2 * i + 1;
    }
}

void create() {
    for (int i = n / 2; i >= 0; --i) {
        down_adjust(i, n);
    }
}

void print() {
    for (int i = 0; i < init.size(); ++i) {
        if (i) printf(" ");
        printf("%d", ls[i]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        init.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        part.push_back(temp);
    }

    ls = init;
    for (int i = 1; i < n; ++i) {
        insert_sort(i);
        if (ls == part) {
            printf("Insertion Sort\n");
            insert_sort(i + 1);
            print();
            return 0;
        }
    }

    ls = init;
    create();
    for (int i = n; i > 0; --i) {
        swap(ls[i - 1], ls[0]);
        down_adjust(0, i - 1);
        if (ls == part) {
            swap(ls[i - 2], ls[0]);
            down_adjust(0, i - 2);
            printf("Heap Sort\n");
            print();
            return 0;
        }
    }
    return 0;
}
