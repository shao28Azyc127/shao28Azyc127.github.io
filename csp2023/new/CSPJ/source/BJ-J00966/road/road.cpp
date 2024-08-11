#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	int u,v,id;
}a[100005];
int p[100005];
long long dp[15][900005];
int n;
long long d;
bool cmp(node x,node y){
	return x.v<y.v;
}
void work1(){
		p[n]=0;
		p[n-1]=a[n-1].u;
		for(int i=n-2;i>=1;i--){
			p[i]=p[i+1]+a[i].u;
		}
		sort(a+1,a+1+n,cmp);
		int x;
		x=n;
		long long ans1=0;
		for(int i=1;i<=n;i++){
			if(x==1){
				break;
			}
			if(a[i].id<x){
				ans1+=((p[a[i].id]-p[x])/d)*a[i].v;
				x=a[i].id;
			}
		}
		printf("%lld",ans1);
}
long long chu(long long x,long long y){
	if(x%y==0){
		return x/y;
	}
	return (x/y)+1;
}
int jl(int x,int y){
	if(x>y){
		return p[y]-p[x];
	}
	else{
		return p[x]-p[y];
	}
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool f=1,f2=1;
	long long cnt=0,ans1;
	ans1=0x3f3f3f3f;
	cin>>n>>d;
	for(int i=1;i<n;i++){
		scanf("%d",&a[i].u);
		if(a[i].u%d!=0){
			f=0;
		}
		cnt+=a[i].u;
	}
	for(int i=1;i<=n;i++){
		a[i].id=i;
		scanf("%d",&a[i].v);
		if(i!=1&&a[i].v<a[1].v){
			f2=0;
		}
	}
	if(f2==1){
		cout<<a[1].v*chu(cnt,d);
		return 0;
	}
	if(f==1||n>=15){
		work1();
		return 0;
	}
	for(int i=n;i>=2;i--){
		a[i].u=a[i-1].u;
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<=(cnt/d)+1;i++){
		dp[1][i*d]=i*a[1].v;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=cnt;j++){
			dp[i][j]=dp[i-1][j+a[i].u];
			for(int k=0;k<=(j/d);k++){
				dp[i][j]=min(dp[i][j],dp[i][j-k*d]+a[i].v*k);
			}
			if(i==n){
				ans1=min(ans1,dp[n][j]);
			}
		}
	}
	cout<<ans1;
	return 0;
}