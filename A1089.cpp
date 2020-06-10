#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> a, init, part;

void print() {
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
}

void insert_sort(int i) {
    int temp = a[i];
    int j = i;
    while (j && a[j - 1] > temp) {
        a[j] = a[j - 1];
        j--;
    }
    a[j] = temp;
}

void merge_sort(int i) {
    for (int j = 0; j < n; j += i) {
        sort(a.begin() + j, a.begin() + min(j + i, n));
    }
}

int main() {
    scanf("%d", &n);
    int temp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        init.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        part.push_back(temp);
    }
    a = init;

    for (int i = 1; i < n; ++i) {
        insert_sort(i);
        if (a == part) {
            printf("Insertion Sort\n");
            insert_sort(i + 1);
            print();
            return 0;
        }
    }

    a = init;
    for (int i = 2; i < n; i *= 2) {
        merge_sort(i);
        if (a == part) {
            printf("Merge Sort\n");
            merge_sort(2 * i);
            print();
            return 0;
        }
    }
    return 0;
}
