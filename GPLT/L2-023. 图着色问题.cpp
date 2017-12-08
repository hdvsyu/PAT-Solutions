#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

bool verify(vector<vector<int>> vertex, int *color, int v) {
    for (int i = 1; i <= v; i++) {
        for (int j = 0; j < vertex[i].size(); j++) {
            if (color[vertex[i][j]] == color[i]) {
                return false;
            }
        }
    }
    return true;
}

int color_num(int *color, int v) {
    color[0] = -1;
    qsort(color, v+1, sizeof(*color), [](const void *a, const void *b){
        int arg1 = *static_cast<const int *>(a);
        int arg2 = *static_cast<const int *>(b);

        if (arg1 < arg2) return -1;
        if (arg1 > arg2) return 1;
        return 0;
    });
    int i = 1, j = 2;
    while (j <= v) {
        if (color[j] != color[i]) color[++i] = color[j];
        j++;
    }
    return i;
}

int main() {
    int v = 0, e = 0, k = 0, v1 = 0, v2 = 0, n = 0;
    scanf("%d %d %d", &v, &e, &k);
    vector<vector<int> > vertex(v+1); // 1 ~ v
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &v1, &v2);
        vertex[v1].push_back(v2);
        vertex[v2].push_back(v1);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int *color = new int[v+1];
        for (int j = 1; j <= v; j++) scanf("%d", &color[j]);
        if (verify(vertex, color, v) && color_num(color, v) == k) printf("Yes\n");
        else printf("No\n");
        delete [] color;
    }
    return 0;
}
