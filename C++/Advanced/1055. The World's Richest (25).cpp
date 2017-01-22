#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Person {
    char name[9];
    int age, worth;
};

int main () {
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    struct Person *persons = new struct Person[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", persons[i].name, &persons[i].age, &persons[i].worth);
    }
    
    qsort(persons, n, sizeof(persons[0]), [](const void *a, const void *b){
        const struct Person arg1 = *static_cast<const struct Person *>(a);
        const struct Person arg2 = *static_cast<const struct Person *>(b);
        
        if (arg1.worth > arg2.worth) return -1;
        if (arg1.worth < arg2.worth) return 1;
        if (arg1.age > arg2.age) return 1;
        if (arg1.age < arg2.age) return -1;
        return strcmp(arg1.name, arg2.name);
    });
    
    for (int i = 0; i < k; i++) {
        printf("Case #%d:\n", (i + 1));
        int m = 0, amin = 0, amax = 0, state = 0;
        scanf("%d %d %d", &m, &amin, &amax);
        for (int i = 0; i < n && m > 0; i++) {
            if (persons[i].age >= amin && persons[i].age <= amax) {
                printf("%s %d %d\n", persons[i].name, persons[i].age, persons[i].worth);
                state = 1;
                m--;
            }
        }
        if (!state) {
            printf("None\n");
        }
    }
    delete [] persons;
    return 0;
}
