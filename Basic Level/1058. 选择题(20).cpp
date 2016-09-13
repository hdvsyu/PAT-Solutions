#include <cstdio>

struct Item {
    int score, unit, t;
    char *choose = new char [6];
};

bool equal(const struct Item &a, const struct Item &b) {
    if (a.t != b.t) return false;
    for (int i = 0; i < a.t; i++) {
        if (a.choose[i] != b.choose[i]) return false;
    }
    return true;
}

int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
        struct Item *items = new struct Item[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &items[i].score, &items[i].unit, &items[i].t);
        for (int j = 0; j < items[i].t; j++) {
            scanf(" %c", &items[i].choose[j]);
        }
    }
    
    int *error = new int [m];
    int maxValue = -1;
    for (int i = 0; i < n; i++) {
        int score = 0;
        for (int j = 0; j < m; j++) {
            struct Item s;
            char c = getchar();
            c = getchar();
            scanf("%d", &s.t);
            for (int k = 0; k < s.t; k++) {
                c = getchar();
                scanf("%c", &s.choose[k]);
            }
            c = getchar();
            if (equal(items[j], s)) score += items[j].score;
            else {
                error[j]++;
                if (error[j] > maxValue) maxValue = error[j];
            }
        }
        printf("%d\n", score);
    }
    
    if (maxValue == -1) {
        printf("Too simple");
    } else {
        printf("%d", maxValue);
        for (int i = 0; i < m; i++) {
            if (error[i] == maxValue) {
                printf(" %d", i + 1);
            }
        }
    }
    delete [] items;
    delete [] error;
    return 0;
}
