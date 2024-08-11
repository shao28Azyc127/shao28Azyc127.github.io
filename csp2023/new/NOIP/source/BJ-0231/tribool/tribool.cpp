#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,pos,a[100003];
bool flag,b[100003],d[100003];
void DFS(int fa,int u,int tot){
    if(a[u]<=0){
        flag=1;
        if(a[u]==0)a[u]=-1;
        return;
    }

    if(d[u]){
        d[u]=0;
        if(u==fa){
            if(tot%2==1)a[u]=-3;
            else a[u]=-1;
            flag=1;
            return;
        }else{
            pos=u;return;
        }
    }
    if(b[u]){
        d[u]=1,DFS(fa,a[u],tot+1),d[u]=0;
        if(a[u]>0&&flag)a[u]=a[a[u]];
    }
    else{
        d[u]=1,DFS(fa,a[u],tot),d[u]=0;
        if(a[u]>0&&flag)a[u]=a[a[u]];
    }
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int ans=0;
        for(register int i=1;i<=m;++i){
            int x,y;char c;
            cin>>c>>x;
            if(c=='T')a[x]=-1;
            else if(c=='F')a[x]=-2;
            else if(c=='U')a[x]=-3;
            else if(c=='+'){
                cin>>y;
                if(a[y]<0)a[x]=a[y];
                else a[x]=y,b[x]=0;
            }else{
                cin>>y;
                if(a[y]==-3)a[x]=-3;
                else if(a[y]==-2)a[x]=-1;
                else if(a[y]==-1)a[x]=-2;
                else a[x]=y,b[x]=1;
            }
        }
        for(register int i=1;i<=n;++i){
            if(a[i]==-3){++ans;}
            else if(a[i]>0){
                DFS(i,i,0),flag=0;
                if(pos){
                    DFS(pos,pos,0),flag=0,DFS(i,i,0),flag=0,pos=0;
                }
                if(a[i]==-3){++ans;}
            }
        }
        printf("%d\n",ans);
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
    }
    return 0;
}
