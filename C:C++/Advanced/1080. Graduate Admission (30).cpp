#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

struct Applicant {
    int ge, gi, final, rank, choices[6], id;
};

int cmp (const void *a, const void *b) {
    struct Applicant arg1 = *static_cast<const Applicant *>(a);
    struct Applicant arg2 = *static_cast<const Applicant *>(b);
    
    if (arg1.final > arg2.final) return -1;
    if (arg1.final < arg2.final) return 1;
    if (arg1.ge > arg2.ge) return -1;
    if (arg1.ge < arg2.ge) return 1;
    return 0;
}

bool cmpId (struct Applicant arg1, struct Applicant arg2) {
    return arg1.id < arg2.id;
}

int main () {
    int n = 0, m = 0, k = 0;
    scanf("%d %d %d", &n, &m, &k);
    int *school = new int[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &school[i]);
    }
    struct Applicant *applications = new struct Applicant[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &applications[i].ge, &applications[i].gi);
        applications[i].final = (applications[i].ge + applications[i].gi) / 2;
        applications[i].id = i;
        for (int j = 0; j < k; j++) {
            scanf("%d", &applications[i].choices[j]);
        }
    }
    
    qsort(applications, n, sizeof(applications[0]), cmp);
    for (int i = 0; i < n; i++) {
        applications[i].rank = i + 1;
        if (i > 0 && cmp(&applications[i], &applications[i - 1]) == 0) {
            applications[i].rank = applications[i - 1].rank;
        }
    }
    vector<vector<struct Applicant> > admission(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int ch = applications[i].choices[j];
            if (admission[ch].size() < school[ch] || (admission[ch].size() >= school[ch] && applications[i].rank == admission[ch][admission[ch].size() - 1].rank)) {
                admission[ch].push_back(applications[i]);
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        sort(admission[i].begin(), admission[i].end(), cmpId);
        for (int j = 0; j < admission[i].size(); j++) {
            if (j != 0) printf(" ");
            printf("%d", admission[i][j].id);
        }
        printf("\n");
    }
    delete [] applications;
    delete [] school;
    return 0;
}