#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
typedef long long ULL;
const int B=37;
ULL n,ans;
map<ULL,int> m;
int a[2000010];
int s[2000010],t;
ULL f[2000010];
ULL dp[2000010];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char cc;cin>>cc;a[i]=cc-'a'+1;
	}
	if(n<=8000){
		for(int i=1;i<n;i++){
			t=0;
			for(int j=i;j<=n;j++){
				if(t&&s[t]==a[j]) t--;
				else s[++t]=a[j];
				if(!t) ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	m[0]++;f[0]=0;
	for(int i=1;i<=n;i++){
		if(t&&s[t]==a[i]) t--,f[i]=dp[t];
		else s[++t]=a[i],f[i]=f[i-1]*B+a[i],dp[t]=f[i];
		ans+=m[f[i]];m[f[i]]++;//cout<<f[i]<<" ";
	}
	cout<<ans;
	return 0;
}
