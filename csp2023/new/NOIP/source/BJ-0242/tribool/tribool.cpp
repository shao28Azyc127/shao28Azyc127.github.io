#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int MAXN=2e5+5;
const int VT=2e5+1,VU=0;
int c[MAXN],mark[MAXN];
vector<PII>gra[MAXN];
int N,M,C,T;
struct Opt
{
    int x,y;
}q[MAXN];
int a[MAXN<<1],b[MAXN<<1];
int ans=0;
void Run()
{
    for(int i=1;i<=N;i++) a[i]=i;
    for(int i=1;i<=N;i++) b[i]=a[i];
    for(int i=1;i<=M;i++)
    {
        int x=q[i].x,y=q[i].y;
        if(y==VT||y==-VT||y==VU) b[x]=y;
        else if(y>0) b[x]=b[y];
        else b[x]=-b[-y];
    }
   // printf("%d %d %d\n",b[1],b[2],b[3]);
    return;
}
void Spread(int u,int col)
{
    c[u]=col;
    for(int i=0;i<gra[u].size();i++)
    {
        int v=gra[u][i].first,w=gra[u][i].second;
        if(c[v]!=-2) continue;
        Spread(v,col*w);
    }
}
bool flag=1;
void Try(int u,int col)
{
    if(!flag) return;
    mark[u]=col;
    for(int i=0;i<gra[u].size();i++)
    {
        int v=gra[u][i].first,w=gra[u][i].second;
        if(c[v]!=-2) continue;
        if(mark[v]!=-2)
        {
            if(mark[v]==mark[u]*w) continue;
            else
            {
                flag=0;
                return;
            }
        }
        else Try(v,col*w);
    }
    return;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d %d",&C,&T);
    while(T--)
    {
        scanf("%d %d",&N,&M);
        ans=N;
        for(int i=1;i<=M;i++)  
        {
            char s[5];
            scanf("%s",s+1);
            int x;
            scanf("%d",&x);
            if(s[1]=='T') q[i]={x,VT};
            if(s[1]=='F') q[i]={x,-VT};
            if(s[1]=='U') q[i]={x,VU};
            if(s[1]=='+'||s[1]=='-')
            {
                int y;
                scanf("%d",&y);
                if(s[1]=='+') q[i]={x,y};
                else q[i]={x,-y};
            }
        }
      //  for(int i=1;i<=M;i++) printf("(%d %d)\n",q[i].x,q[i].y);
        Run();
        int cnt=0;
        for(int i=1;i<=2*N;i++) gra[i].clear();
        gra[VT].clear(),gra[VU].clear();
        for(int i=1;i<=N;i++)
        {
            if(b[i]>0)
            {
                gra[i].push_back({b[i],1});
                gra[b[i]].push_back({i,1});
            }
            else 
            {
                gra[i].push_back({-b[i],-1});
                gra[-b[i]].push_back({i,-1});
                if(i==-b[i])
                {
                    gra[i].push_back({0,1});
                    gra[0].push_back({i,1});
                }
            }
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<gra[i].size();j++)
            {
                int v=gra[i][j].first,w=gra[i][j].second;
              //  printf("Edge%d %d %d\n",i,v,w);
            }
        }
        for(int i=1;i<=N;i++) c[i]=mark[i]=-2;
        Spread(VT,1);
        Spread(0,0);
        for(int i=1;i<=N;i++)
        {
            if(c[i]!=-2) continue;
            flag=1;
            Try(i,1);
            if(flag) Spread(i,1);
            else Spread(i,0);
        }
        ans=0;
        for(int i=1;i<=N;i++) if(c[i]==0) ans++;
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}