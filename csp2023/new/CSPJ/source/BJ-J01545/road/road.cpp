#include<bits/stdc++.h>
using namespace std;

int a[100010];
int v[100010];
int b[100010];
int s[100010];
int main()
{
    freopen("road.in","w",stdin);
    freopen("road.out","r",stdout);
    a[0]=1e9;
    int n,d,cnt=0,ans=0,km=0;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
        s[i+1]=s[i]+v[i];
    }
    for(int i=1;i<=n-1;i++)
    {
     	cin>>a[i];
     	if(a[i]<a[i-1])
        {
            b[++cnt]=i;
        }
    }
    b[++cnt]=n;
    for(int i=1;i<=cnt-1;i++)
    {
        int sy=(s[b[i+1]]-s[b[i]]-km)/d;
        if(sy*d+km<s[b[i+1]]-s[b[i]])
        {
            sy++;
        }
        km+=d*sy;
        ans+=sy*a[b[i]];
        km-=s[b[i+1]]-s[b[i]];
        cout<<km<<" "<<sy<<" "<<ans<<" ";
    }
    cout<<ans;
    return 0;
}