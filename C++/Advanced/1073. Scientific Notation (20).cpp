#include <cstdio>
#include <cstring>

int main () {
    char *num = new char [200000];
    scanf("%s", num);
    int point = -1, e = -1;
    for (int i = 0; i < strlen(num); i++) {
        if (num[i] == '.') point = i;
        if (num[i] == 'E') e = i;
    }
    int E = 0;
    for (int i = e + 2; i < strlen(num); i++) {
        E = E * 10 + num[i] - '0';
    }
    if (num[0] != '+') printf("%c", num[0]);
    if (num[e + 1] == '+') {
        for (int i = 1; i < point; i++) printf("%c", num[i]);
        if (E >= e - point - 1) {
            for (int i = point + 1; i < e; i++) printf("%c", num[i]);
            for (int i = 0; i < E - e + point + 1; i++) printf("0");
        } else {
            for (int i = point + 1; i < point + 1 + E; i++) printf("%c", num[i]);
            printf(".");
            for (int i = point + 1 + E; i < e; i++) printf("%c", num[i]);
        }
    } else { // num[e + 1] == '-'
        if (E > 1) {
            printf("0.");
            for (int i = 0; i < E - 1; i++) printf("0");
            printf("%c", num[1]);
        } else {
            printf("%c.", num[1]);
        }
        for (int i = point + 1; i < e; i++) printf("%c", num[i]);
    }
    delete [] num;
    return 0;
}
