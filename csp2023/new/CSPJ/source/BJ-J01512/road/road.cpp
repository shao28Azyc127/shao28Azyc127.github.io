#include<bits/stdc++.h>
using namespace std;
int v[100005];
int a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=2;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	long long l=1,r=1,mon=0;
	long long yu=0,sum,jia;
	while(r<n){
		//cout<<1<<endl;
		//cout<<l<<" "<<r<<endl;
		while(r<n&&a[r+1]>a[l]){
			r++;
		}
		sum=0;
		for(int i=l+1;i<=r+1;i++)sum+=v[i];
		if(sum<=yu){
			yu-=sum;
			continue;
		}
		sum-=yu;
		jia=(sum+d-1)/d;
		mon+=jia*a[l];
		yu=jia*d-sum;
		l=r+1;
		r=l;
	}
	cout<<mon<<endl;
	return 0;
}