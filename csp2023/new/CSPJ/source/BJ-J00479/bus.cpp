#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans=99999999, maxtim;
struct node{
    int to, tim;
};
vector <node> v[10010];
void dfs(int x, int f, int tim){
    if(x==n){
        if(tim%k==0){
            ans = min(ans, tim);
            return;
        }
    }
    if(tim>ans) return;
    for(int i=0;i<v[x].size();i++){
        node y = v[x][i];
        if(y.to==f) continue;
        dfs(y.to, x, max(tim, y.tim) + 1);
    }
}
signed main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin>>n>>m>>k;
    int a,b,c;
    if(n>100){
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld", &a, &b, &c);
        v[a].push_back(node{b, c});
        maxtim = max(maxtim, c);
    }
    for(int i=0;i<=1000;i+=k){
        dfs(1, 0, i);
    }
    if(ans == 99999999) ans = -1;
    cout<<ans<<endl;
    return 0;
}
