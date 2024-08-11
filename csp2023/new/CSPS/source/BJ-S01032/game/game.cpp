#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
bool dp[810][810];
string s;
bool check(int l,int r){
	int n=r-l+1;
	fr(i,1,n)fr(j,1,n)dp[i][j]=0;
	fr(i,1,n-1)dp[i][i+1]=s[i+l-1]==s[i+l];
	fr(len,4,n){
		if(len&1)continue;
		fr(i,1,n){
			int j=i+len-1;
			if(j>n)break;
			dp[i][j]|=dp[i+1][j-1]&&(s[i+l-1]==s[j+l-1]);
			if(dp[i][j])continue;
			for(int k=i+1;k<j;k+=2){
				dp[i][j]|=dp[i][k]&&dp[k+1][j];
				if(dp[i][j])break;
			}
		}
	}
	return dp[1][n];
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	
	cin >> n >> s;
	s=" "+s;
	if(n<=1600){
		fr(i,1,n-1){
			dp[i][i+1]=s[i]==s[i+1];
		}
		fr(len,4,n){
			if(len&1)continue;
			fr(i,1,n){
				int j=i+len-1;
				if(j>n)break;
				dp[i][j]|=dp[i+1][j-1]&&(s[i]==s[j]);
				if(dp[i][j])continue;
				for(int k=i+1;k<j;k+=2){
					dp[i][j]|=dp[i][k]&&dp[k+1][j];
					if(dp[i][j])break;
				}
			}
		}
		int ans=0;
		fr(i,1,n)fr(j,i,n)ans+=dp[i][j];
		cout << ans;
	}
	else{
		int ans=0;
		fr(i,1,n-1){
			ans+=s[i]==s[i+1];
		}
		fr(j,2,13){
			int len=j*2;
			fr(i,1,n-1){
				int r=i+len-1;
				if(r>n)break;
				ans+=check(i,r);
			}
		}
		
		cout << ans;
	}
	return 0;
}
