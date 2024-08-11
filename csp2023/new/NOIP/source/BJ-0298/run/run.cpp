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
int c,t;
int n,m,k,d;
struct node{
    int x,y,v;
}a[100005];
int ans;
int lst;
void dfs(int day,int en,int lx){
    if(day==n+1){
        ans=max(ans,en);
        return;
    }
    while(day-1==a[lst].x){
        if(lx>=a[lst].y)en+=a[lst].v;
        lst++;
    }
    if(lx==k){
        dfs(day+1,en,0);
    }else{
        dfs(day+1,en-d,lx+1);
        dfs(day+1,en,lx);
    }
}
bool cmp(node n1,node n2){
    return n1.x<n2.x;
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    if(c==17||c==18){
        while(t--){
            ans=0;
            scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
            for(int i=1;i<=m;i++){
                scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].v);
            }
            for(int i=1;i<=m;i++){
                if(i==1&&a[i].x-a[i].y+1<=0)continue;
                if(k<a[i].y)continue;
                if(a[i].v<d*a[i].y)continue;
                ans+=a[i].v-d*a[i].y;
            }
            printf("%lld\n",ans);
        }
        return 0;
    }
    while(t--){
        ans=0;
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        for(int i=1;i<=m;i++){
            scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].v);
        }
        sort(a+1,a+m+1,cmp);
        lst=1;
        dfs(1,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
