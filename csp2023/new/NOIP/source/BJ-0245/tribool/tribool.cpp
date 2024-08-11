#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10,M=4e5+10; //2n+6
struct State{
    int from,tim; //-1
    int flag;     //T/F/U
};
struct node{
    int x,w;
};
stack <State> v[N];
int head[N],vtex[M],nxt[M],edge[M],dfn[N],low[N],ins[N],col[N];
int ne_h[N],ne_v[M],ne_t[M],val[N],ne_val[N],cnt[N],vis[N];
stack <node> s;
int n,m,c,T,idex=1,idex_2=1,tot,num;

void addEdge(int x,int y,int w)
{
    nxt[idex]=head[x];
    head[x]=idex;
    vtex[idex]=y;
    edge[idex]=w;
    idex++;
}

void tarjan(int x,int t)
{
    dfn[x]=low[x]=++tot;
    ins[x]=1;
    s.push((node){x,t});
    int tmp=head[x];
    while(tmp){
        if(!dfn[vtex[tmp]]){
            if(edge[tmp]==0)
                tarjan(vtex[tmp],!t);
            else tarjan(vtex[tmp],t);
            low[x]=min(low[x],low[vtex[tmp]]);
            //cout<<x<<" "<<vtex[tmp]<<" "<<edge[tmp]<<endl;
        }
        else if(ins[vtex[tmp]]) low[x]=min(low[x],dfn[vtex[tmp]]);
        //cout<<x<<" "<<vtex[tmp]<<" "<<low[x]<<endl;
        tmp=nxt[tmp];
    }

    bool flag=false;
    if(low[x]==dfn[x]){
        num++;
        node temp=s.top();
        while(s.size() && s.top().x!=x){
            if(val[s.top().x]==-1) flag=true;
            col[s.top().x]=num;
            ins[s.top().x]=0;
            cnt[num]++;
            s.pop();
        }
        if(val[s.top().x]==-1) flag=true;
        col[x]=num;
        ins[x]=0;
        cnt[num]++;
        s.pop();
        if(cnt[num]>1){
            if(v[x].top().flag==1){
                //cout<<x<<" "<<temp.x<<" "<<val[temp.x]<<" "<<t<<endl;
                if(temp.w!=t) flag=true;
            }
            else{
                if(temp.w==t) flag=true;
            }
        }
        if(flag) ne_val[num]=-1;
    }
}

void addEdge_2(int x,int y)
{
    ne_t[idex_2]=ne_h[x];
    ne_h[x]=idex_2;
    ne_v[idex_2]=y;
    idex_2++;
}

void dfs(int x)
{
    ne_val[x]=-1;
    int tmp=ne_h[x];
    vis[x]=1;
    while(tmp){
        if(!vis[ne_v[tmp]])
            dfs(ne_v[tmp]);
        tmp=ne_t[tmp];
    }
}

void init()
{
    memset(head,0,sizeof(head));
    memset(edge,0,sizeof(edge));
    memset(ne_h,0,sizeof(ne_h));
    idex=1,idex_2=1,tot=0,num=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(col,0,sizeof(col));
    memset(val,0,sizeof(val));
    memset(ne_val,0,sizeof(ne_val));
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>T;
    while(T--){
        init();
        cin>>n>>m;
        val[2*n+3]=-1,val[2*n+1]=1,val[2*n+2]=0;
        for(int i=1;i<=2*n+3;i++)
            while(v[i].size()) v[i].pop();
        for(int i=1;i<=2*n;i++) v[i].push((State){i,0,1}); //-2;undefined
        for(int i=2*n+1;i<=2*n+3;i++)
            v[i].push((State){i,0,1});
        for(int i=1;i<=m;i++){
            char op;
            int x,y;
            cin>>op;
            if(op=='T' || op=='F' || op=='U'){
                cin>>x;
                v[x].push((State){2*n+2,i,1});
                if(op=='T') v[x].top().from=2*n+1;
                else if(op=='U') v[x].top().from=2*n+3;
            }
            else{
                cin>>x>>y;
                v[x].push(v[y].top());
                if(op=='-') v[x].top().flag=!v[y].top().flag;
                //cout<<x<<" "<<v[x].top().from<<" "<<v[x].top().flag<<endl;
            }
        }
        for(int i=1;i<=n;i++){
            State x=v[i].top();
            if(x.from==i && x.flag==0)
                val[i]=-1;
            else if(x.from==i) continue;
            else addEdge(x.from,i,x.flag);
            //cout<<x.from<<" "<<i<<" "<<x.flag<<endl;
        }
        for(int i=1;i<=n;i++){
            if(!dfn[i]) tarjan(i,0);
        }
        if(!dfn[2*n+3]) tarjan(2*n+3,0);
        for(int i=1;i<=n;i++){
            State x=v[i].top();
            if(col[x.from]!=col[i]) addEdge_2(col[i],col[x.from]),addEdge_2(col[x.from],col[i]);
        }
        //cout<<ne_val[1]<<endl;
        for(int i=1;i<=num;i++)
            if(ne_val[i]==-1 && !vis[i]) dfs(i);
        //for(int i=1;i<=num;i++) cout<<ne_val[i]<<endl;
        int ans=0;
        for(int i=1;i<=num-1;i++)
            if(ne_val[i]==-1) ans+=cnt[i];
        cout<<ans<<endl;
    }
    return 0;
}
