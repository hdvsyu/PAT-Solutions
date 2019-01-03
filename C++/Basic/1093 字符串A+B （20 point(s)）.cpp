#include <iostream>
#include <string>

using namespace std;

int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  int visit[200] = {0};
  for (auto it : a + b) {
    if (visit[it] == 0) cout << it;
    visit[it] = 1;
  }
  return 0;
}