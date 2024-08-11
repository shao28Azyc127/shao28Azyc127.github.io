#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,d,a[N],v[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long i=1,left=0;
    long long ans=0;//653526
    while(i<n)
    {
        long long sum=v[i],next=i+1;
        while(a[next]>a[i])
        {
            sum+=v[next++];
        }
        if(next==n)
        {
            sum-=left;
            left=0;
        }
        else 
        {
            while(left>(sum%d)&&sum%d!=0)
            {
                sum-=sum%d;
                sum--;
                left-=sum%d;
                left--;
            }
        }
        
        
        long long k=sum/d;
        if(sum%d!=0) k++;
        left+=k*d-sum;
     //   cout<<k<<" "<<i<<" "<<next<<endl;
        ans+=k*a[i];
        i=next;
    }
    cout<<ans;
    return 0;
}