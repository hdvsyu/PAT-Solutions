#include <cstdio>
#include <algorithm>

using namespace std;

bool isInsert (int *init, int *part, int n) {
    int i = 1;
    while (i < n && part[i] >= part[i - 1]) i++;
    while (i < n && init[i] == part[i]) i++;
    if (i == n) return true;
    return false;
}

void insertSort (int *part, int n) {
    int i = 1;
    while (i < n && part[i] >= part[i - 1]) i++;
    sort(part, part + i + 1);
}

bool isEqual (int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void mergeSort (int *init, int *part, int n) {
    int k = 2;
    for (k = 2; k < n; k = 2 * k) {
        int i = 0;
        for (i = 0; i + k < n; i+=k) {
            sort(init + i, init + i + k);
        }
        sort(init + i, init + n);
        if (isEqual(part, init, n)) break;
    }
    k = 2 * k;
    int i = 0;
    for (i = 0; i + k < n; i+=k) {
        sort(part + i, part + i + k);
    }
    sort(part + i, part + n);
}

int main () {
    int n = 0;
    scanf("%d", &n);
    int *init = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &init[i]);
    }
    int *part = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &part[i]);
    }
    bool insert = isInsert (init, part, n);
    if (insert) {
        printf("Insertion Sort\n");
        insertSort(part, n);
        printf("%d", part[0]);
        for (int i = 1; i < n; i++) {
            printf(" %d", part[i]);
        }
    } else {
        printf("Merge Sort\n");
        mergeSort(init, part, n);
        printf("%d", part[0]);
        for (int i = 1; i < n; i++) {
            printf(" %d", part[i]);
        }
    }
    delete [] part;
    delete [] init;
    return 0;
}
