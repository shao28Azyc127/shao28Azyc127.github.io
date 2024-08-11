#include<bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,s=1e9;
    long long ans=0,l=0;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        if(b[i]<s)
        {
            ans+=(l/d)*s;
            int f=0;
            if(l%d!=0&&i!=1)
            {
                ans+=s;
                f=((l/d)+1)*d-l;
            }
            s=b[i];
            l=a[i]-f;
        }
        else
        {
            l+=a[i];
        }
    }
    ans+=(l/d)*s;
    if(l%d!=0)
        ans+=s;
    cout<<ans;
    return 0;
}
