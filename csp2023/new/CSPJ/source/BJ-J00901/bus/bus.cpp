#include<bits/stdc++.h>
using namespace std;
int n,u[2005],v[2005],a[2005],m,i=1,k;
double x,y;
struct node{
    int nxt[2005],cnt,key;
}s[1005];
void dfs(int t){
    if (i == n && t % k == 0) {
        cout << t;return;
    }
    else if (i == n) return;
    if (1){
        for (int j=1;j<=s[i].cnt;j++){
            i=s[i].nxt[j];
            dfs(t+1);
            i=s[i].key;
        }
    }
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        cin >> u[i] >> v[i] >> a[i];
        s[u[i]].cnt++;
        s[u[i]].key = i;
        s[u[i]].nxt[s[u[i]].cnt]=v[i];
    }
    dfs(0);
    return 0;
}