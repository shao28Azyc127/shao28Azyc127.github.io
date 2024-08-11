#include<iostream>
#include<cstdio>
using namespace std;
int v[100005],a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,minn=100005;
	cin>>n>>d;
	for(int i=1;i<=n-1;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<minn){
			minn=a[i];
		}
	}
	if(minn==a[1]){
		int sum=0;
		for(int i=1;i<=n-1;i++){
			sum+=v[i];
		}
		int x=int(sum/(d*1.0)+1);
		cout<<x*a[1];
	}
	return 0;
}
