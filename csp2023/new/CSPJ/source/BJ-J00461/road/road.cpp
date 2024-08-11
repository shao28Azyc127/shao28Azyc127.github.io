#include<bits/stdc++.h>
using namespace std;

const long double ld=1.0;

int n,d;
int v[100005];
int a[100005];
int minn;
long long juli;
long long ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for (int i=1;i<=n-1;i++)
    {
        scanf("%d",&v[i]);
    }
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    minn=1;juli=0;
    for (int i=2;i<=n;i++)
    {
        if (juli<v[i-1])
        {
            long long tmp=ceil(ld*(v[i-1]-juli)/d);
            //tmp=距离/每升油可走距离=耗油数（向上取整）
            juli+=tmp*d;
            ans+=tmp*a[minn];
        }
        juli-=v[i-1];
        if (a[i]<a[minn])
        {
            minn=i;
        }
    }
    cout<<ans;
    return 0;
}
