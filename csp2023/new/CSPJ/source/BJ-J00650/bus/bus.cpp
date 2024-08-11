#include<bits/stdc++.h>
using namespace std;
int head[10004],to[20004],nxt[20004],least[20004];
int tot;
int n,m,k;
int len[10004],p;
void add(int u,int v,int tm){
    nxt[tot]=head[u];
    head[u]=++tot;
    to[tot]=v;
    least[tot]=tm;
}
struct nd{
    int pl,ln;
};
int mn=1e9;
void mem(){
    for(int i=1;i<=n;i++)len[i]=1e9;
}
void out(){
    for(int i=1;i<=n;i++)cout<<len[i]<<" ";
    cout<<endl;
}
void spfa(int s,int stim){
    mem();
    nd st,a;
    len[s]=stim;
    st.ln=stim;
    st.pl=s;
    int l,p;
    queue<nd >q;
    q.push(st);
    while(!q.empty()){
        a=q.front();
        p=a.pl;
        l=a.ln;
        q.pop();
        for(int i=head[p];i!=0;i=nxt[i]){
            if(len[to[i]]>len[p]){
                if(len[p]<least[i]){
                    continue;
                }else{
                    len[to[i]]=min(len[p]+1,len[to[i]]);
                }
                a.ln=len[to[i]];
                a.pl=to[i];
                q.push(a);
            }
        }
    }
    if(len[n]!=p&&len[n]%k==0){
        mn=min(mn,len[n]);
    }
    //out();
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    p=1e9;
    cin>>n>>m>>k;
    int u,v,tm;
    int mx=0;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>tm;
        add(u,v,tm);
        mx=max(mx,tm);
    }
    for(int i=0;i/2<=mx&&i<mn;i+=k){
        spfa(1,i);
    }
    if(mn==1e9)cout<<"-1";
    else     cout<<mn;
    return 0;
}
