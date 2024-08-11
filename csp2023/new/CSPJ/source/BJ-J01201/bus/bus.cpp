#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,x,y,z;
int main()
{
freopen("bus.in","r",stdin);
freopen("bus.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=m;i++)cin>>x>>y>>z,ans+=z;
cout<<ans;
return 0;
}
