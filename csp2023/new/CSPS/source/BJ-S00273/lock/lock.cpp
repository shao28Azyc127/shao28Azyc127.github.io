#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+(c-'0');
    x*=f;
}
const int N=50;
int n,ans,c[N],a[N][N],pos[N];
map<pair<int,int>,int> mp;
void dfs(int dep){
    if(dep>5){
        bool f=0;
        for(int i=1;i<=n;++i){
            int dif=0,k=0;
            for(int j=1;j<=5;++j) if(c[j]!=a[i][j]) pos[++dif]=j;
            if(dif>2||dif==0) return;
            if(dif==1) continue;
            if(dif==2&&abs(pos[2]-pos[1])>1) return;
            int x=c[pos[1]],y=a[i][pos[1]],z=c[pos[2]],w=a[i][pos[2]];
            int ff=0;
            for(int j=1;j<=9;++j) if(((x+j)%10)==y && ((z+j)%10)==w) ff=1;
            if(ff==0) f=1;
        }
        if(!f){
            ans++;
        }
        return;
    }
    for(int i=0;i<=9;++i){
        c[dep]=i;
        dfs(dep+1);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    read(n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=5;++j) read(a[i][j]);
    }
    dfs(1);
    cout<<ans;
    return 0;
}
