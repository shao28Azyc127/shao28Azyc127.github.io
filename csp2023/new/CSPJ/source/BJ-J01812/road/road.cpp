#include<bits/stdc++.h>
using namespace std;

struct qqq{
	int id;
	long long num;
}p[100005];

int n;
long long d;
long long v[100005],s[100005],a[100005];

bool cmp(qqq ax,qqq bx){
	if(ax.num!=bx.num){
		return ax.num<bx.num;
	}
	else{
		return ax.id<bx.id;
	}
}

int len,b[100005];
long long ans,cnt,l;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%lld",&n,&d);
	for(int i=2;i<=n;++i){
		scanf("%lld",&v[i]);
		s[i]=s[i-1]+v[i];//1~i
	}
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		p[i].id=i;
		p[i].num=a[i];
	}
	sort(p+1,p+n+1,cmp);
	b[0]=n;
	for(int i=1;i<=n;++i){
		if(len==0 || p[i].id<b[len]){
			++len;
			b[len]=p[i].id;
		}
	}
	for(int i=len;i>=1;--i){
		l=s[b[i-1]]-s[b[i]]-cnt;
		ans+=(l+(d-1))/d*a[b[i]];
		cnt=((l+(d-1))/d)*d-l;
	}
	printf("%lld",ans);
	return 0;
}
