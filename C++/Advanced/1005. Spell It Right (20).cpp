#include <cstdio>
#include <cstring>
#include <numeric>

char s[][7] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int flag = 0;

void print(int sum) {
    if (sum == 0) return;
    print(sum / 10);
    if (flag) printf(" ");
    flag = 1;
    printf("%s", s[sum % 10]);
}

int main() {
    char s[110];
    scanf("%s", s);
    int sum = std::accumulate(s, s + strlen(s), 0) - strlen(s) * '0';
    if (sum == 0) printf("zero");
    else print(sum);
    return 0;
}
