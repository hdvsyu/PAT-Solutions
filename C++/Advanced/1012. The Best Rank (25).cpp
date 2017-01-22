#include <cstdio>
#include <cstring>
#include <cstdlib>

struct Student {
    char id[7];
    int score[4];
    int rank[4];
};

int cmp0 (const void *a, const void *b) {
    struct Student arg1 = *static_cast<const struct Student *>(a);
    struct Student arg2 = *static_cast<const struct Student *>(b);
    
    if (arg1.score[0] > arg2.score[0]) return -1;
    if (arg1.score[0] < arg2.score[0]) return 1;
    return 0;
}

int cmp1 (const void *a, const void *b) {
    struct Student arg1 = *static_cast<const struct Student *>(a);
    struct Student arg2 = *static_cast<const struct Student *>(b);
    
    if (arg1.score[1] > arg2.score[1]) return -1;
    if (arg1.score[1] < arg2.score[1]) return 1;
    return 0;
}

int cmp2 (const void *a, const void *b) {
    struct Student arg1 = *static_cast<const struct Student *>(a);
    struct Student arg2 = *static_cast<const struct Student *>(b);
    
    if (arg1.score[2] > arg2.score[2]) return -1;
    if (arg1.score[2] < arg2.score[2]) return 1;
    return 0;
}

int cmp3 (const void *a, const void *b) {
    struct Student arg1 = *static_cast<const struct Student *>(a);
    struct Student arg2 = *static_cast<const struct Student *>(b);
    
    if (arg1.score[3] > arg2.score[3]) return -1;
    if (arg1.score[3] < arg2.score[3]) return 1;
    return 0;
}

void printRank (struct Student s) {
    int rank = s.rank[0], index = 0;
    for (int i = 1; i <= 3; i++) {
        if (rank > s.rank[i]) {
            index = i;
            rank = s.rank[i];
        }
    }
    printf("%d ", rank);
    switch (index) {
        case 0:printf("A\n");
            break;
        case 1:printf("C\n");
            break;
        case 2:printf("M\n");
            break;
        case 3:printf("E\n");
            break;
    }
}

int main () {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    struct Student *students = new struct Student[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", students[i].id, &students[i].score[1], &students[i].score[2], &students[i].score[3]);
        students[i].score[0] = (students[i].score[1] + students[i].score[2] + students[i].score[3]) / 3.0 + 0.5;
    }
    
    // qsort by C Programming Language
    qsort(students, n, sizeof(students[0]), cmp1);
    for (int i = 0; i < n; i++) {
        students[i].rank[1] = i + 1;
        if (i != 0 && students[i].score[1] == students[i - 1].score[1]) {
            students[i].rank[1] = students[i - 1].rank[1];
        }
    }
    
    // qsort by Mathematics
    qsort(students, n, sizeof(students[0]), cmp2);
    for (int i = 0; i < n; i++) {
        students[i].rank[2] = i + 1;
        if (i != 0 && students[i].score[2] == students[i - 1].score[2]) {
            students[i].rank[2] = students[i - 1].rank[2];
        }
    }
    
    // qsort by English
    qsort(students, n, sizeof(students[0]), cmp3);
    for (int i = 0; i < n; i++) {
        students[i].rank[3] = i + 1;
        if (i != 0 && students[i].score[3] == students[i - 1].score[3]) {
            students[i].rank[3] = students[i - 1].rank[3];
        }
    }
    
    // qsort by Average
    qsort(students, n, sizeof(students[0]), cmp0);
    for (int i = 0; i < n; i++) {
        students[i].rank[0] = i + 1;
        if (i != 0 && students[i].score[0] == students[i - 1].score[0]) {
            students[i].rank[0] = students[i - 1].rank[0];
        }
    }
    
    
    for (int i = 0; i < m; i++) {
        char id[7];
        scanf("%s", id);
        bool state = true;
        for (int j = 0; j < n; j++) {
            if (strcmp(students[j].id, id) == 0) {
                printRank(students[j]);
                state = false;
                break;
            } else {
                
            }
        }
        if (state) printf("N/A\n");
    }
    delete [] students;
    return 0;
}