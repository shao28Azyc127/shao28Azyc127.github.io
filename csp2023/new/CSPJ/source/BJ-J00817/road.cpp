#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,d,l,ans;
int v[100005];
int a[100005];
int b[100005];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++) {
		cin>>v[i];
		l+=v[i];
	}
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		b[i-1]=a[i];
	}
	sort(b,b+n);
	if(b[0]!=a[1]) {
		ans=-11;
	}
	ans+=ceil(l/1.0/d)*a[1];
	cout<<ans<<endl;
	return 0;
}

/*
	long long maxnum=20;
	srand(time(NULL));
	cout<<rand()%maxnum;
*/
