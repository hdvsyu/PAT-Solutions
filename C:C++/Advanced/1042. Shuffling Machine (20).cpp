#include <cstdio>
#include <vector>

using namespace std;

void swp (int *poker, const vector<int> &order) {
    int *temp = new int [55];
    for (int i = 1; i < 55; i++) temp[i] = 0;
    for (int i = 0; i < order.size(); i++) {
        temp[order[i]] = poker[i + 1];
    }
    
    for (int i = 1; i < 55; i++) {
        if (temp[i] != 0) poker[i] = temp[i];
    }
    delete [] temp;
}

void printPoker (int *poker) {
    char c[] = {'S', 'H', 'C', 'D', 'J'};
    for (int i = 1; i < 55; i++) {
        if (poker[i] % 13 == 0) {
            printf("%c13", c[poker[i] / 13 - 1]);
        } else {
            printf("%c%d", c[poker[i] / 13], poker[i] % 13);
        }
        if (i != 54) printf(" ");
    }
}

int main () {
    int k = 0;
    scanf("%d", &k);
    int *poker = new int[55];
    for (int i = 1; i < 55; i++) poker[i] = i;
    vector<int> order;
    int t = 0;
    while (~scanf("%d", &t)) {
        order.push_back(t);
    }
    
    for (int i = 0; i < k; i++) {
        swp(poker, order);
    }
    
    printPoker(poker);
    delete [] poker;
    return 0;
}
