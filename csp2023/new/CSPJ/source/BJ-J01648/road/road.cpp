#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,d,v[N],a[N],minn=1e6,t=-1,p=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<minn){
			minn=a[i];
			t=i;
		}
	}
	if(t==1){
		int sum;
		for(int i=1;i<=n;i++){
			sum+=v[i];
		}
		if(sum%d==0){
			cout<<sum/d*minn;
			return 0;
		}else{
			cout<<(sum/d+1)*minn;
			return 0;
		}
	}else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=v[i]/d*a[i];
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
