#include<bits/stdc++.h>
using namespace std;
long long v[100005],a[100005],pre[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,d,sum=0,minn=0x3f3f3f3f,k;
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>v[i];
		pre[i]=pre[i-1]+v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<minn){
			minn=a[i];
			k=i;
		}
	}
	sum=a[1]*ceil(pre[n]*1.0/d);
	if(pre[n]%d!=0){
		sum+=1;
	}
	cout<<sum;
	return 0;
}