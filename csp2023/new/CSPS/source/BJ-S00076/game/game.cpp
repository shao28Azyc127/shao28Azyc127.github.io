#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
int n;string s=" ";
bool dp[N][N];
//ll dp[N][log2(N)];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;char l;ll ans=0;
	for(register int i=1;i<=n;i++){
		char c;scanf(" %c",&c);s+=c;
		if(i>1&&l==c){
			dp[i-1][i]=1;ans++;
		}
		l=c;
	}
	//~ for(int i=1;i<n;i++){
		//~ if(s[i]==s[i+1])dp[i][i+1]=1;
	//~ }
	for(register int len=2;len<=n;len++){
		for(register int l=1,r=len+l;r<=n;l++,r++){
			if(s[l]==s[r]){
				if(dp[l][r]==0&&dp[l+1][r-1]==1)ans++;
				dp[l][r]|=dp[l+1][r-1];
			}
			if(dp[l][r])continue;
			for(register int k=l;k<r;k++){
				if(dp[l][r]==0&&(dp[l][k]&dp[k+1][r])){
					ans++;
				}
				dp[l][r]|=dp[l][k]&dp[k+1][r];
				if(dp[l][r])break;
			}
		}
	}
	//~ ll cnt=0;
	//~ for(register int len=1;len<=n;len++){
		//~ for(register int l=1,r=len+l;r<=n;l++,r++){
			//~ if(dp[l][r])cnt++;
		//~ }
		
	//~ }
	cout<<ans;
	return 0;
}
