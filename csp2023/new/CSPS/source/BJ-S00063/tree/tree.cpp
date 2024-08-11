#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],b[100005],c[100005];
const int INF=4e18;
int lowbit(int x){return x&(-x);}
int con[100005];
int lg[1000005];
int _ppc(int x){
	int ret=0;
	while(x){
		ret++;
		x-=lowbit(x);
	}
	return x;
}
int lim[100005];
int dp[1100005],ppc[1100005],edg[1100005];
int calc(int tim,int id){
	int l=tim,r=INF;
	int bg=b[id]+tim*c[id];
	while(l<r){
		int mid=l+r>>1;
		__int128 chk=0;
		if(mid<=lim[id]) chk=((__int128)1)*(2*bg+(mid-tim)*c[id])*(mid-tim+1)/2;
		else{
			if(tim<=lim[id]) chk=((__int128)1)*(2*bg+(lim[id]-tim)*c[id])*(lim[id]-tim+1)/2+mid-lim[id];
			else chk=mid-tim+1;
		}
		if(chk>=(__int128)a[id]) r=mid;
		else l=mid+1;
	}
	return l;
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	lg[0]=1;
	for(int i=1;i<=1000000;i++) lg[i]=(i>>1)+1;
	int n,u,v;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		if(c[i]<0) lim[i]=(b[i]-1)/(-c[i])+1;
		else lim[i]=INF;
	}
	if(n<=20){
		for(int i=1;i<n;i++){
			scanf("%lld%lld",&u,&v);
			con[u]|=(1<<(v-1));
			con[v]|=(1<<(u-1));
		}
		for(int i=1;i<(1<<n);i++) ppc[i]=_ppc(i);
		for(int i=1;i<(1<<n);i++){
			int j=i^lowbit(i);
			edg[i]=edg[j]|con[lg[lowbit(i)]];
		}
		for(int i=2;i<(1<<n);i++) dp[i]=INF;
		dp[1]=calc(1,1);
		for(int i=1;i<(1<<n);i++){
			if(dp[i]==INF) continue;
			for(int j=1;j<=n;j++){
				if((edg[i]&(1<<(j-1)))==0||((i&(1<<(j-1)))>0)) continue;
				dp[i^(1<<(j-1))]=min(dp[i^(1<<(j-1))],max(dp[i],calc(ppc[i]+1,j)));
			}
		}
		printf("%lld\n",dp[(1<<n)-1]);
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,calc(i,i));
		printf("%lld\n",ans);
	}
	return 0;
}