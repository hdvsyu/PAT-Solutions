#include <cstdio>
#include <vector>

using namespace std;

// MAX表示边界，path是用作dfs的临时路径，finalPath是更新之后的最终路径
// subway是地铁图
// minCnt是经过站的最少次数，minTranf是换成的最少次数，line是图中两点的地铁线号，isVisited是dfs用的标记
const int MAX = 10010;
vector<int> path, finalPath;
vector<vector<int> > subway(MAX);
int minCnt = MAX, minTranf = MAX, line[MAX][MAX], isVisited[MAX];

// 打印换成路径
void printTrace() {
    printf("%d\n", minCnt);
    int sourceIndex = 0, preLine = line[finalPath[0]][finalPath[1]];
    for (int i = 1; i < finalPath.size(); i++) {
        int tempLine = line[finalPath[i - 1]][finalPath[i]];
        if (tempLine != preLine) {
            printf("Take Line#%d from %04d to %04d.\n", preLine, finalPath[sourceIndex], finalPath[i - 1]);
            sourceIndex = i - 1;
            preLine = tempLine;
        }
    }
    printf("Take Line#%d from %04d to %04d.\n", preLine, finalPath[sourceIndex], finalPath[finalPath.size() - 1]);
}

// 获取换乘的次数
int getTransf(vector<int> a) {
    int cnt = 0, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        int tempLine = line[a[i - 1]][a[i]];
        if (preLine != tempLine) {
            cnt++;
            preLine = tempLine;
        }
    }
    return cnt;
}

// 深搜所有的路径，找到目的点的时候，记录将满足题目限制的路径
void dfs(int current, int dest, int cnt) {
    if (dest == current) {
        int tempMinTransf = getTransf(path);
        if (cnt < minCnt || (cnt == minCnt && tempMinTransf < minTranf)) {
            minCnt = cnt;
            finalPath = path;
            minTranf = tempMinTransf;
        }
        return;
    }
    for (int i = 0; i < subway[current].size(); i++) {
        int temp = subway[current][i];
        if (!isVisited[temp]) {
            isVisited[temp] = true;
            path.push_back(temp);
            dfs(temp, dest, cnt + 1);
            path.pop_back();
            isVisited[temp] = false;
        }
    }
}

int main() {
    int n = 0, k = 0, m = 0, pre = 0, temp = 0, source = 0, dest = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            line[temp][pre] = line[pre][temp] = i;
            subway[pre].push_back(temp);
            subway[temp].push_back(pre);
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &source, &dest);
        minCnt = MAX;
        isVisited[source] = true;
        path.push_back(source);
        dfs(source, dest, 0);
        printTrace();
        path.clear();
        isVisited[source] = false;
        finalPath.clear();
    }
    return 0;
}
