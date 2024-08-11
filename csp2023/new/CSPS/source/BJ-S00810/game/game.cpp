#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,sum[N][30],ans;
string s;
bool check(int l,int r){
	if((r-l+1)%2){
		return 0;
	}
	for(int i=l;i<=r;i++){
		if((sum[r][s[i]-'a']-sum[l-1][s[i]-'a'])%2){
			return 0;
		}
	}
	return 1;
}
void text(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		for(int j=0;j<26;j++){
			sum[i][j]=sum[i-1][j];
			if(s[i]-'a'==j){
				sum[i][j]++;
			}
		}
	}
	for(int l=0;l<n-1;l++){
		for(int r=l+1;r<n;r++){
			if(check(l,r)){
				ans++;
			}
		}
	}
	cout<<ans;
	return;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	text();
	return 0;
}