#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#define int long long
#define ull unsigned long long
using namespace std;
int C,t;
int n,m;
int c[15],tp[15];
struct node{
    char v;
    int x,y;
}q[100005];
int ans;
bool check(){
    for(int i=1;i<=n;i++){
        tp[i]=c[i];
    }
    for(int i=1;i<=m;i++){
        if(q[i].v=='T'||q[i].v=='F'||q[i].v=='U'){
            if(q[i].v=='T')c[q[i].x]=1;
            else if(q[i].v=='F')c[q[i].x]=2;
            else c[q[i].x]=3;
        }else{
            if(q[i].v=='+')c[q[i].x]=c[q[i].y];
            else if(q[i].v=='-'){
                if(c[q[i].y]==1)c[q[i].x]=2;
                else if(c[q[i].y]==2)c[q[i].x]=1;
                else c[q[i].x]=3;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(c[i]!=tp[i])return false;
    }
    return true;
}
void dfs(int k){
    if(k==n+1){
        if(check()){
            int cnt=0;
            for(int i=1;i<=n;i++)if(c[i]==3)cnt++;
            ans=min(ans,cnt);
        }
        return;
    }
    c[k]=1;
    dfs(k+1);
    c[k]=2;
    dfs(k+1);
    c[k]=3;
    dfs(k+1);
    return;
}
signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%lld%lld",&C,&t);
    if(C==1||C==2){
        while(t--){
            ans=1e18;
            scanf("%lld%lld",&n,&m);
            for(int i=1;i<=m;i++){
                scanf(" %c",&q[i].v);
                if(q[i].v=='+'||q[i].v=='-')scanf("%lld%lld",&q[i].x,&q[i].y);
                else{
                    scanf("%lld",&q[i].x);
                }
            }
        //    for(int i=1;i<=m;i++)cout<<q[i].x<<' '<<q[i].y<<endl;
            dfs(1);
            printf("%lld\n",ans);
        }
    }else if(C==3||C==4){
        while(t--){
            ans=0;
            scanf("%lld%lld",&n,&m);
            for(int i=1;i<=m;i++){
                scanf(" %c",&q[i].v);
                scanf("%lld",&q[i].x);
                if(q[i].v=='U')c[q[i].x]=3;
                else c[q[i].x]=0;
            }
            for(int i=1;i<=n;i++)if(c[i]==3)ans++;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
/*
2 1
10 10
T 3
+ 1 2
- 7 1
+ 2 10
T 6
- 1 4
U 3
+ 7 10
F 5
+ 6 9
*/
