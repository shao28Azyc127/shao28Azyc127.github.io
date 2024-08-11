#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[10000010],a[100010],s[100010];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(s,0,sizeof(s));
    int n,d;
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        s[i]=s[i-1]+x;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=s[n];i++) f[i]=1e18;
    for(int i=1;i<=n;i++){
        for(int j=s[i]+d;j<=s[n];j++) f[j]=min(f[j],f[j-d]+a[i]);
    }
    cout<<f[s[n]];
}
