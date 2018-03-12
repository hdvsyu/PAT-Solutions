#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int num) {
    if (num == 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    
    int n = 0, temp = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (is_prime(temp)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
