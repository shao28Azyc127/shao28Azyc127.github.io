#include <bits/stdc++.h>
#define int long long
#define MAXN 100010
#define INF LONG_LONG_MAX
using namespace std;
int n,d,v[MAXN],a[MAXN],ans,ans2=INF;
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>d;
    for(int i=2;i<=n;i++) cin>>v[i],v[i]+=v[i-1];
    for(int i=1;i<=n;i++) cin>>a[i];
    int pos=1,now=0;
    while(now<v[n]&&pos<n)
    {
        while(now>=v[pos+1]&&pos+1<=n) pos++;
        int sheng=ceil(1.0*(v[n]-now)/d);
        ans2=min(ans2,ans+a[pos]*sheng);
        bool flag=0;
        for(int i=pos+1;i<=n;i++)
            if(a[i]<a[pos])
            {
                int sheng=ceil(1.0*(v[i]-now)/d);
                ans+=a[pos]*sheng;
                now+=d*sheng;
                pos=i;
                flag=1;
                break;
            }
        if(!flag)
        {
            int sheng=ceil(1.0*(v[n]-now)/d);
            ans+=a[pos]*sheng;
            now+=d*sheng;
            pos=n;
        }
    }
    cout<<min(ans,ans2)<<endl;
    return 0;
}
