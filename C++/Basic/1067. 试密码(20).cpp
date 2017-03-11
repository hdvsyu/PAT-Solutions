#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
    string corretPassowrd;
    int cnt = 0;
    cin >> corretPassowrd >> cnt;
    getchar();
    
    while (true) {
        string attemp;
        getline(cin, attemp);
        if (attemp == "#") {
            break;
        }
        
        if (attemp == corretPassowrd) {
            cout << "Welcome in" << endl;
            break;
        } else {
            cnt--;
            
            cout << "Wrong password: " << attemp << endl;
            if (cnt == 0) {
                cout << "Account locked" << endl;
                break;
            }
        }
    }
    return 0;
}