#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c, n, m, q;
int x[N], y[N];
bool ch()
{
	int rig = 1;
	for(int i = 1; i <= n; i ++)
	{
		int nrg;
		for(int j = rig; j <= m; j ++)
		{
			if(x[i] <= y[j]) break;
			nrg = j;
		}
		rig = nrg;
	}
	if(rig == m) return 1;
	return 0;
}
bool ch2()
{
	int rig = 1;
        for(int i = 1; i <= m; i ++)
        {
                int nrg;
                for(int j = rig; j <= n; j ++)
                {
                        if(y[i] <= x[j]) break;
                        nrg = j;
                }
                rig = nrg;
        }
        if(rig == n) return 1;
        return 0;

}
int ans[N];
int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> c >> n >> m >> q;
	for(int i = 1; i <= n; i ++) cin >> x[i];
	for(int i = 1; i <= m; i ++) cin >> y[i];
	if(ch() || ch2()) cout << '1';
	else cout << '0';
	for(int i = 1; i <= q; i ++)
	{
		int nx, ny;
		cin >> nx >> ny;
		for(int j = 1; j <= nx; j ++)
		{
			int xp, v;
			cin >> xp >> v;
			x[xp] = v;
		}
		for(int j = 1; j <= ny; j ++)
		{
			int yp, v;
			cin >> yp >> v;
			y[yp] = v;
		}
		if(ch() || ch2()) cout << '1';
		else cout << '0';
	}
	cout << endl;
	return 0;
}