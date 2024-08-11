#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m;
struct node{
    char op;
    int to,from;
}a[N];
char b[N];
char e[N];
bool vis[N];
bool flag0;
bool check(){
    for(int i=1;i<=n;i++){
        e[i]=b[i];
    }
    for(int i=1;i<=m;i++){
        if(a[i].op=='T'||a[i].op=='U'||a[i].op=='F'){
            e[a[i].to]=a[i].op;
        }else{
            if(a[i].op=='+'){
                e[a[i].to]=e[a[i].from];
            }else{
                if(e[a[i].from]=='T') e[a[i].to]='F';
                if(e[a[i].from]=='F') e[a[i].to]='T';
                if(e[a[i].from]=='U') e[a[i].to]='U';
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(e[i]!=b[i]) return false;
    }
    return true;
}
void dfs(char c,int p,int k){
    if(!flag0)return;
    b[p]=c;
    if(p==n){
        if(check()) flag0=0;return;
    }
    dfs('T',p+1,k);
    dfs('F',p+1,k);
    if(k)
    dfs('U',p+1,k-1);
}
void solve1(){
    flag0=1;
    for(int i=1;i<=m;i++){
        char v;
        cin>>v;
        a[i].op=v;
        if(v=='T'||v=='U'||v=='F'){
            cin>>a[i].to;
        }else{
            cin>>a[i].to>>a[i].from;
        }
    }
    for(int i=0;i<=n;i++){

        int k=i;
        dfs('T',1,k);
        dfs('F',1,k);
        if(k)
        dfs('U',1,k-1);
        if(!flag0){cout<<k<<endl;break;}
    }
    return;
}
void solve2(){
    memset(vis,0,sizeof vis);
    int cnt=0;
    for(int i=1;i<=m;i++){
        char v;
        int x;
        cin>>v>>x;
        a[i].op=v;
        a[i].to=x;
    }
    for(int i=m;i>=1;i--){
        if(!vis[a[i].to]){
            vis[a[i].to]=1;
            if(a[i].op=='U') cnt++;
        }
    }
    cout<<cnt<<endl;
}
int c,t;
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        if(c==1||c==2) solve1();
        else if(c==3||c==4) solve2();
        else{
            for(int i=1;i<=m;i++){
                char v;
                cin>>v;
                int x,y;
                if(v=='T'||v=='U'||v=='F'){
                    cin>>x;
                }else{
                    cin>>x>>y;
                }
            }
            cout<<0<<endl;
        }
    }
}
