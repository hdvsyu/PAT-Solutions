#include <iostream>

using namespace std;

struct People {
    string name;
    int year;
    int month;
    int day;
};

bool isValid(struct People p) {
    if (p.year > 2014 || p.year < 1814) {
        return false;
    } else {
        if (p.year == 2014) {
            if (p.month < 9) {
                return true;
            } else if (p.month > 9) {
                return false;
            } else {
                if (p.day <= 6) {
                    return true;
                } else{
                    return false;
                }
            }
        } else if (p.year == 1814) {
            if (p.month > 9) {
                return true;
            } else if (p.month < 9) {
                return false;
            } else {
                if (p.day >= 6) {
                    return true;
                } else {
                    return false;
                }
            }
        } else {
            return true;
        }
    }
}

int compare(struct People man1, struct People man2) {
    if (man1.year < man2.year) {
        return 1;
    } else if (man1.year == man2.year){
        if (man1.month < man2.month) {
            return 1;
        } else if (man1.month == man2.month) {
            if (man1.day < man2.day) {
                return 1;
            } else if (man1.day == man2.day) {
                return 0;
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

int main() {
    int n = 0;
    cin >> n;
    int valid = 0;
    struct People max, min;
    max.year = 2014; max.month = 9; max.day = 6;
    min.year = 1814; min.month = 9; min.day = 6;
    for (int i = 0; i < n; i++) {
        struct People p;
        cin >> p.name;
        scanf("%d/%d/%d", &p.year, &p.month, &p.day);
        
        if (isValid(p)) {
            max = compare(max, p) > 0 ? max : p;
            min = compare(p, min) > 0 ? min : p;
            valid++;
        }
    }
    
    if (valid != 0){
        cout << valid << " " << max.name << " " << min.name << endl;
    } else {
        cout << 0;
    }
    return 0;
}