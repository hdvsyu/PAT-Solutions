#include <cstdio>

using namespace std;

int main() {
    char sign[] = "0123456789ABC";
    int a = 0, b = 0, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    printf("#%c%c%c%c%c%c", sign[a / 13], sign[a % 13], sign[b / 13], sign[b % 13], sign[c / 13], sign[c % 13]);
    return 0;
}
