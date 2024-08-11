#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int N=1e5+10;
int n,d,a[N],b[N],pre[N];
void ipt(){
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
}
void solve(){
	for(int i=2;i<=n;i++) pre[i]=pre[i-1]+a[i-1];
	int now=b[1];
	int pos=1;
	int rem=0;
	int ans=0;
	for(int i=2;i<=n;i++){
		if(i==n){
			int dis=pre[n]-pre[pos]-rem;
			int f=dis/d+(dis%d==0?0:1);
			ans+=b[pos]*f;
			rem=f*d-dis;
			break;
		}
		else if(b[i]<now){
			int dis=pre[i]-pre[pos]-rem;
			int f=dis/d+(dis%d==0?0:1);
			ans+=b[pos]*f;
			rem=f*d-dis;
			now=b[i];
			pos=i;
		}
	}
	printf("%lld\n",ans);
}  
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ipt();
	solve();
	return 0;
}