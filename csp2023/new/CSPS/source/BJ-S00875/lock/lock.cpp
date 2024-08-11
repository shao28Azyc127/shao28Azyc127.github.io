#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
const int INF=2e9+5;
template<typename T>
inline void read(T &x) {
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
template<typename T>
void write(T x) {
    if(x>=10)write(x/10);
    putchar(x%10+'0');
}
int n;
int a[10][10],ans[10];
ll res;
bool vis[10][10][10][10][10];
int b[10],pos[10];
bool check(int x) {
    if(vis[ans[1]][ans[2]][ans[3]][ans[4]][ans[5]])return 0;
    int cntt=0;
    for(int i=1;i<=5;i++) {
        b[i]=a[x][i]-ans[i]+10;
        b[i]%=10;
        if(b[i]!=0)pos[++cntt]=i;
        if(cntt>2)return 0;
    }
    if(cntt==1)return 1;
    if(b[pos[1]]==b[pos[2]]&&pos[2]-pos[1]==1)return 1;
    return 0;
}
void dfs(int dep) {
    if(dep>5) {
        for(int i=1;i<=n;i++) {
            if(!check(i))return;
        }
        //printf("%d %d %d %d %d\n",ans[1],ans[2],ans[3],ans[4],ans[5]);
        res++;
        return;
    }
    for(int i=0;i<=9;i++) {
        ans[dep]=i;
        dfs(dep+1);
    }
}
int main() {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=5;j++)
            scanf("%d",&a[i][j]);
        vis[a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]]=1;
    }
    //printf("%d\n",check(1));
    dfs(1);
    printf("%lld\n",res);
    return 0;
}
