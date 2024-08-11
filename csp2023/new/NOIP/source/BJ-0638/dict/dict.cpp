#include<bits/stdc++.h>
using namespace std;
int n,m;
int a1[3031],a2[3031];
int main()
{
freopen("dict.in","r",stdin);
freopen("dict.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
    string st;
    cin>>st;
    a1[i]=10086;
    for(int j=1;j<=m;j++)
    {
        a1[i]=min((int)st[j-1],a1[i]);
        a2[i]=max((int)st[j-1],a2[i]);
    }
}
    for(int i=1;i<=n;i++)
    {
        int k=1;
        for(int j=1;j<=n;j++)
        {
           if(i==j) continue;
           if(a1[i]>=a2[j])
           {
                k=0;
                break;
           }
    }
cout<<k;
}
return 0;
}