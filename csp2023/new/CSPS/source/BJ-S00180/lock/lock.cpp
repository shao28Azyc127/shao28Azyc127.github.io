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
#define MAXN 1000019
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
int n;
int np;
int a[10][10];
int mapp[MAXN];
int has(int a1=a[np][1],int a2=a[np][2],int a3=a[np][3],int a4=a[np][4],int a5=a[np][5])
{
	a1%=10; a2%=10; a3%=10; a4%=10; a5%=10;
	return a1*10000+a2*1000+a3*100+a4*10+a5;	
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cin>>n;
	For(i,1,n) For(j,1,5) cin>>a[i][j];
	//if(n==1) { cout<<"81\n"; return 0; }
	For(i,1,n)
	{
		For(j,1,5)
		{
			For(o,0,9)
			{
				a[i][j]+=o;
				np=i;
				mapp[has()]++;
				a[i][j]-=o;
			}
		}
		For(j,1,4)
		{
			For(o,0,9)
			{
				a[i][j]+=o; a[i][j+1]+=o;
				np=i;
				mapp[has()]++;
				a[i][j]-=o; a[i][j+1]-=o;
			}
		}
	}
	int ans=0;
	For(i,0,99999)
	{
		if(mapp[i]==n) ans++;
	} 
	cout<<ans<<"\n";
	return 0;
}