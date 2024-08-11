#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int cas, T; int m;
int n;
struct Node{
    int op, v;
    Node(int opop = 0, int vv = 0){
        op = opop; v = vv;
    }
};
Node t[maxn];
int fa[maxn << 1];
int fl[maxn << 1];
void init(){
    for(int i = 1;i <= n + n;i++){
        fa[i] = i; fl[i] = 0;
    }
    return ;
}
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y){
    fa[find(x)] = find(y); return ;
}
int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> cas >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            t[i] = Node(1, i);
        }
        for(int i = 1;i <= m;i++){
            char opt; cin >> opt;
            if(opt == '+'){
                int x, y; cin >> x >> y;
                t[x] = t[y];
            } else if(opt == '-'){
                int x, y; cin >> x >> y;
                t[x] = (t[y].op == 0 ? Node(0, (3 - t[y].v) % 3) : Node(3 - t[y].op, t[y].v));
            } else {
                int x; cin >> x;
                t[x] = Node(0, (opt == 'U' ? 0 : (opt == 'T' ? 1 : 2)));
            }
        }
        init();
        for(int i = 1;i <= n;i++){
            // cerr << "? " << i << " " << t[i].op << " " << t[i].v << endl;
            if(t[i].op == 1){
                merge(i, t[i].v); merge(n + i, n + t[i].v);
            } else if(t[i].op == 2){
                merge(n + i, t[i].v); merge(i, n + t[i].v);
            }
        }
        for(int i = 1;i <= n;i++){
            if(t[i].op == 0 && t[i].v == 0){
                fl[find(i)] = 1; fl[find(n + i)] = 1;
            }
            if(find(i) == find(n + i)){
                fl[find(i)] = 1;
            }
        }
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(fl[find(i)] || fl[find(n + i)]) cnt++;
        }
        cout << cnt << '\n';
    }
    cout.flush(); return 0;
}
