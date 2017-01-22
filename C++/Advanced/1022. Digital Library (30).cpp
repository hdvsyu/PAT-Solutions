#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

struct Book {
    string keywords, title, author, publisher, id, year;
};

int cmp (const void *a, const void *b) {
    struct Book arg1 = *static_cast<const struct Book *>(a);
    struct Book arg2 = *static_cast<const struct Book *>(b);
    
    if (arg1.id < arg2.id) return -1;
    if (arg1.id > arg2.id) return 1;
    return 0;
}

void query (const struct Book *books, int k, int n) {
    string str;
    getline(cin, str);
    cout << k << ": " << str << endl;
    bool out = false;
    for (int i = 0; i < n; i++) {
        if (books[i].title == str || books[i].author == str || books[i].publisher == str || books[i].year == str || books[i].keywords.find(str) != std::string::npos) {
            cout << books[i].id << endl;
            out = true;
        }
    }
    if (!out) printf("Not Found\n");
}



int main () {
    int n = 0;
    cin >> n;
    getchar();
    struct Book *books = new struct Book[n];
    for (int i = 0; i < n; i++) {
        getline(cin, books[i].id);
        getline(cin, books[i].title);
        getline(cin, books[i].author);
        getline(cin, books[i].keywords);
        getline(cin, books[i].publisher);
        getline(cin, books[i].year);
    }
    
    qsort(books, n, sizeof(books[0]), cmp);
    
    int m = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k = 0;
        scanf("%d: ", &k);
        query(books, k, n);
    }
    
    delete [] books;
    return 0;
}