//lxy qwq
//Csp-s Rp++
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
//define int long long
#define ull unsigned long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i++)
#define C continue
#define WA cerr<<"QWQ\n"
#define MAXN 100019
#define H cout<<"\n"
#define pb push_back()
#define pk pop_back()
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
struct lxy{ string na; int ed; };
int tot;
map<string,int> st;//jiehouti
int mx;
lxy q[MAXN];

map<string,int> z;
int main()
{
        freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	int _; cin>>_;
	z["int"]=4; z["long"]=8; z["short"]=2; z["byte"]=1;
	while(_--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			string s; int k; cin>>s>>k;
			
		}
		if(op==2)
		{
			string t,o;
			cin>>t>>o;
			int ji=z[t];
			int nxt=(ceil(mx/(ji+0.0))*ji);
			For(i,nxt,nxt+ji) q[i].na=o,q[i].ed=nxt+ji;
			st[o]=mx;
			mx=nxt+ji;
		}
		if(op==3)
		{
			string Qo; cin>>Qo;
			cout<<st[Qo]<<"\n";
		}
		if(op==4)
		{
			int ps; cin>>ps; if(ps>mx) { cout<<"ERR\n"; C; }
			if(q[ps].na.empty()) { cout<<"ERR\n"; }
			else cout<<q[ps].na<<"\n";
		}
	}
	//fclose(stdin);
	//freopen("struct.in","r",stdin);
	return 0;
}