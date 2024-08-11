#include <bits/stdc++.h>
#define ll long long
#define db double
#define MAXN 100000
#define P 998244353

using namespace std;

struct chg{
    int x,y,v;
};

int x,t;
int n,m,k,d;
chg c[MAXN+5];
ll ans;
int num;

void dfs(int p,int l,ll e){
    if(p==n) {ans=max(ans,e);return;}
    ll pl=0;
    while(p==c[num].x&&num<=m){
        if(l>=c[num].y) pl+=c[num].v;
        num++;
    }
    if(num<=m&&e<ans) return;
    if(l<k) dfs(p+1,l+1,e-d+pl);
    dfs(p+1,0,e+pl);
}

bool cmp(chg a,chg b){
    return a.x<b.x;
}

int main(){

    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);

    scanf("%d%d",&x,&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&k,&d);
        ans=-(ll)n*d;
        num=1;
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].v);

        }
        sort(c+1,c+m+1,cmp);
        dfs(0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
