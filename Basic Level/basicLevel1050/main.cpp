#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N = 0;
	cin >> N;

	int *a = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	sort(a, a + N);

	int m = 1, n = 1;
	int min = 100001;
		
	// i is n
	for (int i = 1; i <= sqrt(N); i++) {
		if (N % i == 0) {
			// j is m
			int j = N / i;
			// m - n is the most small.
			if (min > j - i) {
				m = j;
				n = i;
				min = m - n;
			}
		}
	}

	int **matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[n];
	}

	int index = N - 1;
	int i = 0, j = 0;
	while (index >= 0) {
		// right.
		for (; index >= 0 && j < n && matrix[i][j] == 0; j++) {
			matrix[i][j] = a[index--];
		}
		i++;
		j--;

		// down.
		for (; index >= 0 && i < m && matrix[i][j] == 0; i++) {
			matrix[i][j] = a[index--];
		}

		i--;
		j--;

		// left.
		for (; index >= 0 && j >= 0 && matrix[i][j] == 0; j--) {
			matrix[i][j] = a[index--];
		}
		i--;
		j++;

		// up.
		for (; index >= 0 && i >= 0 && matrix[i][j] == 0; i--) {
			matrix[i][j] = a[index--];
		}
		i++;
		j++;
	}

	for (i = 0; i < m; i++) {
		cout << matrix[i][0];
		for (j = 1; j < n; j++) {
			cout << " " << matrix[i][j];
		}
		cout << endl;
	}

	delete [] a;
	for (i = 0; i < m; i++) {
		delete [] matrix[i];
	}
	delete [] matrix;
	return 0;

}
