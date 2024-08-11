// why rdfz has just 2 cpu too
// byd password wrong ??? XD
// 很符合我对 cash capture federation 的想象
// <<CSP-J2023l!2>>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=0;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,ans1=0,ans2=0;
	cin>>n;
	while(n){
		++ans1;
		if(n%3==1&&!ans2)ans2=ans1;
		n-=n/3+(n%3>0);
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}