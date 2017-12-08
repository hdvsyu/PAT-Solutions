#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int inf = 65535;

map<string, int> s_to_i; // 把城镇名映射为一个数字
map<int, string> i_to_s; // 把数字映射位一个城镇名

bool visited[210]; // 标记一个顶点是否已经访问，已经访问置true
int ans_len = inf, ans_kill = -1, defend[210], ans_path_cnt = 0, city_map[210][210];; // ans_len 表示保存是距离最短长度，ans_kill 保存的是杀敌数量最多的，defend数组是每一个城镇的守卫数量，ans_path_cnt是距离最短路径的数目，city_map是图的邻接矩阵表示
deque<int> ans_p; // ans_p保存一个路径的访问次序

// cur 表示当前正在访问的节点下标，e表示敌方大本营，n是整个图的顶点数目，len是从起点到当前点的距离，kill是从起点到当前点的杀敌数量，p是访问的路径
void dfs(int cur, int e, int n, int len, int kill, deque<int> p) {
    if (cur == e) { // 当访问到敌方大本营时
        if (len < ans_len) { // 距离比保存的还要短，则更新距离，杀敌数量，访问次序并把
            ans_len = len;
            ans_kill = kill;
            ans_p = p;
            ans_path_cnt = 1;
        } else if (len == ans_len) {
            ans_path_cnt++;
            if (p.size() > ans_p.size()) {
                ans_kill = kill;
                ans_p = p;
            } else if (p.size() == ans_p.size()) {
                if (kill > ans_kill) {
                    ans_kill = kill;
                    ans_p = p;
                }
            }
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && city_map[cur][i] != inf) {
            visited[i] = true;
            p.push_back(i);
            dfs(i, e, n, len + city_map[cur][i], kill + defend[i], p);
            p.pop_back();
            visited[i] = false;
        }
    }
}

void init(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            city_map[i][j] = inf;
        }
    }
}

void printAns() {
    printf("%s", i_to_s[0].c_str());
    while (!ans_p.empty()) {
        printf("->%s", i_to_s[ans_p.front()].c_str());
        ans_p.pop_front();
    }
    printf("\n%d %d %d\n", ans_path_cnt, ans_len, ans_kill);
}

int main() {
    int n = 0, k = 0, l = 0;
    char own[4], enemy[4], town[4], city1[4], city2[4];
    scanf("%d %d %s %s", &n, &k, own, enemy);
    init(n);
    s_to_i[own] = 0; i_to_s[0] = own;
    for (int i = 1; i < n; i++) {
        scanf("%s %d", town, &defend[i]);
        s_to_i[town] = i; i_to_s[i] = town; // 根据城镇出现的次序，用map来做一一映射
    }
    
    for (int i = 0; i < k; i++) {
        scanf("%s %s %d", city1, city2, &l);
        city_map[s_to_i[city1]][s_to_i[city2]] = city_map[s_to_i[city2]][s_to_i[city1]] = l;
    }
    
    deque<int> p;
    visited[0] = true;
//    dfs(int cur, int e, int n, int len, int kill, deque<int> p) 下方函数的调用对应参数
    dfs(0, s_to_i[enemy], n, 0, 0, p);
    printAns();
    return 0;
}
