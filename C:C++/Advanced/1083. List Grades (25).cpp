#include <cstdio>
#include <cstdlib>

struct Student {
    char name[11], id[11];
    int grade;
};

int main() {
    int n = 0;
    scanf("%d", &n);
    struct Student *records = new struct Student[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", records[i].name, records[i].id, &records[i].grade);
    }
    int grade1 = 0, grade2 = 0;
    scanf("%d %d", &grade1, &grade2);
    qsort(records, n, sizeof(records[0]), [](const void *a, const void *b){
        const struct Student arg1 = *static_cast<const struct Student *>(a);
        const struct Student arg2 = *static_cast<const struct Student *>(b);
        
        if (arg1.grade > arg2.grade) return -1;
        if (arg1.grade < arg2.grade) return 1;
        return 0;
    });
    
    bool state = false;
    for (int i = 0; i < n; i++) {
        if (records[i].grade >= grade1 && records[i].grade <= grade2) {
            printf("%s %s\n", records[i].name, records[i].id);
            state = true;
        }
    }
    if (!state) {
        printf("NONE");
    }
    delete [] records;
    return 0;
}
