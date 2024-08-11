#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int dp[100005];
int sum[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n , m;
	cin >> n >> m;
	for(int i = 1 ; i <= n-1 ; i++){
		cin >> a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> b[i];
	}
	dp[n]=0;
	for(int i = n ; i >= 1 ; i--){
		if(b[i]>b[i-1]){
			dp[i-1]=dp[i]+1;
		}
		else{
			dp[i-1]=0;
		}
		//cout << dp[i]<<endl;
	}
	long long tmp=1,cnt=0,ans=0;
	while(tmp<n){
		if(((sum[tmp+dp[tmp]]-sum[tmp-1])-cnt)%m==0){
			//cout << sum[tmp+dp[tmp]]-sum[tmp-1]<<" " <<((((sum[tmp+dp[tmp]]-sum[tmp-1])-cnt)/m))*b[tmp]<<" ";
			ans+=((((sum[tmp+dp[tmp]]-sum[tmp-1])-cnt)/m))*b[tmp];
			cnt=0;
			tmp+=(1+dp[tmp]);
			//cout << cnt<<endl;
		}
		else{
			//cout << sum[tmp+dp[tmp]]-sum[tmp-1]<< " "<<((((sum[tmp+dp[tmp]]-sum[tmp-1])-cnt)/m)+1)*b[tmp]<<" ";
			ans+=((((sum[tmp+dp[tmp]]-sum[tmp-1])-cnt)/m)+1)*b[tmp];
			cnt=((((sum[tmp+dp[tmp]]-sum[tmp-1])-cnt)/m)+1)*m-((sum[tmp+dp[tmp]]-sum[tmp-1])-cnt);
			tmp+=(1+dp[tmp]);
			//cout << cnt<<endl;
		}
	}
	cout << ans;
	return 0;
}
