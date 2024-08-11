#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int v[N],a[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    int t=0;
    int minn=1e5+10;
    int ans=0;
    cin>>n>>d;
    for(int i=1;i<n;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
        minn=min(minn,a[i]);
        ans+=((ceil)((v[i]*1.0)/d))*minn;
        if(((ceil)((v[i]*1.0)/d))-d+t>=v[i])
            ans-=minn,t=((ceil)((v[i]*1.0)/d))-d+t-v[i];
        else t+=((ceil)((v[i]*1.0)/d))*d-v[i];
    }
    printf("%d",ans);
    return 0;
}
