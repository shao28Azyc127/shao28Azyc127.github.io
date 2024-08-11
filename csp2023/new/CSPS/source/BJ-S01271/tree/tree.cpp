#include<iostream>
#include<queue>
#define ll long long
using namespace std;


ll n;
ll a[100005], b[100005], c[100005], u[1005][1005], h[100005];
bool m[100005];
queue<ll> q;



void bfs(ll x, ll day){
    ll node = q.front();
    q.pop();
    for (int i = )
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;i ++){
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1;i <= n - 1;i ++){
        ll x, y;
        cin >> x >> y;
        u[x][y] = 1;
        u[y][x] = 1;
    }
    m[1] = 1;
    h[1] = max(b[1] + c[1], 1);
    q.push(1);
    bfs(1, 1);
    return 0;
}
