#include <iostream>

using namespace std;

int main() {
    int *score = new int [101];
    int n = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        score[temp]++;
    }
    int k = 0;
    cin >> k;
    for (int i = 0; i < k-1; i++) {
        int temp = 0;
        cin >> temp;
        cout << score[temp] << " ";
    }
    int temp = 0;
    cin >> temp;
    cout << score[temp];

    delete [] score;
    
}
