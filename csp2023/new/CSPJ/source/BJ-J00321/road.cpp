#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,l=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		l+=v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=l/a[1]/d;
	cout<<ans;
	return 0;
} 