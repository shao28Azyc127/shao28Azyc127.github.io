#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,m,a,b,c,de;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	for(ll i=1;i<=t;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		de=b*b-4*a*c;
		if(de<0){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<(-1*b+sqrt(de))/2*a<<endl;
	}
	return 0;
}
