#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

struct student {
    char id[7];
    int score[4], rank[4];
};

bool cmp_0(student a, student b) {
    return a.score[0] > b.score[0];
}

bool cmp_1(student a, student b) {
    return a.score[1] > b.score[1];
}

bool cmp_2(student a, student b) {
    return a.score[2] > b.score[2];
}

bool cmp_3(student a, student b) {
    return a.score[3] > b.score[3];
}

void print_rank (student s) {
    int rank = s.rank[0], index = 0;
    for (int i = 1; i <= 3; i++) {
        if (rank > s.rank[i]) {
            index = i;
            rank = s.rank[i];
        }
    }
    printf("%d ", rank);
    switch (index) {
        case 0:printf("A\n");
            break;
        case 1:printf("C\n");
            break;
        case 2:printf("M\n");
            break;
        case 3:printf("E\n");
            break;
    }
}

int main () {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    struct student *students = new struct student[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", students[i].id, &students[i].score[1], &students[i].score[2], &students[i].score[3]);
        students[i].score[0] = (students[i].score[1] + students[i].score[2] + students[i].score[3]) / 3.0 + 0.5;
    }
    
    
    // sort by C Programming Language
    sort(students, students + n, cmp_1);
    for (int i = 0; i < n; i++) {
        students[i].rank[1] = i + 1;
        if (i != 0 && students[i].score[1] == students[i - 1].score[1]) {
            students[i].rank[1] = students[i - 1].rank[1];
        }
    }
    
    // sort by Mathematics
    sort(students, students + n, cmp_2);
    for (int i = 0; i < n; i++) {
        students[i].rank[2] = i + 1;
        if (i > 0 && students[i].score[2] == students[i - 1].score[2]) {
            students[i].rank[2] = students[i - 1].rank[2];
        }
    }
    
    // sort by English
    sort(students, students + n, cmp_3);
    for (int i = 0; i < n; i++) {
        students[i].rank[3] = i + 1;
        if (i > 0 && students[i].score[3] == students[i - 1].score[3]) {
            students[i].rank[3] = students[i - 1].rank[3];
        }
    }
    
    // sort by Average
    sort(students, students + n, cmp_0);
    map<string, int> position;
    for (int i = 0; i < n; i++) {
        position[students[i].id] = i + 1;
        students[i].rank[0] = i + 1;
        if (i > 0 && students[i].score[0] == students[i - 1].score[0]) {
            students[i].rank[0] = students[i - 1].rank[0];
        }
    }
    
    for (int i = 0; i < m; i++) {
        char id[7];
        scanf("%s", id);
        if (position[id] == 0) {
            printf("N/A\n");
        } else {
            print_rank(students[position[id] - 1]);
        }
    }
    delete [] students;
    return 0;
}
