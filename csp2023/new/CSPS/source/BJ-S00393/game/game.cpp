#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 6;
int n;
string s;
int ans, mat[N];
int mk[N];
bool ch(int l, int r)
{
	l --; r --;
	if((r - l + 1) & 1) return 0;
	string c = s.substr(l, r - l + 1);
//	cout << c << endl;
	for(int i = (c.size() >> 1); i> 0; i --)
	{
//		cout << c << endl;
		for(int j = 0; j < c.size() - 1; j ++)
			if(c[j] == c[j + 1]) {c.erase(j, 2); break;}
	}
//	cout << endl;
	return (c.empty()? 1 : 0);
}
int cp[33];
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> s;
/*	for(int i = 0; i < n; i ++)
	{
		if(cp[s[i] - 'a'] == 0) cp[s[i] - 'a'] = i;
	       	else
		{
			mat[i] = cp[s[i] - 'a'];
			mat[cp[s[i] - 'a']] = i;
			cp[s[i] - 'a'] = 0;
		}
	}
//	for(int i = 1; i <= n; i ++) cout << mat[i] << " ";
//	cout << endl;
*/		
	for(int i = 1; i <= n; i ++)
	{
		for(int j = i + 1; j <= n; j += 2)
		{	
			if(ch(i, j)) ans ++;
		}
	}
	cout << ans << endl;
	return 0;
}