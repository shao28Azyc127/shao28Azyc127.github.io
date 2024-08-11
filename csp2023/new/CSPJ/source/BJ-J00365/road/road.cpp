#include<iostream>
#include <cstdio>
using namespace std;
const int N=1e5+10;
long long n,d,a[N],v[N],minn=1e5+100,ans,ans1=0,l,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	ans=1;
	while(ans<n){
		minn=min(minn,v[ans]);
		if((a[ans]-l)%d==0){
			ans1+=((a[ans]-l)/d)*minn;
			l=0;
			ans++;
		}
		else{
			ans1+=((a[ans]-l)/d+1)*minn;
			k=((a[ans]-l)/d+1);
			l+=k*d-a[ans];
			ans++;
		}
	}
	cout<<ans1<<endl;
	return 0;
}
