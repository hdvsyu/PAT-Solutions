#include <cstdio>

void print_post_order(int *arr, int n, int cur) {
    if (cur > n) return;
    int left_child = 2 * cur, right_child = 2 * cur + 1;
    print_post_order(arr, n, left_child);
    print_post_order(arr, n, right_child);
    if (cur != 1) printf("%d ", arr[cur]);
}

bool min_heap(int *arr, int n, int cur) {
    if (cur >= n) return true;
    int left_child = cur * 2, right_child = cur * 2 + 1;
    if (right_child <= n) {
        if (arr[left_child] >= arr[cur] && arr[right_child] >= arr[cur]) {
            return min_heap(arr, n, left_child) && min_heap(arr, n, right_child);
        }
    } else if (left_child <= n) {
        if (arr[left_child] >= arr[cur]) {
            return min_heap(arr, n, left_child) && min_heap(arr, n, right_child);
        }
    } else {
        return true;
    }
    return false;
}

bool max_heap(int *arr, int n, int cur) {
    if (cur >= n) return true;
    int left_child = cur * 2, right_child = cur * 2 + 1;
    if (right_child <= n) {
        if (arr[left_child] <= arr[cur] && arr[right_child] <= arr[cur]) {
            return max_heap(arr, n, left_child) && max_heap(arr, n, right_child);
        } else {
            return false;
        }
    } else if (left_child <= n) {
        if (arr[left_child] <= arr[cur]) {
            return max_heap(arr, n, left_child) && max_heap(arr, n, right_child);
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int m = 0, n = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        int *arr = new int[1030];
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[j]);
        }
        if (max_heap(arr, n, 1)) {
            printf("Max Heap\n");
        } else if (min_heap(arr, n, 1)) {
            printf("Min Heap\n");
        } else {
            printf("Not Heap\n");
        }
        print_post_order(arr, n, 1);
        printf("%d\n", arr[1]);
        delete [] arr;
    }
    return 0;
}
