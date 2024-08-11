#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n,m,tcnt,out;
int rx,ry;

int ans[MAXN];
bool vis[MAXN],vv[MAXN];
int tag[MAXN];

int siz[MAXN];

char op;

struct Value{
    int f,k;
}val[MAXN];

vector<int> g[MAXN];

stack<int> s0,st;

void calc(int i){
    ans[i]=ans[val[i].f]*val[i].k;

    return;
}

void topo(){
    while(!s0.empty()){
        int nu=s0.top();
        s0.pop();
        vis[nu]=true;
        for(auto nv:g[nu]){
            if(vis[nv]){
                continue;
            }
            calc(nv);
            s0.push(nv);
        }
    }

    return;
}

void solve(int i){
    siz[i]=1;
    for(auto nv:g[i]){
        if(tag[nv]<0){
            continue;
        }

        solve(nv);

        siz[i]+=siz[nv];
    }

    return;
}

void run(){
    memset(tag,0,sizeof(tag));
    memset(ans,0,sizeof(tag));
    memset(siz,0,sizeof(siz));
    memset(vis,0,sizeof(vis));
    memset(vv,0,sizeof(vv));

    tcnt=0;

    out=0;

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        val[i].f=i;
        val[i].k=1;
        vis[i]=false;
        g[i].clear();
    }

    for(int i=1;i<=m;i++){
        cin>>op;
        if(op=='+'){
            cin>>rx>>ry;
            val[rx]=val[ry];
        }else if(op=='-'){
            cin>>rx>>ry;
            val[rx]=val[ry];
            val[rx].k*=-1;
        }else if(op=='T'){
            cin>>rx;
            val[rx].f=0;
            val[rx].k=1;
        }else if(op=='F'){
            cin>>rx;
            val[rx].f=0;
            val[rx].k=-1;
        }else if(op=='U'){
            cin>>rx;
            val[rx].f=0;
            val[rx].k=0;
        }
    }

    for(int i=1;i<=n;i++){
        if(val[i].f==0){
            ans[i]=val[i].k;
            s0.push(i);
            vis[i]=true;
        }else if(val[i].f==i){
            if(val[i].k==1){
                ans[i]=1;
            }else{
                ans[i]=0;
            }
            s0.push(i);
            vis[i]=true;
        }else{
            g[val[i].f].push_back(i);
        }
    }

    topo();

    for(int i=1;i<=n;i++){
        if(ans[i]==0){
            out++;
        }
    }

    for(int i=1;i<=n;i++){
        if(vis[i]){
            continue;
        }

        int now=i;
        tcnt++;
        while(!tag[now]){
            tag[now]=tcnt;
            st.push(now);
            now=val[now].f;
        }

        if(!st.empty()){
            int tt=tag[now];
            if(tt==tcnt){
                tt=now;
                tag[tt]=-tcnt;
                while(st.top()!=tt){
                    tag[st.top()]=-tcnt;
                    st.pop();
                }
                while(!st.empty()){
                    st.pop();
                }
            }else{
                while(!st.empty()){
                    tag[st.top()]=abs(tt);
                    st.pop();
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(tag[i]<0){
            solve(i);
        }
    }

    for(int i=1;i<=n;i++){
        if(tag[i]<0&&!vv[i]){
            int now=i,ncnt=1,nsum=0;
            while(tag[i]<0&&!vv[now]){
                vv[now]=true;

                ncnt*=val[now].k;
                nsum+=siz[now];
                now=val[now].f;
            }
            if(ncnt==1){
                out-=nsum;
            }
        }
    }

    printf("%d\n",out);

    return;
}

int c,t;

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);

	ios::sync_with_stdio(false);

	cin>>c>>t;

	for(int i=1;i<=t;i++){
        run();
	}

	return 0;
}
