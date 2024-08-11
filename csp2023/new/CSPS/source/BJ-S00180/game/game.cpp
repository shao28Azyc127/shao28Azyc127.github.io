//lxy qwq
//Csp-s Rp++
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define int long long
#define ull unsigned long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i++)
#define C continue
#define WA cerr<<"QWQ\n"
#define MAXN 2000019
#define H cout<<"\n"
#define pb push_back
#define pk pop_back
const int MOD=998244353;
int ksm(int x,int y) 
{
	int ba=x,ans=1;
	while(y) 
	{ 
		if(y&1) { ans*=ba; ans%=MOD; } 
		ba*=ba; ba%=MOD;
	}
	return ans%MOD;
}
int n; string s;
#define MAXS 1019
void sub_35()
{
	bool ok_[MAXS][MAXS];
	memset(ok_,0,sizeof(ok_));
	int cnt_=0;
	For(i,2,n) if(s[i-1]==s[i]) ok_[i][i-1]=ok_[i-1][i]=1,cnt_++;
	for(int len=4;len<=n;len+=2) For(i,1,n-len+1)
	{
		int j=i+len-1;
		int gs=0;
		if(s[i]==s[j]) { ok_[i][j]=ok_[i+1][j-1]; if(ok_[i][j]) cnt_++;  C; }
		For(k,i,j-1)
		{
			if(ok_[i][k]&&ok_[k+1][j]) { ok_[i][j]=1; break; }
		}
		if(ok_[i][j]) cnt_++;
		if(gs) ok_[i-1][j+1]=ok_[i][j];
	}
	cout<<cnt_<<"\n";
	return ;
}
int bas[MAXN];
int qz[MAXN];
void sub_50()
{
	For(i,2,n)
	{
		if(s[i]==s[i-1]) { bas[i]=i-1; C; }
		if(bas[i-1]!=0&&s[bas[i-1]-1]==s[i]) 
		{
			bas[i]=max(bas[i-1]-1,bas[i]); C;
		}
		int fi=i-1;
		while(bas[fi]!=0)
		{
			fi=bas[fi]-1;
			if(s[fi]==s[i]) { bas[i]=fi; break; }
		}
	}
	//For(i,1,n) cerr<<bas[i]<<" ";	
	int qwq=0;
	For(i,1,n) { if(bas[i]!=0) { qz[i]=qz[bas[i]-1]+1; } qwq+=qz[i]; } 
	//For(i,1,n) cerr<<qz[i]<<" ";
	cout<<qwq<<"\n";
	return ;
}
 main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cin>>n>>s;
	s.insert(0," ");
	int cnt=0,k=0;
	int cs=0;                          
	if(n<=1000) { sub_35(); return 0; }
	sub_50(); 
	/*For(i,1,n)
	{
		if(!q.empty()&&s[q.back()]==s[i]) { v[i]=v[q.back()]=1; q.pk(); }
		else q.pb(i);
	}
	int nc=0; q.clear();
	For(i,1,n) 
	{
		if(!q.empty()&&s[q.back()]==s[i]) { fl[i]=fl[q.back()]=nc; nc--; q.pk(); }
		else if(v[i]) { q.pb(i); nc++; }
		if(nc==1) nc=i;
	}
	For(i,1,n) cerr<<fl[i]<<" "; H;
	For(i,1,n) FOR(j,1,i) cnt+=(fl[j]==fl[i]);
	cout<<cnt<<"\n";*/
	return 0;
}