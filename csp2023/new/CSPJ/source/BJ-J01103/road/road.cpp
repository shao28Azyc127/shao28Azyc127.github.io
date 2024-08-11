#include <iostream>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int v[100010],a[100010];
    int minp=100010,minn;
    long long s=0;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        s+=v[i];
    }

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<minp)
        {
            minp=a[i];
            minn=i;
        }
    }
    cout<<minp*s<<endl;
    return 0;
}
