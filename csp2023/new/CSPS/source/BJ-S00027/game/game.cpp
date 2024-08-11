#include<bits/stdc++.h>
using namespace std;
long long n,ans;//,dp[10005][10005];
bool check[30005][30005];
string s;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>s;
	s='.'+s;
	for(int i=1;i<n;i++)
		if(s[i]==s[i+1]) check[i][i+1]=true,ans++;//dp[i][i+1]=1,
	for(int len=4;len<=n;len+=2){
		for(int head=1;head+len-1<=n;head++){
			int tail=head+len-1;
			if(s[tail]==s[head]&&check[head+1][tail-1]==true){
				check[head][tail]=true;
				ans++;
				continue;
			}
			for(int k=head+1;k<tail;k+=2){
				if(check[head][k]==true&&check[k+1][tail]==true){
					ans++;
					check[head][tail]=true;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
