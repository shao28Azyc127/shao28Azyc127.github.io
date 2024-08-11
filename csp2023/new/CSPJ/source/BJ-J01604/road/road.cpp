#include<bits/stdc++.h>
using namespace std;
long long n,d,v[100005],a[100005],ans=0,minn=100005,j=0,l=0;
bool flag=true;
int main()
{
    cin>>n>>d;
    for(int i=0;i<n-1;i++) cin>>v[i];
    for(int i=0;i<n;i++) cin>>a[i];
    l=v[0];
    for(int i=1;i<n;i++)
    {
    	if(a[i]<a[j])
    	{
    	    ans+=(l+l%d)/d*a[j];
    	    j=i;
    	    flag=false;
    	    l=0;
    	}
    	else
    	{
    	    l+=v[i];
    	}
    }
    if(flag) ans+=(l+l%d)/d*a[0];
    cout<<ans;
    return 0;
}