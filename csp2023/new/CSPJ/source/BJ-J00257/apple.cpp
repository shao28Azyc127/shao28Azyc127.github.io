//lxy qwq
//Csp-s Rp++
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define WA cerr<<"QWQ\n"
#define INF 0x3f3f3f3f
#define H cout<<"\n"
#define C continue
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(b);i>=(a);i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(b);i>(a);i--)
#define MAXN
#define ull unsigned long long
int n;
 main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	int cnt=0;
	int nq=n,pos=INF;
	while(n>1)
	{
		if(n%3==1) { pos=min(pos,cnt); }
		n=n-ceil(n/3.0);
		cnt++;
	}
	if(pos==INF) pos=cnt;
	cout<<cnt+1<<" "<<pos+1<<"\n";
	return 0;
}