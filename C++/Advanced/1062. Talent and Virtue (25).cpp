#include <cstdio>
#include <cstdlib>

using namespace std;

struct student {
    int id, virtue, talent, level;
};

int cmp(const void *arg1, const void *arg2) {
    const struct student a = *static_cast<const struct student *>(arg1);
    const struct student b = *static_cast<const struct student *>(arg2);
    
    if (a.level < b.level) return -1;
    if (a.level > b.level) return 1;
    if (a.virtue + a.talent < b.virtue + b.talent) return 1;
    if (a.virtue + a.talent > b.virtue + b.talent) return -1;
    if (a.virtue > b.virtue) return -1;
    if (a.virtue < b.virtue) return 1;
    if (a.id < b.id) return -1;
    if (a.id > b.id) return 1;
    return 0;
}

int main() {
    int n = 0, h = 0, l = 0, cnt = 0;
    scanf("%d %d %d", &n, &l, &h);
    struct student *s = new struct student[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &s[i].id, &s[i].virtue, &s[i].talent);
        if (s[i].virtue < l || s[i].talent < l) {
            s[i].level = 5;
        } else {
            cnt++;
            if (s[i].virtue >= h && s[i].talent >= h) {
                s[i].level = 1;
            } else if (s[i].virtue >= h && s[i].talent < h) {
                s[i].level = 2;
            } else if (s[i].virtue >= s[i].talent) {
                s[i].level = 3;
            } else {
                s[i].level = 4;
            }
        }
    }
    qsort(s, n, sizeof(s[0]), cmp);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d %d %d\n", s[i].id, s[i].virtue, s[i].talent);
    }
    delete [] s;
    return 0;
}
