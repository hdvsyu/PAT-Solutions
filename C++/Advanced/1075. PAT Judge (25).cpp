#include <cstdio>
#include <cstring>
#include <cstdlib>

struct User {
    int id, total, score[6], solved, rank, level;
    
    User() {
        for (int i = 0; i < 6; i++) {
            score[i] = -2;
        }
        total = solved = 0;
    }
};

bool isShown (struct User user, int k) {
    for (int i = 1; i <= k; i++) {
        if (user.score[i] != -1 && user.score[i] != -2) {
            return true;
        }
    }
    return false;
}

int main () {
    int n = 0, k = 0, m = 0;
    scanf("%d %d %d", &n, &k, &m);
    int *p = new int [k + 1];
    for (int i = 1; i <= k; i++) {
        scanf("%d", &p[i]);
    }
    struct User *users = new struct User[n + 1];
    for (int i = 0; i < m; i++) {
        int id = 0, pro = 0, sco = 0;
        scanf("%d %d %d", &id, &pro, &sco);
        users[id].id = id;
        users[id].score[pro] = users[id].score[pro] > sco ? users[id].score[pro] : sco;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            users[i].total += (users[i].score[j] == -1 || users[i].score[j] == -2 ? 0 : users[i].score[j]);
            if (users[i].score[j] == p[j]) users[i].solved++;
            if (isShown(users[i], k)) users[i].level = 1;
        }
    }
    
    qsort(users, n + 1, sizeof(users[1]), [](const void *a, const void *b){
        struct User arg1 = *static_cast<const struct User *>(a);
        struct User arg2 = *static_cast<const struct User *>(b);
        
        if (arg1.level > arg2.level) return -1;
        if (arg1.level < arg2.level) return 1;
        if (arg1.total > arg2.total) return -1;
        if (arg1.total < arg2.total) return 1;
        if (arg1.solved > arg2.solved) return -1;
        if (arg1.solved < arg2.solved) return 1;
        if (arg1.id < arg2.id) return -1;
        if (arg1.id > arg2.id) return 1;
        return 0;
    });
    
    for (int i = 0; i < n; i++) {
        if (isShown(users[i], k)) {
            users[i].rank = i + 1;
            if (i >= 1 && users[i].total == users[i - 1].total) {
                users[i].rank = users[i - 1].rank;
            }
            printf("%d %05d %d", users[i].rank, users[i].id, users[i].total);
            for (int j = 1; j <= k; j++) {
                if (users[i].score[j] != -2) printf(" %d", users[i].score[j] == -1 ? 0 : users[i].score[j]);
                else printf(" -");
            }
            printf("\n");
        }    }
    
    delete [] p;
    delete [] users;
    return 0;
}
