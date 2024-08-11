#include <bits/stdc++.h>
using namespace std;

int n, r;
string s;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
		for(int j = 0; j <= n - i; j++)
		{
			string d = "";
			for(int k = j; k < j + i; k++)
			{
				bool f = true;
				if(d.empty() == false)
					if(d.front() == s[k]) d.pop_back(), f = false;
				if(f) d.push_back(s[k]);
				
			}
			if(d.size() == 0) r++;
			cout << d << endl;
		}
	}
	cout << r << endl;

    return 0;
}
