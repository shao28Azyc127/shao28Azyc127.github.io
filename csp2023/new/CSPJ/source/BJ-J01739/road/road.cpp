#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
int ans=0,n,d,a[maxn],v[maxn];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int cnt=0;
    int MIN=1e10+10;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
        cnt+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        MIN=min(MIN,a[i]);
    }
    if(MIN==a[1])
    {
        cout<<MIN*(cnt/d)<<endl;
        return 0;
    }
    int l=0;
    int Min=a[1];
    for(int i=1;i<=n-1;i++)
    {
        if(a[i]>=Min)
        {
            l+=v[i];
            //cout<<i<<endl;
        }
        else
        {
            int p=l/d;;
            if(p*d<l) p++;
            ans+=p*Min;
            l=v[i];
            Min=a[i];
        }
    }
    int p=l/d;;
    if(p*d<l) p++;
    ans+=p*Min;
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
