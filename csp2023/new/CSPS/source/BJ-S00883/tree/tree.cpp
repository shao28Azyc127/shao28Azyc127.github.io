#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,ans,u,v;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;cin>>n;int ans=0;
    for(int i=1;i<=n;i++) cin>>a>>b>>c,ans+=a+b+c;
    for(int i=1;i<n;i++) cin>>u>>v,ans+=u+v;
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
