#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int n,m,k,s,t,f[N],g[N][26];
char c[N];

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>c+1;
    for (int i=n-1;i>=1;--i){
        if (c[i]==c[i+1]) {
            f[i]=f[i+2]+1;
            for (int j=0;j<26;++j) g[i][j]=g[i+2][j];
            if (i+2<=n)g[i][c[i+2]-'a']=i+2;
        }
        else {
            k=g[i+1][c[i]-'a'];
            if (k==0) continue;
            f[i]=1+f[k+1];
            for (int j=0;j<26;++j) g[i][j]=g[k+1][j];
            g[i][c[k+1]-'a']=k+1;
        }
    }
    ll ans=0;
    for (int i=1;i<=n;++i)
        ans+=f[i];
    cout<<ans;

}
