#include <bits/stdc++.h>
#define int long long
using namespace std;
short bl[100005],bl1[100005];
struct cz{
    char op;
    int x,y;
}ask[100005];
int ans;
void dfs(int x,int n,int m){
    if(x==0){
        for(int i=1;i<=n;++i)bl1[i]=bl[i];
        for(int i=0;i<m;++i){
            if(ask[i].op=='-'){
                if(bl1[ask[i].y]==2)bl1[ask[i].x]=bl1[ask[i].y];
                else bl1[ask[i].x]=!bl1[ask[i].y];
            }
            else if(ask[i].op=='+')bl1[ask[i].x]=bl1[ask[i].y];
            else if(ask[i].op=='T')bl1[ask[i].x]=1;
            else if(ask[i].op=='F')bl1[ask[i].x]=0;
            else if(ask[i].op=='U')bl1[ask[i].x]=2;
        }
        bool flag=1;
        int cnt=0;
        for(int i=1;i<=n;++i){
            if(bl1[i]!=bl[i])flag=0;
            cnt+=(bl1[i]==2?1:0);
        }
        if(flag)ans=min(ans,cnt);
        return;
    }
    for(int i=0;i<=2;++i){
        bl[x]=i;
        dfs(x-1,n,m);
    }
    return;
}
inline void baoli(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>ask[i].op;
        if(ask[i].op=='T'||ask[i].op=='F'||ask[i].op=='U')cin>>ask[i].x;
        else cin>>ask[i].x>>ask[i].y;
    }
    ans=INT_MAX;
    dfs(n,n,m);
    cout<<ans<<"\n";
    return;
}
void getfa(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;++i)bl[i]=0;
    while(m--){
        char op;
        int abc;
        cin>>op>>abc;
        bl[abc]=(op=='T'?1:(op=='F'?0:2));
    }
    int cnt=0;
    for(int i=1;i<=n;++i)if(bl[i]==2)cnt++;
    cout<<cnt<<"\n";
    return;
}
void merge(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;++i)bl[i]=0;
    while(m--){
        char op;
        int x,y;
        cin>>op>>x;
        if(op!='U')cin>>y;
        if(op=='+')bl[x]=bl[y];
        else bl[x]=2;
    }
    int cnt=0;
    for(int i=1;i<=n;++i)if(bl[i]==2)cnt++;
    cout<<cnt<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c<=2)while(t--)baoli();
    else if(c<=4)while(t--)getfa();
    else if(c<=6)while(t--)merge();
    else baoli();
    return 0;
}
