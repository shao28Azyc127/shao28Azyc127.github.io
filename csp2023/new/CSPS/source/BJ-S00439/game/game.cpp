#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;

int n;
string s;
ll ans;

stack<char> st;

bool check(int l)
{
	for (int i=l;i<=n;i++)
	{
		if (st.empty())
		{
			st.push(s[i]);
			continue;
		}
		if (st.top()==s[i])
		{
			st.pop();
			if (st.empty())
				ans++;
		}
		else st.push(s[i]);
	}
	while (!st.empty())
		st.pop();
	return 0;
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s;
	for (int i=0;i<n;i++)
	{
		check(i);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}