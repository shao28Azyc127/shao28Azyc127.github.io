//Lxy qwq
//Noip Rp++
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define C continue
#define WA cerr<<"LXY\n";
#define WR(x) cerr<<x<<"\n";
#define G(i,p) for(auto i:pq[p])
#define VG(i,p) for(int i=0;i<pq[p].size();i++)
#define LG(i,p) for(int i=hd[p];i;i=nxt[i])
#define fi first
#define se second
#define pb push_back
#define pk pop_back
#define MAXN 3019
#define H cout<<"\n"
#define WH cerr<<"\n";
#define INF 0x3f3f3f3f
int bx1[MAXN][36];
string s[MAXN];
int mx[MAXN],mn[MAXN];
int n; int len;
bool cmp1(char x,char y) { return x<y; }
bool cmp2(char x,char y) { return x>y; }
int MOD1=2008120319,ba1=19;
int MOD2=20081203,ba2=37;
bool cmp(int i,int j)//min{i}>=max{j}
{
	if(mn[i]>=mx[j]) return 1;
	else return 0;
	Rof(k,25,0) 
	{
		if(bx1[i][k]&&!bx1[j][k]) return 1;
		
	}
	return 0;
}
 main()
{
	//freopen("dict.in","r",stdin);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>len; 
	For(i,1,n) { cin>>s[i]; s[i].insert(0," "); }
	For(i,1,n)
	{//cerr<<s[i]<<"\n";
		sort(s[i].begin(),s[i].end());
		mn[i]=INF; mx[i]=-INF;
		For(j,1,len) { mx[i]=max(mx[i],(int)(s[i][j]-'a')+1); mn[i]=min(mn[i],(int)(s[i][j]-'a')+1);
		bx1[i][s[i][j]-'a'+1]++; }
		
	}
	For(i,1,n)
	{	
		bool fl=0;
		For(j,1,n)
		{
			if(j==i) C;
			if(cmp(i,j)) { fl=1; break; } 
		}
		cout<<(!fl);
	} H;
	return 0;
}