#include<bits/stdc++.h>
using namespace std;
int c,m,q,n,mx,my;
int x[500007],y[500007];
int main()
{
freopen("expand.in","r",stdin);
freopen("expand.out","w",stdout);
cin>>c>>n>>m>>q;
for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        mx=min(mx,x[i]);
    }
for(int i=1;i<=m;i++)
{
    cin>>y[i];
    my=min(my,y[i]);
}
if(mx>=y[m]||my<=x[n]||(mx>=y[1]&&my<=x[1]))
{
    cout<<0;
}
else cout<<1;
return 0;
}
