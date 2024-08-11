#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ll n;cin>>n;
	ll ans1=0,ans2=0;bool flag=0;
	while(n){
		ans1++;
		ll k=(n-1)/3;ll m=1+3*k;
		if(m==n&&flag==0){flag=1;ans2=ans1;}
		ll cal=1+(m-1)/3;
		n-=cal;
	}
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}
