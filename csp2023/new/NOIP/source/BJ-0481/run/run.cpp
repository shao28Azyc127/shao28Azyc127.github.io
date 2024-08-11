#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

struct chalenge
{
	int xi, yi, vi, value;
};

long long c, q, n, m, k, d;
long long ans;

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> c >> q;
	while(q > 0)
	{
		q--;
		ans = 0;
		vector<chalenge> chals;
		queue<chalenge> chalsq;
		cin >> n >> m >> k >> d;
		chalenge chals0;
		cin >> chals0.xi >> chals0.yi >> chals0.vi;
		chals0.value = chals0.vi - (chals0.yi * d);
		// chals.emplace_back(chals0);
		chalsq.emplace(chals0);
		for(int i = 1 ; i < m ; i++)
		{
			chalenge tmp;
			cin >> tmp.xi >> tmp.yi >> tmp.vi;
			tmp.value = tmp.vi - (tmp.yi * d);
			// cout << tmp.value << endl;
			int nn = chalsq.size();
			bool flag = false;
			for(int j = 0 ; j < nn-1 ; j++)
			{
				if(tmp.xi <= chalsq.front().xi)
				{
					flag = true;
					chalsq.emplace(tmp);
				}
				chalenge front = chalsq.front();
				chalsq.pop();
				chalsq.emplace(front);
			}
			if(!flag)
			{
				chalsq.emplace(tmp);
			}
		}
		int nnnn = chalsq.size();
		for(int i = 0 ; i < nnnn ; i++)
		{
			chals.emplace_back(chalsq.front());
			chalsq.pop();
		}
		// for(int i = 0 ; i < chals.size() ; i++)
		// {
		// 	// cout << chals[i].xi << " " << chals[i].yi << " " << chals[i].vi << " " << chals[i].value << endl;
		// }
		int nnn = chals.size();
		for(int i = 1 ; i < nnn ; i++)
		{
			for(int j = i-1 ; j >= 0 ; j--)
			{
				if(chals[j].xi != -1 && chals[i].xi-chals[i].yi+1 < chals[j].xi && chals[i].xi - chals[j].xi + chals[j].yi + 1 <= k)
				{
					int heq = chals[i].value+chals[j].value+(chals[j].xi-chals[i].xi+chals[i].yi)*d;
					if(heq > chals[i].value)
					{
						chals[i].yi = chals[i].yi+chals[j].yi-(chals[j].xi-chals[i].xi+chals[i].yi);
						chals[i].value = heq;
						chals[j].xi = -1;
						chals[j].yi = -1;
						chals[j].value = 0;
					}
				}
			}
		}
		for(int i = 0 ; i < nnn ; i++)
		{
			for(int j = i-1 ; j >= 0 ; j--)
			{
				if(!chals[i].xi - chals[j].xi + chals[j].yi + 1 <= k)
				{
					if(chals[i].value < chals[j].value)
					{
						chals[i].xi = -1;
						chals[i].yi = -1;
						chals[i].value = 0;
					}
					else
					{
						chals[j].xi = -1;
						chals[j].yi = -1;
						chals[j].value = 0;
					}
				}
			}
		}
		for(int i = 0 ; i < chals.size() ; i++)
		{
			if(chals[i].value > 0)
			{
				// cout << chals[i].xi << " " << chals[i].yi << " " << chals[i].vi << endl;
				ans += chals[i].value;
			}
		}
		cout << ans << endl;
	}
	return 0;
}