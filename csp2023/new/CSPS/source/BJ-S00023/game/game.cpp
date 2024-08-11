#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1000000007;
int n;
char c[2000005];
bool dp[2005][2005];
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(i!=1&&c[i]==c[i-1]){
			dp[i-1][i]=true;
			//cout<<i-1<<' '<<i<<endl;
		}
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if(len!=2&&c[i]==c[j]&&dp[i+1][j-1]){
				dp[i][j]=true;
			}
			for(int k=i;k<j;k++){
				if(dp[i][k]&&dp[k+1][j]){
					dp[i][j]=true;
				}
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(dp[i][j]){
				//cout<<i<<' '<<j<<endl;
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}