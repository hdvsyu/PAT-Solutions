#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

map<string, int> si;
vector<string> itos(200);
int happiness[200], cities[200][200], isVisited[200];
int routes, final_cost = 100000, final_happiness = 1000000, final_unit = 100000;
vector<int> final_path;

void dfs (int cur, int dest, int cost, int happy, int unit, vector<int> path, int n) {
    if (cur == dest) {
        if (cost < final_cost) {
            final_cost = cost;
            final_unit = unit;
            final_happiness = happy;
            routes = 1;
            final_path = path;
        } else if (cost == final_cost) {
            routes += 1;
            if (happy > final_happiness) {
                final_happiness = happy;
                final_unit = unit;
                final_path = path;
            } else if (happy == final_happiness) {
                if (happy / unit > final_happiness / final_unit) {
                    final_unit = unit;
                    final_path = path;
                }
            }
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!isVisited[i] && cities[cur][i] != 0) {
            isVisited[i] = true;
            path.push_back(i);
            dfs(i, dest, cost + cities[cur][i], happy + happiness[i], unit + 1, path, n);
            path.pop_back();
            isVisited[i] = false;
        }
    }
}

void printPath () {
    cout << itos[final_path[0]];
    for (int i = 1; i < final_path.size(); i++) {
        cout << "->" << itos[final_path[i]];
    }
}

int main () {
    int n = 0, k = 0;
    string s;
    cin >> n >> k >> s;
    si[s] = 0;
    itos[0] = s;
    for (int i = 1; i < n; i++) {
        cin >> s >> happiness[i];
        si[s] = i;
        itos[i] = s;
    }
    for (int i = 0; i < k; i++) {
        string a, b;
        cin >> a >> b;
        cin >> cities[si[a]][si[b]];
        cities[si[b]][si[a]] = cities[si[a]][si[b]];
    }
    
    isVisited[0] = true;
    vector<int> path;
    path.push_back(0);
    dfs (0, si["ROM"], 0, 0, 0, path, n);
    cout << routes << " " << final_cost << " " << final_happiness << " " << (final_happiness / final_unit) << endl;
    printPath();
    return 0;
}