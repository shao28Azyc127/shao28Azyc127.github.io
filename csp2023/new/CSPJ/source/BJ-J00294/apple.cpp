#include<iostream>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n,ans=0,d=0,f=0;
	cin>>n;
	while(n){
		long long t=n/3;
		if(t*3!=n)t++;
		if(!f&&t+(t-1)*2==n)d=ans+1,f=1;
		n-=t;
		ans++;
	}
	cout<<ans<<' '<<d;
	return 0;
}