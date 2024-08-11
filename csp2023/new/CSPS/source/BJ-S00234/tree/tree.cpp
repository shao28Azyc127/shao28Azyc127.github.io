#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const int N = 2e5+10;
int n,x,y,pre[N],k,num,st[N];
bool f[N];
LL d[N];
struct st{
    LL aa,bb,cc;
}p[N];
struct node{
    int to,next;
}a[N];
void add(int x,int y){
    a[++k]={y,pre[x]};
    pre[x]=k;
}
void dfs(int x,int fath){
    st[++num]=x;
    for(int i = pre[x];i;i=a[i].next){
        int to=a[i].to;
        if(to!=fath){
            dfs(to,x);
        }
    }
}
int main(){
freopen("tree.in","r",stdin);
freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%lld%lld%lld",&p[i].aa,&p[i].bb,&p[i].cc);
    }
    for(int i = 1;i < n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    dfs(1,0);
    int ans=n;
    for(int j = 1;j <= num;j++){
        for(int i = 1;i <= j;i++){
            if(p[st[i]].bb+i*p[st[i]].cc<1) d[st[i]]+=1;
            else d[st[i]]+=p[st[i]].bb+i*p[st[i]].cc;
            if(d[st[i]]>=p[st[i]].aa) ans--;
        }
    }

    int cnt=0;
    while(ans>0){
        for(int i = 1;i <= n;i++){
                cnt++;
            d[i]+=max(p[i].bb+(n+i)*p[i].cc,(LL)1);
            if(d[i]>=p[i].aa) ans--;
        }
    }
    cout<<cnt+n;
    return 0;
}
