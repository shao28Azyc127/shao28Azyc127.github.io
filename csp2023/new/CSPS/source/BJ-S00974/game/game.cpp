#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2000010;
using ll=long long;
int n;
char s[N];
void init(){
    cin>>n;
    scanf("%s",s+1);
}
int f[N];
ll g[N];
ll ans;
// ll f[N][3];
int main(){
    // freopen("game/game4.in","r",stdin);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    init();
    for(int i=n;i;i--){
        int p=i+1;
        while(p<=n&&s[i]!=s[p])p=f[p]+1;
        f[i]=p;
        if(f[i]<=n)g[i]=g[f[i]+1]+1;
        ans+=g[i];
    }
    // for(int i=1;i<=n;i++)cout<<f[i]<<' '<<g[i]<<'\n';
    cout<<ans;
    return 0;
}