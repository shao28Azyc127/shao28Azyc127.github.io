#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int a[500003],b[500003];
int ac[500003],bc[500003];
bool flaga[500003],flagb[500005];
int main()
{
     freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
     cin>>c>>n>>m>>q;
     cin>>a[1]>>b[1];
    if(a[1]!=b[1])cout<<1<<endl;
    else cout<<0<<endl;
    for(int i=1;i<=q;i++)
   {
       int x,y;
     int z;
       cin>>x>>y;
      if(x==1)cin>>z>>a[1];
      if(y==1)cin>>z>>b[1];
      if(a[1]!=b[1])cout<<1<<endl;
       else cout<<0<<endl;
    }
      return 0;
}
