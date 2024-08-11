#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
stack<char> s;
ll n;
stack<int> pt;
ll endn[N], ans, t;
char c, cs[N];
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n;
	//pt.push(1);
	//cin >> c;
	//s.push(c);
	int m=1, t=1;
	for(int i=1; i<=n; ++i)
		cin >> cs[i];
	while(cs[m] == cs[m+1])
	{
		m++;
	}
	if(m%2==1) t=2;
	for(int i=t; i<=n; ++i)
	{
		c=cs[i];
		if(s.size() && s.top()==c)
		{
			s.pop();
			endn[i]++;
			ans++;
			endn[i] += endn[pt.top()-1];
			ans += endn[pt.top()-1];
			pt.pop();
		}
		else
		{
			pt.push(i);
			s.push(c);
		}
		//cout << i << " pt: " << (pt.size()>0 ? pt.top() : 0) << " s: " << (s.size()>0 ? char(s.top()): 0) << " endn: " << endn[i] << endl;
	}
	cout << ans;
	return 0;
}