#include<bits/stdc++.h>
#define p_b push_back
#define m_p make_pair
#define pi pair<int,int>
#define p1 first
#define p2 second
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
inline ll read(){
    ll x=0;short t=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')t=-1;ch=getchar();
    }while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}int n,m,res[maxn],tres[maxn],vis[maxn];
struct node {
    int x,y,val;
    node(){val=-1;}
}d[maxn];
vector<pi>v[maxn];
vector<int>qwq;
void dfs(int u){
    vis[u]=1;
    qwq.p_b(u);
    for(auto f:v[u]){
        int x=f.p1,y=f.p2;
        if(tres[x]!=-1)continue;
        if(y)tres[x]=2-tres[u];
        else tres[x]=tres[u];
        dfs(x);
    }
}int calc(int u,int x){
    qwq.clear();
    tres[u]=x;dfs(u);
    //printf("tres[%d]=%d\n",u,x);
    //for(int x:qwq)printf("%d %d\n",x,tres[x]);
    for(int x:qwq)if(res[x]!=-1&&tres[x]!=res[x]){
        for(int x:qwq)tres[x]=-1;
        return 1e9;
    }
    for(int x:qwq){
        for(auto f:v[x]){
            int y=f.p1,w=f.p2;
            if(w){
                if(tres[x]+tres[y]!=2){
                    for(int x:qwq)tres[x]=-1;
                    return 1e9;
                }
            }else {
                if(tres[x]!=tres[y]){
                    for(int x:qwq)tres[x]=-1;
                    return 1e9;
                }
            }
        }
    }int res=0;
    for(int x:qwq)if(tres[x]==1)++res;
    return res;
}
void slv(){
    n=read(),m=read();
    up(i,1,n)d[i].val=-1,d[i].x=i,d[i].y=0,tres[i]=res[i]=-1,vis[i]=0;
    up(i,1,m){
        char ch=getchar();
        while(ch!='+'&&ch!='-'&&ch!='T'&&ch!='U'&&ch!='F')ch=getchar();
        if(ch=='+'){
            int x=read(),y=read();
            if(d[y].val!=-1)d[x].val=d[y].val;
            else d[x].x=d[y].x,d[x].y=d[y].y,d[x].val=-1;
        }else if(ch=='-'){
            int x=read(),y=read();
            if(d[y].val!=-1)d[x].val=2-d[y].val;
            else d[x].x=d[y].x,d[x].y=!d[y].y,d[x].val=-1;
        }else {
            int x=read();
            if(ch=='T')d[x].val=0;
            else if(ch=='F')d[x].val=2;
            else d[x].val=1;
        }
    }up(i,1,n)res[i]=d[i].val;
    up(i,1,n)v[i].clear();
    up(i,1,n)if(d[i].val==-1)v[d[i].x].p_b(m_p(i,d[i].y)),v[i].p_b(m_p(d[i].x,d[i].y));
    int res=0;
    up(i,1,n)if(!vis[i]){
        int mn=1e9;
        up(j,0,2)mn=min(mn,calc(i,j));
        res+=mn;
    }printf("%d\n",res);
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    read();int t=read();
    while(t--)slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}