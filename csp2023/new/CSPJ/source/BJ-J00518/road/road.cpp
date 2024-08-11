#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int u[N],a[N],mi[N],mz[N];//xu yao zai na xie zhan jia you;
long long c[N];//qian zhui he
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,i,nn=0;
	long long ans=0,ykm=0;
	mi[0]=2147483647;
	scanf("%d%d",&n,&d);
	for(i=1;i<n;++i){
		scanf("%d",&u[i]);
		c[i+1]=c[i]+u[i];
	}
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		mi[i]=min(mi[i-1],a[i]);
		if(mi[i]<mi[i-1])mz[++nn]=i;
	}
	if(mz[nn]!=n)mz[++nn]=n;
	for(i=1;i<nn;++i){
		//jia you liang=ci zhan dao xia yi ge xu yao jia you de zhan de zong lu cheng
		long long jl=c[mz[i+1]]-c[mz[i]];
		long long yl=(jl-ykm-1)/d+1;
		ans+=(yl*a[mz[i]]);
		ykm+=(yl*d-jl);
	}
	printf("%lld",ans);
	return 0;
}
