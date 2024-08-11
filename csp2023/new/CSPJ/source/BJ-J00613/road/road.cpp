#include<bits/stdc++.h>
using namespace std;

int a[1000000];
int b[1000000];
int c[1000000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	long long sum=0;
	int ans=0;
	for(int i=1;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sum/=d;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    ans+=a[1]/d+1;
    ans*=b[1];
    int in=0;
    for(int i=2;i<=n;i++)
    {
        if(a[1]>a[i])
        {
            in=1;
            break;
        }
    }
    if(in==0)
    {
        cout<<sum*a[1];
        return 0;
    }
    if(n==1)
    {
        int l=(a[1]/d)*b[1];
        cout<<l;
        return 0;
    }
    int cnt=1;
    b[n]=10000000;
    for(int i=2;i<n;i++)
    {
        if(b[i]<=b[i+1])
        {
            c[cnt]=i;
            cnt++;
        }
    }
    cnt--;
    for(int i=1;i<cnt;i++)
    {
        int l=0;
        for(int j=c[i];j<c[i+1];j++)
        {
            //cout<<c[i]<<" "<<c[i+1];
            l+=a[j]/d+1;
        }
        l*=b[c[i]];
        ans+=l;
    }
    cout<<ans+n-1;
	return 0;
}
