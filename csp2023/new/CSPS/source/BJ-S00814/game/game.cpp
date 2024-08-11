#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
mt19937_64 rnd(22625025);
unsigned int A[5000005],X[3000005],Y[3000005];
signed main()
{
	for(int i=0;i<=2500005;i++) A[i]=rnd();
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t=s;
	reverse(t.begin(),t.end());
	s=" "+t+s;
	t="";
	//cout << s << "\n";
	int ans=0;
	unsigned int hsh=0;
	X[0]=hsh;
	map<unsigned int,int> mp;
	for(int i=n+1;i<=n+n;i++)
	{
		if(!t.size()||t.back()!=s[i])
		{
			hsh+=A[t.size()]*s[i];
			t+=s[i];
		}
		else
		{
			hsh-=A[t.size()-1]*t.back();
			t.pop_back();
		}
		X[i-n]=hsh;
	}
	t="",hsh=0;
	Y[0]=hsh;
	for(int i=n;i>=1;i--)
	{
		if(!t.size()||t.back()!=s[i])
		{
			hsh+=A[t.size()]*s[i];
			t+=s[i];
		}
		else
		{
			hsh-=A[t.size()-1]*t.back();
			t.pop_back();
		}
		Y[n-i+1]=hsh;
	}
	sort(X,X+n+1);
	sort(Y,Y+n+1);
	int nw=0;
	for(int i=0;i<=n;i++)
	{
		if(i&&X[i]==X[i-1]) continue;
		int c1=0,c2=0;
		while(nw<=n&&Y[nw]<X[i]) ++nw;
		while(nw<=n&&Y[nw]==X[i]) ++nw,++c2;
		for(int j=i;j<=n;j++)
		{
			if(X[j]==X[i]) ++c1;
			else break;
		}
		ans+=c1*c2;
	}
	cout << (ans-n-1)/2 << "\n";
	return 0;
}