#include <cstdio>
#include <algorithm>

struct athlete {
    int id, dist;
    athlete() {}
    athlete(int _id, int _dist): id(_id), dist(_dist) {};
};

bool cmp(athlete a, athlete b) {
    return a.dist < b.dist;
}

int main() {
    int n = 0, id = 0, x = 0, y = 0;
    scanf("%d", &n);
    athlete athletes[10010];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &id, &x, &y);
        athletes[i] = athlete(id, x * x + y * y);
    }
    std::sort(athletes, athletes + n, cmp);
    printf("%04d %04d", athletes[0].id, athletes[n-1].id);
    return 0;
}
