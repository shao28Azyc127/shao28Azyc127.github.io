#include<bits/stdc++.h>
using namespace std;
int a[100005],w[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long sum=0,n,d;
	cin>>n>>d;
	for(int i=1;i<=n-1;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n; i++){
		cin>>w[i];
	}
	cout<<(sum+d-1)/d*w[1];
	return 0;
}