#include <string>
#include <iostream>
#include <map>
#include <set>

using namespace std;

void print_ids(set<int> &ids) {
    bool flag = false;
    for (auto it = ids.begin(); it != ids.end(); it++) {
        printf("%07d\n", *it);
        flag = true;
    }
    if (!flag) printf("Not Found\n");
}

int main () {
    int n = 0, m = 0, k = 0, id = 0, publish_year = 0;
    string title, author, publisher, keyword;
    scanf("%d", &n);
    map<string, set<int>> author_m, title_m, publisher_m, publish_year_m, keyword_m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        getchar();
        getline(cin, title);
        getline(cin, author);
        while (cin >> keyword) {
            keyword_m[keyword].insert(id);
            if (getchar() == '\n') break;
        }
        getline(cin, publisher);
        scanf("%d", &publish_year);
        author_m[author].insert(id);
        title_m[title].insert(id);
        publisher_m[publisher].insert(id);
        publish_year_m[to_string(publish_year)].insert(id);
    }
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d: ", &k);
        string str;
        getline(cin, str);
        printf("%d: %s\n", k, str.c_str());
        if (k == 1) {
            print_ids(title_m[str]);
        } else if (k == 2) {
            print_ids(author_m[str]);
        } else if (k == 3) {
            print_ids(keyword_m[str]);
        } else if (k == 4) {
            print_ids(publisher_m[str]);
        } else {
            print_ids(publish_year_m[str]);
        }
     }
    
    return 0;
}
