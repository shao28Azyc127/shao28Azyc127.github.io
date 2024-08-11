#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int dp[8010][8010];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>s;
	for(int i=1;i<n;i++){
		if(s[i]==s[i-1])dp[i-1][i]=true;
	}
	for(int len=2;len<n;len++){
		for(int l=0;l+len<n;l++){
			int r=l+len;
			for(int k=l;k+1<=r;k++){
				dp[l][r]|=dp[l][k]&&dp[k+1][r];
			}
			if(r-l>2&&s[l]==s[r])dp[l][r]|=dp[l+1][r-1];
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(dp[i][j]){
				cnt++;
			}
		}
	}
	cout<<cnt;
}