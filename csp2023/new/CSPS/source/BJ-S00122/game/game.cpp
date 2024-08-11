#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int n , cnt;
string s;
bool is(int l , int r)
{
	stack<char>st;
	for (int i = l; i <= r; i++)
	{
		if (!st.empty() && s[i] == st.top())st.pop();
		else st.push(s[i]);
	}
	if (st.empty())return true;
	return false;;
}
int main()
{
	freopen("game.in" , "r" , stdin);
	freopen("game.out" , "w" , stdout);
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (is(i - 1 , j - 1))
				cnt++;
	cout << cnt;
	return 0;
}
