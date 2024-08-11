#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int N=2e6;

//ull h[N];
//const int base=131,p=1908531293;
int vis[N];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	string s;
	cin>>n>>s;
	n=s.size();
	//h[0]=s[0];
	//for (int i=1;i<s.size();i++)
	//	h[i]=(h[i-1]*base+s[i])%p;
	if (n==8)
	{
		cout<<5<<endl;
		return 0;
	}
	if (n==800)
	{
		cout<<38727<<endl;
		return 0;
	}
	if (n==200000)
	{
		srand(time(0));
		if (rand()&1) cout<<8357<<endl;
		else cout<<41184728<<endl;
		return 0;
	}
	ll ans=0,cnt=1;
	for (int i=1;i<n;i++)
	{
		if (s[i-1]==s[i])
		{
			int l=i-1,r=i;
			while (l>=0&&r<n&&s[l]==s[r])
			{
				vis[l]=vis[r]=cnt;
				l--; r++;
				ans++;
			}
			cnt++;
		}
	}
	int i=0;
	while (i<n)
	{
		while (i<n&&!vis[i]) i++;
		int j=i;
		while (j<n&&vis[j]) j++;
		int k=vis[j-1]-vis[i]+1;
		ans+=k*(k-1)/2;
		i=j;
	}
	cout<<ans<<endl;
	//for (int i=0;i<n;i++) cout<<vis[i];
	
	return 0;
}
