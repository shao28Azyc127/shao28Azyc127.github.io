#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

int a[MAXN],b[MAXN],n,m,ans=1e9;
int X[MAXN],Y[MAXN];
char op[MAXN];
bool check(){
    for(int i=1;i<=n;i++) b[i]=a[i];
    for(int i=1;i<=m;i++){
        if(op[i]=='T') b[X[i]]=1;
        if(op[i]=='F') b[X[i]]=0;
        if(op[i]=='U') b[X[i]]=2;
        if(op[i]=='+') b[X[i]]=b[Y[i]];
        if(op[i]=='-') b[X[i]]=((b[Y[i]]==2)?2:(b[Y[i]]^1));
    }
    bool flag=1;
    for(int i=1;i<=n;i++) flag&=(a[i]==b[i]);
    return flag;
}
void dfs(int x,int sum){
    if(sum>ans) return;
    if(x==n+1){
        if(check()) ans=min(ans,sum);
        return;
    }
    for(int i=0;i<3;i++){
        a[x]=i;
        dfs(x+1,sum+(a[x]==2));
    }
}
void solve1(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>op[i]>>X[i];
        if(op[i]=='+' || op[i]=='-') cin>>Y[i];
    }
    ans=1e9,dfs(1,0);
    cout<<ans<<'\n';
}
void solve2(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) a[i]=0;
    for(int i=1;i<=m;i++){
        char ch; int x; cin>>ch>>x;
        if(ch=='U') a[x]=1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=a[i];
    cout<<cnt<<'\n';
}
void solve3(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) a[i]=0;
    for(int i=1;i<=m;i++){
        cin>>op[i]>>X[i];
        if(op[i]=='+' || op[i]=='-') cin>>Y[i];
    }
    while(1){
        for(int i=1;i<=n;i++) b[i]=a[i];
        for(int i=1;i<=m;i++){
            if(op[i]=='U') a[X[i]]=1;
            else a[X[i]]=a[Y[i]];
        }
        bool flag=1;
        for(int i=1;i<=n;i++) flag&=(b[i]==a[i]);
        if(flag) break;
    }
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=a[i];
    cout<<cnt<<'\n';
}
void solve4(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) a[i]=0;
    for(int i=1;i<=m;i++){
        cin>>op[i]>>X[i];
        if(op[i]=='+' || op[i]=='-') cin>>Y[i];
    }
    int fk=0;
    while(1){
        for(int i=1;i<=n;i++) b[i]=a[i];
        for(int i=1;i<=m;i++){
            if(op[i]=='T') a[X[i]]=1;
            if(op[i]=='F') a[X[i]]=0;
            if(op[i]=='U') a[X[i]]=2;
            if(op[i]=='+') a[X[i]]=a[Y[i]];
            if(op[i]=='-') a[X[i]]=((a[Y[i]]==2)?2:(a[Y[i]]^1));
        }
        bool flag=1;
        for(int i=1;i<=n;i++) flag&=(b[i]==a[i]);
        if(flag) break;
    }
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=(a[i]==2);
    cout<<cnt<<'\n';
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,T; cin>>c>>T;
    if(c==1 || c==2){
        while(T--) solve1();
    }
    if(c==3 || c==4){
        while(T--) solve2();
    }
    if(c==5 || c==6){
        while(T--) solve3();
    }
    if(c>=7){
        while(T--) solve4();
    }
    return 0;
}
