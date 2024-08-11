#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans,d,v[N],dp[N][3],u[N];
int a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,minn=1e9+1;
	scanf("%d%d",&n,&d);
	int y;
	for(i=1;i<n;i++)scanf("%d",&u[i]),v[i]=v[i-1]+u[i];
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<minn)minn=a[i],y=i;
	}if(y==1){
		int c=v[n-1]%d;
		if(c==0)cout<<a[1]*c;
		else cout<<a[1]*(c+1);
		return 0;
	}
	if(u[1]%d==0){
		dp[1][1]=a[1];
		dp[1][2]=0;
		dp[1][0]=u[1]/d*a[1];
	}else{
		dp[1][1]=a[1];
		dp[1][2]=(u[1]/d+1)*d-u[1];
		dp[1][0]=(u[1]/d+1)*a[1];
	}
	for(i=2;i<n;i++){
		if(u[i]-dp[i-1][2]<=0){
			dp[i][0]=dp[i-1][0];
			dp[i][1]=min(dp[i-1][1],a[i-1]);
			if(u[i]-dp[i-1][2]==0)dp[i][2]=0;
			else dp[i][2]=abs(u[i-1]-dp[i][2]);
		}else{
			dp[i][1]=min(dp[i-1][1],a[i]);
			if((u[i-1]-dp[i-1][2])%d==0)dp[i][0]=dp[i-1][0]+((u[i]-dp[i-1][2])/d)*dp[i][1];
			else dp[i][0]=dp[i-1][0]+((u[i]-dp[i-1][2])/d+1)*dp[i][1];
			if((u[i]-dp[i-1][2])%d==0)dp[i][2]=((u[i]-dp[i-1][2])/d)*d-(u[i]-dp[i-1][2]);
			else dp[i][2]=((u[i]-dp[i-1][2])/d+1)*d-(u[i]-dp[i-1][2]);
		}
	}
	cout<<dp[n-1][0];
	return 0;
}
