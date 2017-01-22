#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Record {
    int id, grade;
    char *name = new char[9];
};


void sortByThree(struct Record *records, int n) {
    qsort(records, n, sizeof(records[0]), [](const void *a, const void *b){
        const struct Record arg1 = *static_cast<const struct Record *>(a);
        const struct Record arg2 = *static_cast<const struct Record *>(b);
        
        if (arg1.grade > arg2.grade) return 1;
        if (arg1.grade < arg2.grade) return -1;
        if (arg1.id > arg2.id) return 1;
        return -1;
    });
}

void sortByTwo(struct Record *records, int n) {
    qsort(records, n, sizeof(records[0]), [](const void *a, const void *b){
        const struct Record arg1 = *static_cast<const struct Record *>(a);
        const struct Record arg2 = *static_cast<const struct Record *>(b);
        
        if (strcmp(arg1.name, arg2.name) > 0) return 1;
        if (strcmp(arg1.name, arg2.name) < 0) return -1;
        if (arg1.id > arg2.id) return 1;
        return -1;
    });
}

void sortByOne(struct Record *records, int n) {
    qsort(records, n, sizeof(records[0]), [](const void *a, const void *b){
        const struct Record arg1 = *static_cast<const struct Record *>(a);
        const struct Record arg2 = *static_cast<const struct Record *>(b);
        
        if (arg1.id > arg2.id) return 1;
        return -1;
    });
}

int main() {
    int n = 0, c = 0;
    scanf("%d %d", &n, &c);
    struct Record *records = new struct Record[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &records[i].id, records[i].name, &records[i].grade);
    }
    switch (c) {
        case 1:
            sortByOne(records, n);
            break;
        case 2:
            sortByTwo(records, n);
            break;
        default:
            sortByThree(records, n);
            break;
    }
    
    for (int i = 0; i < n; i++) {
        printf("%06d %s %d\n", records[i].id, records[i].name, records[i].grade);
    }
    
    delete [] records;
    return 0;
}
