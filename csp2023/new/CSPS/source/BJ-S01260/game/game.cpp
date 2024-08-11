#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#define LL long long
using namespace std;

const int NR=1080;
const int MR=0;
const int MOD=0;

bool dp[NR][NR];

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	s=" "+s;
	int ans=0;
	for(int i=2;i<=n;i++){
		if(s[i]==s[i-1])dp[i-1][i]=true,ans++;
	}
	for(int len=4;len<=n;len+=2){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			if(s[l]==s[r]&&dp[l+1][r-1])ans++,dp[l][r]=true;
			else{
				for(int k=l+1;k<=r-2;k++){
					if(dp[l][k]&&dp[k+1][r]){
						ans++,dp[l][r]=true;
						break;
					}
				}
			}
			
			
			
		}
	}
	cout << ans << endl;
}