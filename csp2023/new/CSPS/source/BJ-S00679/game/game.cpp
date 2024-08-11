#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,a[N],f[N],g[N],ans;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        a[i]=c-'a'+1;
        int p=i-1;
        while(a[p]!=a[i]&&p>0){
            p=g[p]-1;
        }
        if(p<=0) continue;
        g[i]=p;
        ans+=f[i]=1+f[p-1];
    }
    cout<<ans;
    return 0;
}