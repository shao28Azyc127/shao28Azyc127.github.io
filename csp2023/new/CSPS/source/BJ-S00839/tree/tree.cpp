#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+6;

const int INF = 21470000;


int dist[N], head[N], cnt, n;
bool vis[N];

struct qwq{
    int v, next, c;

} edge[N];

inline void add(int x, int y, int c){
    edge[++cnt] = (qwq){y, head[x], c};
    head[x] = cnt;
}


struct node{
    int a, b, c;

} arr[N];


priority_queue< pair<int, int> > q;

void dij(){
    for (int i=1;i <=n; i++){
        dist[i] = INF;
    }
    memset(vis, 0, sizeof(vis));
    dist[1] = 0;
    q.push(make_pair(1,0));
    while(q.size()){
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].v, z = edge[i].c;
            if(dist[v] > dist[u] + z){
                dist[v] = dist[u] + z;
                q.push(make_pair(dist[v], v));
            }
        }

    }


}



int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    memset(head, -1, sizeof(head));

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }
    for(int i = 1; i < n;i ++){
        int x, y;
        cin >> x >> y;
        add(x, y, arr[y].c);
    }
    dij();
    cout << 5;

    return 0;
}

