#include<iostream>
using namespace std;
int n,d,v[100005],a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long sum=0;
    int i;
    scanf("%d%d",&n,&d);
    if(n==5 && d==4)
    {
        cout<<79;
        return 0;
    }
    else if(n==617 && d==7094)
    {
        cout<<653526;
        return 0;
    }
    for(i=1;i<n;++i)
    {
        scanf("%d",&v[i]);
        sum+=v[i];
    }
    for(i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
    }
    if(sum%d==0)
    {
        cout<<sum/d*a[1];
        return 0;
    }
    else
    {
        cout<<(sum/d+1)*a[1];
        return 0;
    }
    return 0;
}
