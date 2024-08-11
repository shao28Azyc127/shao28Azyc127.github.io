#include<iostream>
using namespace std;
int a[2000006],dp[8005][8005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,ans1=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		a[i]=ch-'a';
	}
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]){
			dp[i][i+1]=1;
			ans1++;
		}
	}
	for(int l=4;l<=n;l+=2){
		for(int i=1;i<=n;i++){
			int j=i+l-1;
			if(j>n){
				break;
			}
			if(a[i]==a[j]){
				dp[i][j]=dp[i+1][j-1];
			}
			if(dp[i][j]==1){
				ans1++;
				continue;
			}
			for(int k=i;k<j;k++){
				if(dp[i][k]&&dp[k+1][j]){
					dp[i][j]=1;
					ans1++;
					break;
				}
			}
		}
	}
	cout<<ans1;
	return 0;
}