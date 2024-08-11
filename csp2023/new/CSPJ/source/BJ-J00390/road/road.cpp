#include <iostream>
#include <cmath>
using namespace std;
long long d,n,MIN=100000;
long long l[100005],price[100005];
long long check(long long abc)
{
    long long sum=0;
    if(abc==n)
    {
        return 0;
    }
    for(long long i=abc;i<n;i++)
    {
        for(long long j=i;j<=n;j++)
        {
            sum=0;
            for(long long w=i;w<j;w++)
            {
                sum+=l[w];
            }
            sum=sum*price[i]+check(j+1);
            MIN=min(MIN,sum);
        }
    }
    return MIN;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;

    for(int i=1;i<=n;i++)
    {
        cin>>price[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        cin>>l[i];
    }
    cout<<check(1);
    return 0;
}
