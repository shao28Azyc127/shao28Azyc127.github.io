#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<ctime>
using namespace std;
const int MAXN=1e5+10;
struct Tp{
    char op;
    int x,y;
}a[MAXN];
int n,m;
int cc,t;
int ans,minl;
int cnt;
int b[MAXN],c[MAXN];
bool can;
bool Energy(){
    memcpy(c,b,sizeof(b));
    for(int i=1;i<=m;i++){
        if(a[i].op=='T') c[a[i].x]=1;
        else if(a[i].op=='F') c[a[i].x]=0;
        else if(a[i].op=='U') c[a[i].x]=2;
        else if(a[i].op=='+'){
            c[a[i].x]=c[a[i].y];
        }
        else{
            if(c[a[i].y]==0) c[a[i].x]=1;
            else if(c[a[i].y]==1) c[a[i].x]=0;
            else c[a[i].x]=2;
        }
    }
 //   can=0;
    for(int i=1;i<=n;i++) if(b[i]!=c[i]) return false;
 //   can=1;
  //  return cnt;
    return true;
}
int tot=0;
void Dfs(int x){
    if(cnt>ans) return;
    if(x>n){
        if(Energy()) ans=min(ans,cnt);
        return;
    }
    for(int i=0;i<3;i++){
        b[x]=i;
        if(i==2) cnt++;
        Dfs(x+1);
        if(i==2) cnt--;
        b[x]=0;
    }
}
void Work1(){
    ans=n;
    Dfs(1);
    cout<<ans<<endl;
}
void Work2(){
    for(int i=1;i<=n;i++) b[i]=3;
    for(int i=1;i<=m;i++){
        if(a[i].op=='T') b[i]=1;
        else if(a[i].op=='F') b[i]=0;
        else b[i]=2;
    }
    for(int i=1;i<=n;i++) ans+=b[i]==2;
    cout<<ans<<endl;
}/*
void Work(){
    for(int i=1;i<=n;i++) b[i]=2;
    for(int i=1;i<=m;i++){
        if(a[i].op=='T') b[a[i].x]=1;
        else if(a[i].op=='F') b[a[i].x]=0;
        else if(a[i].op=='U') b[a[i].x]=2;
        else if(a[i].op=='+'){
            b[a[i].x]=b[a[i].y];
        }
        else{
            if(b[a[i].y]==0) b[a[i].x]=1;
            else if(b[a[i].y]==1) b[a[i].x]=0;
            else b[a[i].x]=2;
        }
    }
    for(int i=1;i<=n;i++) ans+=b[i]==2;
    cout<<ans<<endl;
}*/
int main(){
    ios::sync_with_stdio(false);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    srand(time(NULL));
    cin>>cc>>t;
    int tmp=t;
    while(tmp--){
        memset(b,0,sizeof(b));
        can=tot=ans=0;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            cin>>a[i].op;
            if(a[i].op=='T'||a[i].op=='F'||a[i].op=='U') cin>>a[i].x;
            else cin>>a[i].x>>a[i].y;
        }
        if(1<=cc&&cc<=2) Work1();
        else if(3<=cc&&cc<=4) Work2();
        //else Work();
    }
    return 0;
}