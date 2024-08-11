#include<iostream>
#include<cstdio>
using namespace std;

long long n,d,a[1005],v[1005],ans,mnv=2e9,mnvi,s[1005],mnvl,mnvil;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdourt);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
        s[i]=s[i-1]+v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<mnv)
        {
            mnv=min(mnv,a[i]);
            mnvi=i;
        }
    }
    ans+=(s[n-1]-s[mnvi-1])*1.0/d*mnv;
    while(mnvi!=1)
    {
        mnvl=mnv;
        mnvil=mnvi;
        mnv=2e9;
        for(int i=1;i<=mnvi-1;i++)
        {
            if(a[i]<mnv)
            {
                mnv=min(mnv,a[i]);
                mnvi=i;
            }

        }
        ans+=(a[mnvil-1]-a[mnvi-1])*1.0/d*mnv;
    }

    cout<<ans<<endl;

    return 0;
}