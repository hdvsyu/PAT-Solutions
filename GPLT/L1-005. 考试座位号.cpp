#include <iostream>

struct site {
    char s[15];
    int test, exam;
}stu[1010];

struct site find(int test, int n) {
    for (int i = 0; i < n; i++) {
        if (stu[i].test == test) {
            return stu[i];
        }
    }
    return stu[-1];
}

int main() {
    int n = 0, m = 0, temp = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", stu[i].s, &stu[i].test, &stu[i].exam);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        struct site r = find(temp, n);
        printf("%s %d\n", r.s, r.exam);
    }
    
    return 0;
}
