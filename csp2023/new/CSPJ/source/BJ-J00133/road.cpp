#include<bits/stdc++.h>
using namespace std;
int v[100005];
int a[100005];
long long sum[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+v[i];
	}
	int cur=0;
	long long ans=0,km=0;
	for(int i=1;i<n;i++){
		if(i!=cur+1){
			continue;
		}
		cur=n-1;
		for(int j=i+1;j<n;j++){
			if(a[j]<=a[i]){
				cur=j-1;
				break;
			}
		}
		long long tmp=sum[cur]-sum[i-1]-km;
		long long cnt=tmp/k+(tmp%k==0?0:1);
		ans+=cnt*a[i];
		km=cnt*k-tmp;
	}
	cout<<ans;
	return 0;
}