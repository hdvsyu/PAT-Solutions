#include <iostream>
#include <string>
#include <set>
#include <cctype>

using namespace std;

int main() {
	string badKeyInput, testKey;

	getline(cin, badKeyInput);
	getline(cin, testKey);
	// cin >> badKeyInput >> testKey;

	// 判断上档键是否在坏掉的键盘里面
	bool noShiftKey = true;
	set<char> s; // 将坏掉的键放入散列表里面，方便查找
	for (int i = 0; i < badKeyInput.length(); i++) {
		char c = badKeyInput[i];
		if (c == '+') {
			noShiftKey = false;
		}
		s.insert(c);
		s.insert(tolower(c));
	}

	if (noShiftKey) {
		// 上档键不在坏掉的键里面，可以输出大写的
		for (int i = 0; i < testKey.length(); i++) {
			char c = testKey[i];
			if (s.count(c) == 0) {
				cout << c;
			}
		}
	} else {
		// 上档键在坏掉的键，如果是大写的，则不输出
		for (int i = 0; i < testKey.length(); i++) {
			char c = testKey[i];
			if (!isupper(c)) {
				if (s.count(c) == 0) {
					cout << c;
				}
			}
		}
	}

	return 0;
}
