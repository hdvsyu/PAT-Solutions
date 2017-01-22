#include <cstdio>
#include <algorithm>
 
using namespace std;
 
const int MAX = 10010;
int father[MAX], bird[MAX];
 
void init() {
	for (int i = 0; i < MAX; i++) {
		father[i] = i;
		bird[i] = 0;
	}
}
 
int findFather(int f) {
	while (f != father[f]) {
		f = father[f];
	}
	return f;
}
 
void unionFind (int a, int b) {
	int fa = findFather(a);
	int fb = findFather(b);
	
	if (fa < fb) {
		father[fb] = fa;
	} else {
		father[fa] = fb;
	}
}
 
void getRoot () {
	int child[MAX];
	fill(child, child + MAX, 0);
	for (int i = 1; i < MAX; i++) {
		if (bird[i]) {
			child[findFather(i)]++;
		}
	}
	
	int sum = 0, cnt = 0;
	for (int i = 1; i < MAX; i++) {
		if (child[i] != 0) {
			cnt++;
			sum += child[i];
		}
	}
	printf("%d %d\n", cnt, sum);
}
 
int main() {
	init();
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k = 0, f = 0;
		scanf("%d %d", &k, &f);
		bird[f] = 1;
		for (int j = 1; j < k; j++) {
			int b = 0;
			scanf("%d", &b);
			bird[b] = 1;
			unionFind(f, b);
		}
	}
	getRoot();
	int q = 0;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		if (bird[a] && bird[b]) {
			if (findFather(a) == findFather(b)) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		} else {
			printf("No\n");
		}
	}
	
	return 0;
}