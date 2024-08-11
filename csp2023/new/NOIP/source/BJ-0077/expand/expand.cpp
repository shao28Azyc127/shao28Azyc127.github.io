#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2005;
int v[maxn][maxn];
int x00[maxn], y00[maxn];
int x[maxn], y[maxn];
#define pii pair<int,int>
#define mp make_pair
struct Queue{
    pii a[maxn*maxn]; int top=0;
    pii pop(){
        return a[--top];
    }
    void push(pii x){
        a[top++] = x;
    }
}qu;
inline bool check(int i, int j, int n, int m, int q){
    if(i < n && j < m && (v[i][j] != q) && ((x[i] - y[j]) * (x[0] - y[0]) > 0)){
        v[i][j] = q;
        return 1;
    }
    return 0;
}
bool run(int n, int m, int q){
    qu.top = 0;
    if((x[0] - y[0]) * (x[n-1] - y[m-1]) <= 0) return 0;
    qu.push(mp(0, 0));
    while(qu.top){
        pii a = qu.pop();
        int x = a.first, y = a.second;
        //cout<<x<<" "<<y<<" "<<q<<endl;
        if(check(x+1,y+1,n,m,q)) {if(x+1==n-1&&y+1==m-1)return 1; qu.push(mp(x+1,y+1));}
        if(check(x+1,y,n,m,q)) {if(x+1==n-1&&y==m-1)return 1; qu.push(mp(x+1,y));}
        if(check(x,y+1,n,m,q)) {if(x==n-1&&y+1==m-1)return 1; qu.push(mp(x,y+1));}
    }
    return 0;
}
signed main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    for(int i=0;i<n;i++)cin>>x00[i];
    for(int i=0;i<m;i++)cin>>y00[i];
    memcpy(x, x00, sizeof(x00));
    memcpy(y, y00, sizeof(y00));
    cout<<run(n, m, 1);
    for(int i=0;i<q;i++){
        memcpy(x, x00, sizeof(x00));
        memcpy(y, y00, sizeof(y00));
        int kx, ky;
        cin>>kx>>ky;
        for(int j=0;j<kx;j++){
            int p, v;
            cin>>p>>v;
            p--;
            x[p] = v;
        }
        for(int j=0;j<ky;j++){
            int p, v;
            cin>>p>>v;
            p--;
            y[p] = v;
        }
        cout<<run(n, m, i+2);
    }
    cout<<endl;
    return 0;
}
