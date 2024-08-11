#include<bits/stdc++.h>
using namespace std;
namespace SOLUTION{
	typedef long long ll;
	const int N=8010;
	int n;char s[N];
	ll ans;bool f[N][N];
	int main(){
		cin>>n>>s+1;
		for(int i=1;i<n;i++)	f[i][i+1]=(s[i]==s[i+1]),ans+=f[i][i+1];
		for(int len=4;len<=n;len+=2)
			for(int l=1,r=len;r<=n;l++,r++){
				if(s[l]==s[r]&&f[l+1][r-1]){
					f[l][r]=1,ans++;
					continue;
				}for(int k=l+1;k<=r;k+=2)
					if(f[l][k]&&f[k+1][r]){
						f[l][r]=1,ans++;
						break;					
					}
			}
		cout<<ans;
		return 0;
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return SOLUTION::main();
}