#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout)
    long long n,d,v[100005],a[100005];
    cin>>n>>d;
    for(long long i=0;i<n-1;i++){
    	cin>>v[i];
	}
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long ans=0,x=0,h=0,min=100005;
	for(int i=0;i<n;i++){
		if(a[i]<min||i==n-1){
			ans+=(min*h+d-1)/d;
			min=a[i];
			h=h%d;
		}
		h+=v[i];
	}
	cout<<ans;
    return 0;
}