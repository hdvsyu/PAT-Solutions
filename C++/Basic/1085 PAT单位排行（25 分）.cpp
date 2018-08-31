#include <cstdio>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>

using namespace std;

struct department {
    string school;
    int score, cnt;
    department() {}
    department(string _school, int _score, int _cnt): school(_school), score(_score), cnt(_cnt) {}
};

bool cmp(department a, department b) {
    return a.score == b.score ? (a.cnt == b.cnt ? a.school < b.school : a.cnt < b.cnt) : a.score > b.score;
}

string to_lower(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (isupper(s[i])) s[i] += 32;
    }
    return s;
}


int main() {
    char id[10], school[10];
    int score = 0, n = 0, idx = 0, rank = 1;
    scanf("%d", &n);
    map<string, double> m;
    map<string, int> m_cnt;
    for (int i = 0; i < n; i++) {
        scanf("%s %d %s", id, &score, school);
        string s = to_lower(school);
        m_cnt[s]++;
        if (id[0] == 'T') {
            m[s] += score * 1.5;
        } else if (id[0] == 'A') {
            m[s] += score;
        } else if (id[0] == 'B') {
            m[s] += score / 1.5;
        }
    }
    
    department departments[100010];
    for (auto it = m.begin(); it != m.end(); it++) {
        departments[idx++] = department(it->first, (int)it->second, m_cnt[it->first]);
    }
    sort(departments, departments + m.size(), cmp);
    printf("%lu\n", m.size());
    for (int i = 0; i < m.size(); i++) {
        if (i >= 1 && departments[i - 1].score != departments[i].score) {
            rank = i+1;
        }
        printf("%d %s %d %d\n", rank, departments[i].school.c_str(), departments[i].score, departments[i].cnt);
    }
    return 0;
}
