#include <iostream>
#include <set>
#include <map>
#include <cstring>

using namespace std;

int main() {
    char s[12];
    scanf("%s", s);
    set<int> arr;
    for (int i = 0; i < 11; i++) {
        arr.insert(s[i] - '0');
    }
    map<int, int> m;
    int i = 0, flag = 0;;
    printf("int[] arr = new int[]{");
    for (auto it = arr.rbegin(); it != arr.rend(); it++, i++) {
        m[*it] = i;
        if (flag) printf(",");
        flag = 1;
        printf("%d", *it);
        
    }
    flag = 0;
    printf("};\nint[] index = new int[]{");
    for (int j = 0; j < strlen(s); j++) {
        if (flag) printf(",");
        flag = 1;
        printf("%d", m[s[j] - '0']);
        
    }
    printf("};");
    return 0;
}
