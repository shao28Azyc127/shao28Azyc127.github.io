#include <bits/stdc++.h>

using namespace std;

string s, tmp;
int n, rp, top = -1;
vector<string> v;
vector<char> t;

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> s;
	
	for(int i = 0; i < s.size() - 1; i++)
	{
		tmp = s[i];
		v.push_back(tmp);
		for(int j = i + 1; j < s.size(); j++)
		{
			tmp += s[j];
			v.push_back(tmp);
		}
	}
	
	for(auto q : v)
	{
		while(!t.empty())t.pop_back();
		if(q.size() == 0 or q.size() == 1)
		{
			continue;
		}
		
		t.push_back(q[0]);
		top = 0;
		for(int i = 1; i < q.size(); i++)
		{
			if(t[top] != q[i])
			{
				t.push_back(q[i]);
				top++;
			}
			else
			{
				t.pop_back();
				top--;
			}
		}
		if(t.empty())
		{
			rp++;
		}
	}
	cout << rp;
	
	return 0;
}