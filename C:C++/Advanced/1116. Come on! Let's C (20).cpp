#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int isPrime (int num) {
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}
 
int main() {
	int n = 0;
	scanf("%d", &n);
    int rank[10000];
    fill(rank, rank + 10000, -1);
	for (int i = 1; i <= n; i++) {
		int t = 0;
		scanf("%d", &t);
		rank[t] = i;
	}
	int k = 0;
	scanf("%d", &k);
	int checked[10000];
	fill(checked, checked + 10000, 0);
	for (int i = 0; i < k; i++) {
		int query = 0;
		scanf("%d", &query);
		
		if (rank[query] == -1) {
			printf("%04d: Are you kidding?\n", query);
		} else {
			if (checked[query] == 1) {
				printf("%04d: Checked\n");
			} else if (rank[query] == 1) {
				printf("%04d: Mystery Award\n", query);
				checked[query] = 1;
			} else {
				if (isPrime(rank[query])) {
					printf("%04d: Minion\n", query);
					checked[query] = 1;
				} else {
					printf("%04d: Chocolate\n", query);
					checked[query] = 1;
				}
			}
		}
		
	}
	return 0;
}