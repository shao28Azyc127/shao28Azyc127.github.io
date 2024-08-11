#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
bool dp[10000][10000];
string s;
bool check(int a,int b){
	int len=b-a+1;
	for(int i=1;i<=len/2;i++){
		if(s[a+i-1]!=s[b-i+1]){
			return 0;
		}
	}
	return 1;
}
int main(){
	//前三道题都会？？？？？？要是1=我表演倒立
	//byd qu jian dp 50pts??????
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    s='0'+s;
    for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(i,j)){
				dp[i][j]=1;
				//cout<<i<<' '<<j<<endl;
				ans++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<=j;k++){
				if(dp[i][k]==1 && dp[k+1][j]==1 && dp[i][j]==0){
					dp[i][j]=1;
					ans++;
					break;
				}
			}
		}
	}
	cout<<ans;
    return 0;
}
