#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

struct edge{
    int to;
    int et;
};

struct node{
    int pt;
    int dis;
};

vector <edge> graphx[10001];
bool visited[10001];
int n, k;

int bfs(){
    queue <node> q;
    q.push({1,0});
    while (!q.empty()){
        node tp = q.front();
        q.pop();
        int curpt = tp.pt;
        int curdis = tp.dis;
        if (curpt == n){
            return curdis;
        }
        visited[curpt] = true;
        for (edge x:graphx[curpt]){
            if (visited[x.to] == true){
                continue;
            }
            if (x.et <= curdis){
                q.push({x.to,curdis+1});
            }
        }
    }
    return -1;
}

int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int m;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int a, b, v;
        cin >> a >> b >>v;
        edge tmp;
        tmp.to = b;
        tmp.et = v;
        graphx[a].push_back(tmp);
    }
    int ans = bfs();
    cout << ans + (k-(ans%k));
    return 0;
}

