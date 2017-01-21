#include <iostream>
#include <algorithm>

using namespace std;

struct Mooncake {
	double memory;
	double sale;
	double price;
};

int cmp(Mooncake a, Mooncake b) {
	if (a.price > b.price) {
		return 1;
	}

	if (a.price < b.price) {
		return -1;
	}

	return 0;
}


int main() {
	int n = 0, d = 0;
	double p = 0;

	cin >> n >> d;
		
	Mooncake *mooncakes = new Mooncake[n];
	for (int i = 0; i < n; i++) {
		cin >> mooncakes[i].memory;
	}
	
	for (int i = 0; i < n; i++) {
		cin >> mooncakes[i].sale;
		mooncakes[i].price = mooncakes[i].sale / mooncakes[i].memory;
	}
	
	for (int i = 0; i < n; i++) {
		cout << mooncakes[i].price << endl;
	}


	sort(mooncakes, mooncakes + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << mooncakes[i].price << endl;
	}

	double total = 0;
	for (int i = 0; i < n; i++) {
		if (d - mooncakes[i].memory >= 0) {
			total += mooncakes[i].sale;
			d -= mooncakes[i].memory;
		} else {
			total += mooncakes[i].price * d;
			break;
		}
	}

	printf("%.2f", total);
}