#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int len = 10010;
int father[len], empty[len], estates[len], areas[len];
vector<struct Family> family;

struct Family {
    int id, m;
    double estate, area;
    Family(int m_id, int m_m, double m_estate, double m_area) {
        id = m_id; m = m_m; estate = m_estate; area = m_area;
    }
};

bool cmp (struct Family a, struct Family b) {
    if (a.area > b.area) return true;
    if (a.area == b.area) {
        return a.id < b.id;
    }
    return false;
}

void init () {
    for (int i = 0; i < len; i++) {
        father[i] = i; empty[i] = 1; estates[i] = 0; areas[i] = 0;
    }
}

int findFather (int x) {
    while (x != father[x]) x = father[x];
    return x;
}

void unionFind (int a, int b) {
    if (b == -1) return;
    int fa = findFather(a), fb = findFather(b);
    if (fa < fb) father[fb] = fa;
    else if (fb < fa) father[fa] = fb;
}

void findFamily () {
    int f[len];
    fill(f, f + len, 0);
    for (int i = 0; i < len; i++) {
        f[findFather(i)]++;
        if (i != findFather(i)) {
            estates[findFather(i)] += estates[i];
            areas[findFather(i)] += areas[i];
        }
    }
    for (int i = 0; i < len; i++) {
        if (!empty[i] && f[i] != 0) {
            struct Family fy(i, f[i], estates[i] * 1.0 / f[i], areas[i] * 1.0 / f[i]);
            family.push_back(fy);
        }
    }
}

int main () {
    init();
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int id = 0, f = 0, m = 0, k = 0;
        scanf("%d %d %d %d", &id, &f, &m, &k);
        unionFind(id, f); unionFind(id, m);
        empty[id] = 0;
        if (f != -1) empty[f] = 0;
        if (m != -1) empty[m] = 0;
        for (int j = 0; j < k; j++) {
            int child = 0;
            scanf("%d", &child);
            unionFind(id, child);
            empty[child] = 0;
        }
        int estate = 0, area = 0;
        scanf("%d %d", &estate, &area);
        estates[id] = estate;
        areas[id] = area;
    }
    findFamily();
    
    sort(family.begin(), family.end(), cmp);
    printf("%lu\n", family.size());
    for (int i = 0; i < family.size(); i++) {
        struct Family t = family[i];
        printf("%04d %d %.3f %.3f\n", t.id, t.m, t.estate, t.area);
    }
    return 0;
}