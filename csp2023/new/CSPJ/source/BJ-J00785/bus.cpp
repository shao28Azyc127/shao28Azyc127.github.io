#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>a>>b;
        ans=max(ans,b);
    }
    int i=max(k,ans);
    for(;!(i%k==0&&i%ans==0);i++)
    {

    }
    if(k==ans)
    {
        cout<<i+k;
    }
    else
    {
        cout<<i;
    }
    return 0;
}