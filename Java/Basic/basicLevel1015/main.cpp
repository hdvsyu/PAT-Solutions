#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
 
using namespace std;
 
struct Stu {
    string id;
    int de;
    int cai;
};
 
bool cmp (struct Stu s1, struct Stu s2) {
    if ((s1.de + s1.cai) > (s2.de + s2.cai)) {
        return true;
    } else if ((s1.de + s1.cai) == (s2.de + s2.cai)){
        if(s1.de > s2.de) {
            return true;
        } else if (s1.de == s2.de){
            return s1.id < s2.id;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
 
int main() {
    int n = 0, l = 0, h = 0;
    cin >> n>> l>> h;
    vector<struct Stu> v1;
    vector<struct Stu> v2;
    vector<struct Stu> v3;
    vector<struct Stu> v4;
    for (int i = 0; i < n; i++) {
        struct Stu temp;
        cin >> temp.id;
        scanf("%d %d", &temp.de, &temp.cai);
         
        if (temp.de >= l && temp.cai >= l) {
            if (temp.de >= h && temp.cai >= h) {
                v1.push_back(temp);
            } else if (temp.de >= h) {
                v2.push_back(temp);
            } else if (temp.de < h && temp.cai < h && temp.de >= temp.cai) {
                v3.push_back(temp);
            } else {
                v4.push_back(temp);
            }
        }
    }
     
    cout << (v1.size() + v2.size() + v3.size() + v4.size()) << endl;
     
    sort(v1.begin(), v1.end(), cmp);
    for(int i = 0; i < v1.size(); i++) {
        cout << v1[i].id << " ";
        printf("%d %d\n", v1[i].de, v1[i].cai);
    }
    sort(v2.begin(), v2.end(), cmp);
    for(int i = 0; i < v2.size(); i++) {
        cout << v2[i].id << " ";
        printf("%d %d\n", v2[i].de, v2[i].cai);
    }
    sort(v3.begin(), v3.end(), cmp);
    for(int i = 0; i < v3.size(); i++) {
        cout << v3[i].id << " ";
        printf("%d %d\n", v3[i].de, v3[i].cai);
    }
    sort(v4.begin(), v4.end(), cmp);
    for(int i = 0; i < v4.size(); i++) {
        cout << v4[i].id << " ";
        printf("%d %d\n", v4[i].de, v4[i].cai);
    }
    return 0;
}