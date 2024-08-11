//Genshin Impact (wrong) Zhenshen Impart (true)
//I love Kamisato Ayaka
#include <bits/stdc++.h>

#define rep(i,a,b,c) for(int (i)=a;i<=(b);i+=(c))
#define per(i,a,b,c) for(int (i)=a;i>=(b);i-=(c))
#define pb push_back
using namespace std;

const int MAXN=2000200;
int f[MAXN];
long long cnt[MAXN];
int jmp[MAXN][23];
int okk[MAXN][23];

signed main(){
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n;string s;
	cin>>n>>s;s=" "+s;
	long long ans=0;
	rep(i,0,22,1)	okk[0][i]=(1<<28)-1;
	rep(i,1,n,1){
		int t=i-1;
		int ss=s[i]-'a';

		per(j,22,0,1){
			if(!(okk[t][j]&(1<<ss)) && jmp[t][j]>=1){	t=jmp[t][j];}
		}
		if(s[t]==s[i])	t=t;
		else if(s[f[t]]==s[i])	t=f[t];
		else {f[i]=jmp[i][0]=i;okk[i][0]=(1<<s[i]-'a');
		rep(j,1,22,1)	jmp[i][j]=jmp[jmp[i][j-1]][j-1],okk[i][j]=okk[i][j-1]|okk[jmp[i][j-1]][j-1];
		continue ;}
		f[i]=t-1;
		jmp[i][0]=t-1;okk[i][0]=(1<<(s[t-1]-'a'))|(1<<(s[i]-'a'));
		rep(j,1,22,1)	jmp[i][j]=jmp[jmp[i][j-1]][j-1],okk[i][j]=okk[i][j-1]|okk[jmp[i][j-1]][j-1];
		cnt[i]=cnt[t-1]+1;
		ans+=cnt[i];
	}
	//rep(i,1,n,1)	cout<<f[i]<<" ";
	cout<<ans<<endl;
	
	return 0;
}