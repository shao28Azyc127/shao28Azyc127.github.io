//ÏûÏûÀÖ
#include<bits/stdc++.h>
using namespace std;
bool dp[8005][8005];
char s[8005];
int len,cnt;
bool dfs(int x,int y){
	if(dp[x][y]==true){
		return true;
	}
	for(int i=1;i<=len;i++){
		if(dp[i][y]==true){
			if(dfs(x,i-1)==true){
				return true;
			}
		}
	}
	return false;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>len;
	for(int i=1;i<=len;i++){
		cin>>s[i];
	}
	for(int i=1;i<=len-1;i++){
		for(int j=0;j<=len-2 && i+1+j<=len;j++){
			if(j==0 && s[i]==s[i+1]){
				dp[i][i+1]=true;
				cnt++;
			}else if(dp[i+1][i+j]==true && s[i]==s[i+1+j]){
				dp[i][i+1+j]=true;
				cnt++;
			}else{
				if(dfs(i,i+1+j)==true){
					dp[i][i+1+j]=true;
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}


/*#include<bits/stdc++.h>
using namespace std;
bool bor[8005][8005];
int vis[2000005];
int n,cnt;
char s[2000005];
void dfs(int l,int r){
	if(r==l+1){
		if(s[l]==s[r]){
			cnt++;
			bor[l][r]=true;
		}
		return;
	}
	if(r==l){
		return;
	}
	int mid=(l+r)/2;
	dfs(l,mid);
	dfs(mid+1,r);
	int ll=mid;
	int rr=mid+1;
	while(1){
		if(
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	dfs(1,n);
	return 0;
}*/