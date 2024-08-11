#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e5+5;
int n,a[MAXN],b[MAXN],c[MAXN],u[MAXN],v[MAXN];
int ans;
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    int maxi=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        b[i]=max(1ll,b[i]);
        maxi=max(maxi,a[i]/b[i]);
    }
    for(int i=1;i<n;i++){
        cin>>u[i]>>v[i];
    }
    cout<<maxi;
    return 0;
}
