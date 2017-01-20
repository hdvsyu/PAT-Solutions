#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int getMin(int number) {
    int *num = new int [4];
    for (int i = 0; i < 4; i++) {
        num[i] = number % 10;
        number /= 10;
    }
    
    sort(num, num + 4, [](int a, int b) {
        return a > b;
    });
    
    int result = 0;
    for (int i = 0; i < 4; i++) {
        result += num[i] * pow(10, i);
    }
    delete [] num;
    return result;
}

int getMax(int number) {
    int *num = new int [4];
    for (int i = 0; i < 4; i++) {
        num[i] = number % 10;
        number /= 10;
    }
    
    sort(num, num + 4, [](int a, int b) {
        return a < b;
    });
    
    int result = 0;
    for (int i = 0; i < 4; i++) {
        result += num[i] * pow(10, i);
    }
    delete [] num;
    return result;
}

int main() {
    int number = 0;
    scanf("%d", &number);
    do {
        int max = getMax(number);
        int min = getMin(number);
        number = max - min;
            printf("%04d - %04d = %04d\n", max, min, number);
    } while (number != 6174 && number != 0);
    return 0;
}
