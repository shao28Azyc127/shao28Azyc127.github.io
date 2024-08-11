#include<iostream>
using namespace std;
struct node{
	int s,u;
}a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,d;
	cin>>n>>d;
	int x=0;
	a[x].s=1000000;
	long long sum=0,ans=0;
	for(int i=1;i<n;i++){
		cin>>a[i].u;
		sum+=a[i].u;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		if(a[i].s<a[x].s) x=i;
	}
	if(x==1){
		int c=sum/d;
		if(sum%d!=0) c++;
		cout<<(long long)c*a[1].s;
		return 0;
	}
	long long c=0;
	int v=0;
	for(int i=1;i<n;i++){
		if(i<v) continue;
		else v=0;
		if(a[i].s>a[i+1].s){
			if(c<a[i].u){
				int b=a[i].u-c;
				if(b%d==0) ans=ans+b/d*a[i].s;
				else ans=ans+(b/d+1)*a[i].s;
				c=c+(b/d+1)*d-b;
			}else c-=a[i].u;
			sum-=a[i].u;
		}else{
			if(x==i){
				if(sum%d==0) ans+=sum/d*a[i].s;
				else ans+=(sum/d+1)*a[i].s;
				cout<<ans;
				return 0;
			}
			long long e=a[i].u;
			for(int j=i+1;j<n;j++){
				if(a[i].s<=a[j].s){
					e+=a[j].u;
					continue;
				}
				v=j;
				sum-=e;
				if(c<e){
					e-=c;
					c=0;
				}
				if(e%d==0) ans=ans+e/d*a[i].s;
				else{
					ans+=(e/d+1)*a[i].s;
					c=c+(e/d+1)*d-e;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}