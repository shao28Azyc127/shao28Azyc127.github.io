#include<iostream>
using namespace std;
long long n,d,v[100005],a[100005],cnt,ya;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n,d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans==v[1],i=2,x=a[1];
    while(i<n)
    {
        if(x>a[i])
        {
            x=a[i];
            i++;
            if(ans%d!=0)cnt=cnt+(ans/d+1)*x;
            else cnt+=ans/d*x;
            ya+=ans;
            ans=0;
        }
        else
        {
            ans+=v[i];
            i++;
        }
    }
    int ye;
    for(int i=1;i<=n;i++)
    {
        ye+=v[i];
    }
    if(ya!=ye)cnt+=(ye-ya)*x;
    cout<<cnt;
    return 0;
}