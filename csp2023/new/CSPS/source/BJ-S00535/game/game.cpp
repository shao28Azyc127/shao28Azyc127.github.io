#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,now=0;
string s;
stack<char> st;
char a[200005];
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>s;
	if(n<=8000)
	{
		int l=s.length();
		for(int i=0;i<l;i++)
		{
			for(int j=i;j<l;j++)
			{
				if(!st.size()) st.push(s[j]);
				else if(st.top()==s[j]) st.pop();
				else st.push(s[j]);
				if(!st.size()) ans++;
			}
			while(st.size()) st.pop();
		}
		cout<<ans<<endl;
		return 0;
	}
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		for(int j=i;j<min(i+300,l);j++)
		{
			if(!now) a[++now]=s[j];
			else if(a[now]==s[j]) now--;
			else a[++now]=s[j];
			if(!now) ans++;
		}
		now=0;
	}
	cout<<ans<<endl;
}