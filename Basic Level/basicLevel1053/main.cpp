#include <iostream>

using namespace std;

int main() {
	int n = 0;
	double e = 0;
	int d = 0;
	int mustEmpty = 0;
	int maybeEmpty = 0;
	cin >> n >> e >> d;
	for (int i = 0; i < n; i++) {
		int k = 0;
		cin >> k;
		int cnt = 0;
		if (k > d) {
			for (int j = 0; j < k; j++) {
				double temp = 0;
				cin >> temp;
				if (temp < e) {
					cnt++;
				}
			}
				
			if (cnt > k / 2) {
				mustEmpty++;
			}
		} else {
			for (int j = 0; j < k; j++) {
				double temp = 0;
				cin >> temp;
				if (temp < e) {
					cnt++;
				}
			}
				
			if (cnt > k / 2) {
				maybeEmpty++;
			}
		}
	}
	
		
	printf("%.1f%% %.1f%%", maybeEmpty * 1.0 / n * 100, mustEmpty * 1.0 / n * 100);
	return 0;
}
