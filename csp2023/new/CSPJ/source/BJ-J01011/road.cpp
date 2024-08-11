#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,j;
    long long x=0,cur=0;
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        long long sum=0;
        for(j=i+1;j<=n;j++)
        {
            if(a[j]<=a[i])
            {
                sum+=v[j-1];
                break;
            }
            else sum+=v[j-1];
        }
        long long y=sum-cur;
        x+=(y+d-1)/d*a[i];
        cur=(y+d-1)/d*d+cur-sum;
        i=j-1;
    }
    cout<<x;
    return 0;
}
