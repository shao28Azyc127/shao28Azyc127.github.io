#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int v[200000],a[200000],n,i,s=0,d;
    cin>>n>>d;
    for(i=1;i<n;i++){
	    cin>>v[i];
	    s=s+v[i];
	}
	for(i=1;i<=n;i++){
	    cin>>a[i];
	}
    if(s%d==0) cout<<s/d*a[1];
    else cout<<(s/d+1)*a[1];
    return 0;
}
