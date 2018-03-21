#include <cstdio>
#include <string>

int main() {
    int m = 0, hh = 0, mm = 0, ss = 0, earily = 99999999, later = 0;
    char s[20];
    scanf("%d", &m);
    std::string e, l;
    for (int i = 0; i < m; i++) {
        scanf("%s %d:%d:%d", s, &hh, &mm, &ss);
        if (hh * 3600 + mm * 60 + ss < earily) {
            earily = hh * 3600 + mm * 60 + ss;
            e = s;
        }
        scanf("%d:%d:%d", &hh, &mm, &ss);
        if (hh * 3600 + mm * 60 + ss > later) {
            later = hh * 3600 + mm * 60 + ss;
            l = s;
        }
    }
    printf("%s %s", e.c_str(), l.c_str());
    
    return 0;
}
