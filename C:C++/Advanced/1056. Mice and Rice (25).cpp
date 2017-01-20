#include <cstdio>
#include <queue>

using namespace std;

struct Mouse {
    int weight, rank;
};

int main() {
    int np = 0, ng = 0;
    scanf("%d %d", &np, &ng);
    struct Mouse *mouses = new struct Mouse[np];
    for (int i = 0; i < np; i++) {
        scanf("%d", &mouses[i].weight);
    }
    queue<int> compet;
    for (int i = 0; i < np; i++) {
        int t = 0;
        scanf("%d", &t);
        compet.push(t);
    }
    while (compet.size() > 1) {
        int temp = compet.size(), group;
        if (temp % ng == 0) group = temp / ng;
        else group = temp / ng + 1;
        for (int i = 0; i < group; i++) {
            int k = compet.front();
            for (int j = 0; j < ng; j++) {
                if (i * ng + j >= temp) break;
                int f = compet.front();
                if (mouses[k].weight < mouses[f].weight) k = f;
                mouses[f].rank = group + 1;
                compet.pop();
            }
            compet.push(k);
        }
    }
    mouses[compet.front()].rank = 1;
    printf("%d", mouses[0].rank);
    for (int i = 1; i < np; i++) {
        printf(" %d", mouses[i].rank);
    }
    delete [] mouses;
    return 0;
}
