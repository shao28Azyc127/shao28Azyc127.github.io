#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,v[100005],a[100005],l=0,ans=0,k,m,b[100005],p,el;
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>v[i];
		l+=v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	k=a[1];
	sort(a,a+n);
	if(k==a[1]){
		if(l%d==0){
			ans=l/d;
		}
		else{
			ans=1+l/d;
		}
		ans*=a[1];
	}
	else{
		m=k;
		for(int i=1;i<n;i++){
			m=min(m,b[i]);
			v[i]-=el;
			if(v[i]%d==0){
				p=v[i]/d;
			}
			else{
				p=1+v[i]/d;
			}
			el=d*p-v[i];
			ans=ans+p*m;
		}
	}
	cout<<ans;
	return 0;
}