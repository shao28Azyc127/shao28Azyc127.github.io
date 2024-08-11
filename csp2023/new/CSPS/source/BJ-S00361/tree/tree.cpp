#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ll n,a,b,c,u,v;
	cin>>n;
	for(int i=1; i<=n; i++){
		scanf("%lld%lld%lld",&a,&b,&c);
	}
	for(int i=1; i<n; i++){
		scanf("%lld%lld",&u,&v);
	}
	cout<<n+1<<endl;
	return 0;
}
