#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
		
	int *states = new int[3];	
	int JB = 0, JC = 0, JJ = 0;
	int YB = 0, YC = 0, YJ = 0;
	for (int i = 0; i < n; i++) {
		char a, b;
		cin >> a >> b;			
		if (a == 'B') {
			if (b == 'B') {
				states[1]++;
			} else if (b == 'C') {
				states[0]++;
				JB++;
			} else {
				states[2]++;
				YJ++;
			}
		} else if (a == 'C') {
			if (b == 'B') {
				states[2]++;
				YB++;
			} else if (b == 'C') {
				states[1]++;
			} else {
				states[0]++;
				JC++;
			}
		} else {
			// a == 'J'
			if (b == 'B') {
				states[0]++;
				JJ++;
			} else if (b == 'C') {
				states[2]++;
				YC++;
			} else {
				states[1]++;
			}
		}
	}
		
	cout << states[0] << " " << states[1] << " " << states[2] << endl;
	cout << states[2] << " " << states[1] << " " << states[0] << endl;
		
	int max = JB;
	char symbol = 'B';
	if (max < JC) {
		max = JC;
		symbol = 'C';
	} 
	if (max < JJ) {
		symbol = 'J';
	}
		
	cout << symbol << " ";
		
	max = YB;
	symbol = 'B';
	if (max < YC) {
		symbol = 'C';
		max = YC;
	}
	if (max < YJ) {
		symbol = 'J';
	}
	cout << symbol;
	
	return 0;
	
}