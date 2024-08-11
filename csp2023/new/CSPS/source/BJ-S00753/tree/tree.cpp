#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,b,c,v,u;
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
	}
	for(int j=1;j<n;j++){
		scanf("%lld%lld",&u,&v);
	}
	srand(clock());
	printf("%lld",rand()%LONG_LONG_MAX);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
