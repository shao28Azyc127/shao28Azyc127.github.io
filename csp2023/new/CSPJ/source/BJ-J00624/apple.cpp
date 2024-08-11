#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n,ans1=0,ans2=0;
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%lld",&n);
	while(n>3){
		ans1++;
		if((n-1)/3*3==(n-1)&&ans2==0){
			ans2=ans1;
		}
		if(n/3*3!=n) n-=n/3+1;
		else n-=n/3;
	}
	if(n<=3) ans1+=n;
	if(ans2==0) ans2=ans1;
	printf("%lld %lld",ans1,ans2);
	return 0;
}
	