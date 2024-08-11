#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;
int n,d,v[maxn],a[maxn],sum,p;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n-1;i++)cin>>v[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++){
		if(a[1]<a[i]) p++;
	}
	if(p==(n-1)){
		int q;
		for(int i=1;i<=n-1;i++)q=q+v[i];
		sum=(q+d-1)/d;
		cout<<sum;
	}
	return 0;
}
