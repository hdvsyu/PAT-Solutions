#include <cstdio>
#include <algorithm>

using namespace std;

bool isInsert (int *init, int *part, int n) {
    int i = 1;
    while (i < n && part[i] >= part[i - 1]) i++;
    while (i < n && part[i] == init[i]) i++;
    if (i == n) return true;
    return false;
}

void insertSort (int *part, int n) {
    int i = 1;
    while (i < n && part[i] >= part[i - 1]) i++;
    sort(part, part + i + 1);
}

void adjust (int *part, int cur, int n) {
    int max = cur;
    if (2 * cur + 1 < n && part[2 * cur + 1] > part[max]) max = 2 * cur + 1;
    if (2 * cur + 2 < n && part[2 * cur + 2] > part[max]) max = 2 * cur + 2;
    if (max != cur) {
        swap(part[max], part[cur]);
        adjust(part, max, n);
    }
}

void heapSort (int *part, int end) {
    while (end >= 0 && part[end] > part[0]) end--;
    swap(part[0], part[end]);
    adjust(part, 0, end);
}

int main () {
    int n = 0;
    scanf("%d", &n);
    int *init = new int [n], *part = new int [n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &init[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &part[i]);
    }
    bool insert = isInsert(init, part, n);
    if (insert) {
        printf("Insertion Sort\n");
        insertSort(part, n);
        printf("%d", part[0]);
        for (int i = 1; i < n; i++) {
            printf(" %d", part[i]);
        }
    } else {
        printf("Heap Sort\n");
        heapSort(part, n - 1);
        printf("%d", part[0]);
        for (int i = 1; i < n; i++) {
            printf(" %d", part[i]);
        }
    }
    delete [] part;
    delete [] init;
    return 0;
}