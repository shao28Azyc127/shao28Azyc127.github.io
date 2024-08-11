#include<bits/stdc++.h>
using namespace std;
const int NR=8005;
int n;
char s[NR];
// int f[NR][NR];//i~j
bool g[NR][NR];
int lt[NR],rt[NR];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>s[i];
	for(int i=1;i<n;++i)
		if(s[i]==s[i+1])g[i][i+1]=true;
	memset(rt,0x3f3f3f3f,sizeof(rt));
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j)
			if(s[i]==s[j]){rt[i]=j;break;}
		for(int j=i-1;j>=1;--j)
			if(s[i]==s[j]){lt[i]=j;break;}
	}
	for(int len=1;len<=n;++len){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if(len%2)continue;
			if(len>2&&s[i]==s[j])
				if(g[i+1][j-1])
					g[i][j]=true;
			if(rt[i]<lt[j]&&rt[i]<j&&lt[j]>i){
				if(g[i][rt[i]]&&g[lt[j]][j]&&(rt[i]+1==lt[j]||g[rt[i]+1][lt[j]-1]))
					g[i][j]=true;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			if(g[i][j])ans++;
	cout<<ans<<endl;
	// cout<<g[1][n]<<endl;
	return 0;
}