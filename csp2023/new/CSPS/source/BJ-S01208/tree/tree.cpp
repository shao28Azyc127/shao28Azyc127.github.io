#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e5+7;
const int Mmax=2e3+7;
int n;
long long a[Nmax],b[Nmax],c[Nmax];
long long p[Nmax];
int f[Mmax][Mmax];
int vis[Nmax];
int vvii[Nmax];
int ans;
int main(){
    freopen("tree.in","r",stdin);
    cin>>n;
    long long t=1;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        f[u][v]=1;f[v][u]=1;
    }
    vis[1]=1;
    vvii[1]=1;
    p[1]+=max(b[1]+t*c[1],1ll);
    t++;
    for(int i=2;i<=n;i++){
        long long maax=0;
        int mj=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(k!=j&&vis[j]==0){
                    if(vis[k]==1){
                        maax=max(maax,a[j]);
                        mj=j;
                        break;
                    }
                }
            }
        }
        vis[mj]=1;
        vvii[i]=mj;
        int o=1;
        while(vvii[o]!=0){
            p[vvii[o]]+=max(b[vvii[o]]+t*c[vvii[o]],1ll);
            o++;
        }
        t++;
        for(int e=1;e<=n;e++){
            if(p[e]>=a[e])ans++;
        }
        if(ans==n){
            break;
        }
        else{
            ans=0;
        }
    }
    freopen("tree.out","w",stdout);
    cout<<t;
    return 0;
}
