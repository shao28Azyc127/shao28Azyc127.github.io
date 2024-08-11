#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10,T=10000000,F=-10000000,U=10000001,U1=-10000001;

int t,f[N*2],ans,c,n,m,u,v,root[N*2];
bool flag[N*2];
char op;

int qfind(int x){
    if(x==root[x]) return x;
    return root[x]=qfind(root[x]);
}

void qmerge(int x,int y){
    int fx=qfind(x);
    int fy=qfind(y);
    if(fx>fy) swap(fx,fy);
    root[fy]=fx;
    return ;
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    for(;t>=1;t--){
        ans=0;
        memset(flag,0,sizeof(flag));
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            f[i]=i;
        for(int i=0;i<=n+N+1;i++)
            root[i]=i;
        for(int i=1;i<=m;i++){
            cin>>op;
            cin>>u;
            if(op=='T')
                f[u]=T;
            if(op=='F')
                f[u]=F;
            if(op=='U')
                f[u]=U;
            if(op=='+'){
                cin>>v;
                f[u]=f[v];
            }
            if(op=='-'){
                cin>>v;
                f[u]=-f[v];
            }
        }
        for(int i=1;i<=n;i++){
            if(f[i]!=T&&f[i]!=F&&f[i]!=U&&f[i]!=U1){
                qmerge(i+N,f[i]+N);
                qmerge(N-i,N-f[i]);
            }
        }
        for(int i=1;i<=n;i++){
            if(f[i]==U||f[i]==U1)
                flag[qfind(i+N)]=1,flag[qfind(N-i)]=1;
            else if(qfind(i+N)==qfind(N-i))
                flag[qfind(i+N)]=1;
        }
        for(int i=1;i<=n;i++){
            if(flag[qfind(i+N)]) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

