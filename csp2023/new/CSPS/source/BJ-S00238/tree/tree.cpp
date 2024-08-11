#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005],b[100005],c[100005],now[100005],day;
long long nxt[100005];
bool f[100005];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        nxt[u]=v;
    }
    nxt[0]=1;
    int u=0;
    bool fl=false;
    while(!fl){
        day++;
        f[nxt[u]]=true;
        u=nxt[u];
        fl=true;
        for(int i=1;i<=day;i++){
            now[i]+=max((long long)1,b[i]+day*c[i]);
        }
        for(int i=1;i<=n;i++){
            if(now[i]<a[i]){
                fl=false;
            }
        }
    }
    cout<<day;
    return 0;
}

