#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
struct Node{
    int u,v,nxt,c;
}e[N<<1];
int h[N],tot;
void add(int u,int v,int c){
    //cout<<u<<" "<<v<<" "<<c<<"\n";
    tot++;
    e[tot].u=u;
    e[tot].v=v;
    e[tot].c=c;
    e[tot].nxt=h[u];
    h[u]=tot;
}
int n,m;
vector<int>stat[N];
int len[N];
int stat_tot;
int typ[N];
/*void dfs(int start){
    for(int i=h[start];i;i=e[i].nxt){
        typ[e[i].v]=typ[start]*e[i].c;
        dfs(e[i].v);
    }
}*/
int cnt=0;
int fa[N];
int getfa(int u){
    if(fa[u]==u)return u;
    return fa[u]=getfa(fa[u]);
}
void merge(int u,int v){
    //cout<<u<<" "<<v<<"\n";
    int fu=getfa(u);
    int fv=getfa(v);
    if(fu==fv)return;
    fa[fu]=fv;
    if(typ[fu]!=4||typ[fv]!=4){
        if(typ[fu]==4)return;
        if(typ[fv]==4){
            typ[fv]=typ[fu];
            return;
        }
        if(typ[fu]==0||typ[fv]==0){
            typ[fv]=0;
            return;
        }
        if(typ[fu]==-typ[fv])typ[fv]=0;
        else return;
    }
    return;
}
void calc(){
    for(int i=1;i<=2*max(stat_tot,n);i++){
        fa[i]=0;
        h[i]=len[i]=0;
        typ[i]=0;
        stat[i].clear();
    }
    for(int i=1;i<=tot;i++){
        e[i].u=e[i].v=e[i].c=e[i].nxt=0;
    }
    cnt=0;
    stat_tot=0;
    tot=0;
    n=m=0;
}
signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++){
            stat[i].push_back(i+3);
            len[i]=1;
        }
        stat_tot=n+3;
        for(int i=1;i<=m;i++){
            char s;
            scanf("%s",&s);
            //cout<<s<<"\n";
            stat_tot++;
            if(s=='T'){
                int u;
                scanf("%lld",&u);
                len[u]++;
                stat[u].push_back(stat_tot);
                add(1,stat_tot,1);
            }
            if(s=='F'){
                int u;
                scanf("%lld",&u);
                len[u]++;
                stat[u].push_back(stat_tot);
                add(2,stat_tot,1);
            }
            if(s=='U'){
                int u;
                scanf("%lld",&u);
                len[u]++;
                stat[u].push_back(stat_tot);
                add(3,stat_tot,1);
                add(3,stat_tot,-1);
            }
            if(s=='+'){
                int u,v;
                scanf("%lld%lld",&u,&v);
                add(stat[v][len[v]-1],stat_tot,1);
                len[u]++;
                stat[u].push_back(stat_tot);
            }
            if(s=='-'){
                int u,v;
                scanf("%lld%lld",&u,&v);
                add(stat[v][len[v]-1],stat_tot,-1);
                len[u]++;
                stat[u].push_back(stat_tot);
            }
        }
        for(int i=1;i<=stat_tot*2;i++){
            typ[i]=4;
            fa[i]=i;
        }
        typ[1]=1;
        typ[2]=-1;
        typ[3]=0;
        typ[1+stat_tot]=-1;
        typ[2+stat_tot]=1;
        typ[3+stat_tot]=0;
        //dfs(1);
        //dfs(2);
        //dfs(3);
        /*for(int i=1;i<=n;i++){
            if(typ[stat[i][len[i]-1]]!=4){
                vis[i]=1;
                endpos[i]=typ[stat[i][len[i]-1]];
                cnt+=(!endpos[i]);
            }
        }*/
        //cout<<cnt<<"\n";
        //cout<<stat_tot<<" aat\n";
        for(int i=1;i<=tot;i++){
            if(e[i].c==1){
                merge(e[i].u,e[i].v);
                merge(e[i].u+stat_tot,e[i].v+stat_tot);
            }
            else{
                merge(e[i].u,e[i].v+stat_tot);
                merge(e[i].u+stat_tot,e[i].v);
            }
        }
        //for()
        /*for(int i=1;i<=stat_tot;i++){
            if(getfa(i)==getfa)
        }
        for(int i=1;i<=n;i++){
            cout<<
            if(getfa(i+3)==getfa(i+3+stat_tot)||){
                //cout<<"?\n";
                typ[getfa(i+3)]=typ[getfa(i+3+stat_tot)]=0;
            }
        }*/
        //cout<<cnt<<"\n";
        for(int i=1;i<=n;i++){
            merge(i+3,stat[i][len[i]-1]);
            merge(i+3+stat_tot,stat[i][len[i]-1]+stat_tot);
        }
        for(int i=1;i<=stat_tot;i++){
            /*if(typ[getfa(i+3)]==0||typ[getfa(i+3+stat_tot)]==0||getfa(i+3)==getfa(i+3+stat_tot)||(typ[getfa(i+3)]==typ[getfa(i+3+stat_tot)]&&typ[getfa(i+3+stat_tot)]!=4)){
                typ[getfa(i+3)]=typ[getfa(i+3+stat_tot)]=0;
            }*/
            if(getfa(i)==getfa(i+stat_tot)||typ[getfa(i)]==0||typ[getfa(i+stat_tot)]==0||(typ[getfa(i+stat_tot)]==typ[getfa(i)]&&typ[getfa(i)]!=4)){
                typ[getfa(i)]=typ[getfa(i+stat_tot)]=0;
            }
        }
        //cout<<typ[getfa(2+stat_tot)]<<"\n";
        for(int i=1;i<=n;i++){
            if(typ[getfa(i+3)]==0||typ[getfa(i+3+stat_tot)]==0||getfa(i+3)==getfa(i+3+stat_tot)||(typ[getfa(i+3)]==typ[getfa(i+3+stat_tot)]&&typ[getfa(i+3+stat_tot)]!=4)){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
        calc();
    }
    return 0;
}