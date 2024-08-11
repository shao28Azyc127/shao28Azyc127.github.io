#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct T{
    char op;
    int x,y;
}a[N];
int o,_;
int n,m,ans;
int val[N],now[N];
void dfs(int x){
    if(x>n){
        for(int i=1;i<=n;i++) now[i]=val[i];
        for(int i=1;i<=m;i++){
            if(a[i].op=='+') now[a[i].x]=now[a[i].y];
            else if(a[i].op=='-') now[a[i].x]=(now[a[i].y]==2?now[a[i].y]:1-now[a[i].y]);
            else{
                if(a[i].op=='U') now[a[i].x]=2;
                else now[a[i].x]=(a[i].op=='T');
            }
        }
        int ok=1,cnt=0;
        for(int i=1;i<=n;i++){
            if(val[i]!=now[i]) ok=0;
            cnt+=(val[i]==2);
        }
        if(ok) ans=min(ans,cnt);
        return;
    }
    dfs(x+1);
    val[x]=1;
    dfs(x+1);
    val[x]=2;
    dfs(x+1);
    val[x]=0;
}
void solve(){
    ans=1e6;
    if(o<=2){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf(" %c",&a[i].op);
            if(a[i].op=='+'||a[i].op=='-') scanf("%d%d",&a[i].x,&a[i].y);
            else scanf("%d",&a[i].x);
        }
        dfs(1);
        printf("%d\n",ans);
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&o,&_);
    while(_--) solve();
    return 0;
}
