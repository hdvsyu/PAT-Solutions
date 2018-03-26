#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cctype>

using namespace std;

string tolow(string name) {
    for (int i = 0; i < name.size(); i++)
        if (isupper(name[i]))
            name[i] = tolower(name[i]);
    return name;
}

struct school {
    string name;
    int tws, ns;
}schools[100010];

int main() {
    int n = 0, score = 0, rank = 1, index = 0;
    scanf("%d", &n);
    char id[8], name[8];
    map<string, double> mtws;
    map<string, int> mns;
    for (int i = 0; i < n; i++) {
        scanf("%s %d %s", id, &score, name);
        string lowname = tolow(name);
        if (id[0] == 'A') {
            mtws[lowname] += score;
        } else if (id[0] == 'B') {
            mtws[lowname] += score / 1.5;
        } else if (id[0] == 'T') {
            mtws[lowname] += score * 1.5;
        }
        mns[lowname]++;
    }
    printf("%lu\n", mtws.size());
    for (auto it = mtws.begin(); it != mtws.end(); it++) {
        schools[index++] = school{ it->first, (int)it->second, mns[it->first]};
    }
    sort(schools, schools + index, [](school a, school b){
        return a.tws == b.tws ? (a.ns == b.ns ? a.name < b.name : a.ns < b.ns ) : a.tws > b.tws ;
    });
    for (int i = 0; i < index; i++) {
        if (i > 0 &&  schools[i].tws != schools[i-1].tws)
            rank = i+1;
        printf("%d %s %d %d\n", rank, schools[i].name.c_str(), schools[i].tws, schools[i].ns);
    }
    return 0;
}
