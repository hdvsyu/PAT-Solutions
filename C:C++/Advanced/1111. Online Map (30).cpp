#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 500;

struct City {
    int dis, time;
}cities[MAX][MAX];

int dis[MAX], collect[MAX], n, disPath[MAX], disTime[MAX], tt[MAX], timePath[MAX], timeUnit[MAX];
vector<int> final_dis_path, final_time_path;

int getIndexForDistance () {
    int index = -1, i = 0;
    for (i = 0; i < n; i++) {
        if (!collect[i]) {
            index = i;
            break;
        }
    }
    for (i += 1; i < n; i++) {
        if (!collect[i] && dis[i] < dis[index]) {
            index = i;
        }
    }
    return index;
}

int getIndexForTime () {
    int index = -1, i = 0;
    for (i = 0; i < n; i++) {
        if (!collect[i]) {
            index = i;
            break;
        }
    }
    for (i += 1; i < n; i++) {
        if (!collect[i] && tt[i] < tt[index]) {
            index = i;
        }
    }
    return index;
}

void dijkstraForTime (int s) {
    fill(tt, tt + MAX, 65536);
    fill(collect, collect + MAX, 0);
    tt[s] = 0; timeUnit[s] = 0;
    
    for (int i = 0; i < n; i++) {
        timePath[i] = i;
    }
    while (true) {
        s = getIndexForTime();
        if (s == -1) break;
        collect[s] = 1;
        for (int i = 0; i < n; i++) {
            if (!collect[i] && cities[s][i].time != 0) {
                if (tt[i] > tt[s] + cities[s][i].time) {
                    tt[i] = tt[s] + cities[s][i].time;
                    timePath[i] = s;
                    timeUnit[i] = timeUnit[s] + 1;
                } else if (tt[i] == tt[s] + cities[s][i].time && timeUnit[i] > timeUnit[s] + 1) {
                    timePath[i] = s;
                    timeUnit[i] = timeUnit[s] + 1;
                }
            }
        }
    }
}

void dijkstraForDistance (int s) {
    fill(dis, dis + MAX, 65536);
    fill(collect, collect + MAX, 0);
    dis[s] = 0; disTime[s] = 0;
    
    for (int i = 0; i < n; i++) {
        disPath[i] = i;
    }
    while (true) {
        s = getIndexForDistance();
        if (s == -1) break;
        collect[s] = 1;
        for (int i = 0; i < n; i++) {
            if (!collect[i] && cities[s][i].dis != 0) {
                if (dis[i] > dis[s] + cities[s][i].dis) {
                    dis[i] = dis[s] + cities[s][i].dis;
                    disPath[i] = s;
                    disTime[i] = disTime[s] + cities[s][i].time;
                } else if (dis[i] == dis[s] + cities[s][i].dis && disTime[i] > disTime[s] + cities[s][i].time) {
                    disPath[i] = s;
                    disTime[i] = disTime[s] + cities[s][i].time;
                }
            }
        }
    }
}

void getDisPath (int s, int e) {
    if (s == e) {
        final_dis_path.push_back(s);
        return;
    }
    getDisPath(s, disPath[e]);
    final_dis_path.push_back(e);
}

void getTimePath (int s, int e) {
    if (s == e) {
        final_time_path.push_back(s);
        return;
    }
    getTimePath(s, timePath[e]);
    final_time_path.push_back(e);
}

void printTimePath () {
    printf("%d", final_time_path[0]);
    for (int i = 1; i < final_time_path.size(); i++) {
        printf(" -> %d", final_time_path[i]);
    }
}

void printDisPath () {
    printf("%d", final_dis_path[0]);
    for (int i = 1; i < final_dis_path.size(); i++) {
        printf(" -> %d", final_dis_path[i]);
    }
}

int main() {
    int m = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v1 = 0, v2 = 0, oneWay = 1;
        scanf("%d %d %d", &v1, &v2, &oneWay);
        scanf("%d %d", &cities[v1][v2].dis, &cities[v1][v2].time);
        if (!oneWay) {
            cities[v2][v1] = cities[v1][v2];
        }
    }
    int s = 0, e = 0;
    scanf("%d %d", &s, &e);
    dijkstraForDistance(s);
    getDisPath(s, e);
    dijkstraForTime(s);
    getTimePath(s, e);
    
    if (final_dis_path != final_time_path) {
        printf("Distance = %d: ", dis[e]);
        printDisPath();
        printf("\n");
        printf("Time = %d: ", tt[e]);
        printTimePath();
        
    } else {
        printf("Distance = %d; Time = %d: ", dis[e], tt[e]);
        printTimePath();
    }
    return 0;
}