#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,v[MAXN],a[MAXN],ans=0,q,s[MAXN],x=0,d,xx;
int main()
{
    freopen("road.in","r",stdin);
    cin>>n>>d;
    s[1]=0;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        s[i+1]=s[i]+v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    q=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[q]||i==n)
        {
            if(s[i]-s[q]-x<0)
            {
                xx=x-(s[i]-s[q]);
                if(xx>=s[i+1]-s[i]&&i<=n)
                {
                    q=i;
                    i++;
                    if(q==n)
                    {
                        cout<<ans<<endl;
                        return 0;
                    }
                }
            }
            if((s[i]-s[q]-x)%d==0)
            {
                ans+=(s[i]-s[q]-x)/d*a[q];
                x=0;
            }
            else
            {
                ans+=((s[i]-s[q]-x)/d+1)*a[q];
                x=(s[i]-s[q]-x+d)%d;
            }
            q=i;
        }
    }
    freopen("road.out","w",stdout);
    cout<<ans<<endl;
    return 0;
}
