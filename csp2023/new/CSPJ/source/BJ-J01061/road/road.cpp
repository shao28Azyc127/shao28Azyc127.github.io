#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
long long a[200010],b[200010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d;
    cin>>n>>d;
    for(int i=2;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    long long minn=b[1];
    long long sum=0,now=0,sumr=0;
    for(int i=2;i<=n;i++)
    {
        sumr+=a[i];
        if(sumr<=now)
        {
            minn=min(minn,b[i]);
            continue;
        }
        long long oil=long(ceil(1.0*(sumr-now)/d));
        sum+=oil*minn;
        now+=1ll*oil*d;
        minn=min(minn,b[i]);
    }
    cout<<sum<<endl;
    return 0;
}