#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d,a[100010],v[100010];
int ans=0;
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
        cin>>v[i];
    cin>>a[1];
    int m=a[1],dis=v[1];
    int o=0;
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<m||i==n)
        {
            double b=(dis-o)/(d*1.0);
            if(b!=floor(b))
            {
                o=(floor(b)+1-b)*d;
                b=floor(b)+1;
            }
            ans+=b*m;
            m=a[i];
            dis=v[i];
        }
        else
            dis+=v[i];
    }
    cout<<ans;
    return 0;
}
