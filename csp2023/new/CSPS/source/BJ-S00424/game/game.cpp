#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int co[N]={0},ans=0;
bool b(string s)
{
	stack<char> st;
	for(int i=0;i<s.length();i++)
	{
		if(st.size()==0||st.top()!=s[i])
			st.push(s[i]);
		else
			st.pop();
	}
	return !st.size();
}
void mkco(string s)
{
	for(int j=2;j<=s.length();j+=2)
		for(int i=0;i+j<=s.length();i++)
			if(b(s.substr(i,j)))
				ans++;
	return;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	cin>>n;
	string s;
	cin>>s;
	mkco(s);
	cout<<ans;	
	return 0;
}