//bus.cpp
#include <bits/stdc++.h>

using namespace std;
int n,m,k,tmx;
int anss=1e9;
struct edge{
    int v,tme;
};
struct point{
    int p,cnt,tme;
};
vector<edge> G[10005];
queue<point> qu;
void bfs(int stt){
    point st;
    while(!qu.empty())qu.pop();
    st.p=1;st.tme=stt;st.cnt=0;
    qu.push(st);
    while(!qu.empty()){
        point fa=qu.front();qu.pop();
        if(fa.p==n){
            if(fa.cnt%k==0)anss=min(anss,fa.tme+fa.cnt);
            continue;
        }
        int siz=G[fa.p].size();
        for(int i=0;i<siz;i++){
            point zi;
            zi.p=G[fa.p][i].v;
            zi.cnt=fa.cnt+1;
            zi.tme=max(fa.tme,G[fa.p][i].tme-zi.cnt+1);
            //if(zi.cnt<=k){
                qu.push(zi);
            //}
        }
    }
}
void bfs2(){
    point st;
    while(!qu.empty())qu.pop();
    st.p=1;st.tme=k;st.cnt=0;
    qu.push(st);
    while(!qu.empty()){
        point fa=qu.front();qu.pop();
        if(fa.p==n){
            if(fa.cnt%k==0){
                anss=fa.tme+fa.cnt;
                return;
            }
            continue;
        }
        int siz=G[fa.p].size();
        for(int i=0;i<siz;i++){
            point zi;
            zi.p=G[fa.p][i].v;
            zi.cnt=fa.cnt+1;
            zi.tme=max(fa.tme,G[fa.p][i].tme-zi.cnt+1);
            qu.push(zi);
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,t;
        scanf("%d%d%d",&u,&v,&t);
        tmx=max(t,tmx);
        edge e;
        e.v=v;
        e.tme=t;
        G[u].push_back(e);
    }
    if(k==1)bfs(1);
    else if(n<=10){
            bfs(k);
        for(int i=2*k;i<=tmx;i+=k){
            bfs(i);
        }
    }else if(tmx=0){
        bfs2();
    }else{
        printf("-1\n");
        return 0;
    }
    if(anss>=1e9)printf("-1\n");
    else if(anss%k==0){
        printf("%d\n",anss);
    }else{
        printf("%d\n",(anss/k+1)*k);
    }
    return 0;
}
