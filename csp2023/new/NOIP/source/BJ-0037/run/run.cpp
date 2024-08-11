/*
So long as men can breathe or eyes can see,
So long lives this, and this gives life to thee.
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1e5, M = 4e5;
const long long Inf = 1e16;

int TestId, TestCnt;

int n, m, k;
long long d;

struct Task
{
	int l, r;
	long long v;
} task[N + 5];

int b[M + 5], _cnt;

vector<int> vec[M + 5];
bool cmp(int x, int y)
{
	return task[x].l > task[y].l;
}

namespace BF
{
	const int NN = 5000;

	long long dp[2][NN + 5];

	void solve()
	{
		for (int i = 0; i <= 1; i++)
			for (int j = 0; j <= _cnt; j++)
				dp[i][j] = -Inf;
		
		dp[0][0] = 0;
		int ty = 0;

		for (int i = 0; i < _cnt; i++)
		{
			for (int j = 0; j <= _cnt; j++)
				dp[ty ^ 1][j] = -Inf;

			int p = 1;
			long long sum = 0;
			for (auto id : vec[i])
			{
				int l = task[id].l;
				long long v = task[id].v;
				while (i - p + 1 > l && b[i] - b[i - p + 1] + 1 <= k)
				{
					dp[ty][p] += sum;
					p++;
				}
				sum += v;
			}
			while (p <= i && b[i] - b[i - p + 1] + 1 <= k)
			{
				dp[ty][p] += sum;
				p++;
			}

			for (int j = 0; j <= i; j++)
			{
				if (j != 0 && b[i] - b[i - j + 1] + 1 > k)
					break;
				if (b[i + 1] - b[i - j + 1] + 1 <= k)
				{
					dp[ty ^ 1][j + 1] = max(dp[ty ^ 1][j + 1], dp[ty][j] - d);
				}
				dp[ty ^ 1][0] = max(dp[ty ^ 1][0], dp[ty][j]);
			}

			ty ^= 1;
		}

		long long ans = 0;
		for (int i = 0; i <= _cnt; i++)
			ans = max(ans, dp[ty][i]);
		printf("%lld\n", ans);
		return ;
	}
}
namespace A
{
	const int NN = 5000;

	long long dp[2][NN + 5];

	void solve()
	{
		for (int i = 1; i <= k + 1; i++)
			dp[0][i] = -Inf;

		dp[0][0] = 0;
		int ty = 0;
		for (int i = 0; i < _cnt; i++)
		{
			for (int j = 0; j <= k + 1; j++)
				dp[ty ^ 1][j] = -Inf;

			int p = 1;
			long long sum = 0;
			for (auto id : vec[i])
			{
				int l = task[id].l;
				long long v = task[id].v;
				while (i - p + 1 > l && b[i] - b[i - p + 1] + 1 <= k && p <= i)
				{

					dp[ty][p] += sum;
					p++;
				}
				sum += v;
			}
			while (p <= i && b[i] - b[i - p + 1] + 1 <= k)
			{
				dp[ty][p] += sum;
				p++;
			}

			for (int j = 0; j <= i; j++)
			{
				if (j != 0 && b[i] - b[i - j + 1] + 1 > k)
					break;
				if (b[i + 1] - b[i - j + 1] + 1 <= k)
				{
					dp[ty ^ 1][j + 1] = max(dp[ty ^ 1][j + 1], dp[ty][j] - d);
				}
				dp[ty ^ 1][0] = max(dp[ty ^ 1][0], dp[ty][j]);
			}

			ty ^= 1;
		}

		long long ans = dp[ty][0];
		for (int i = 1; i <= _cnt && b[_cnt] - b[_cnt - i + 1] + 1 <= k; i++)
			ans = max(ans, dp[ty][i]);
		printf("%lld\n", ans);
		return ;
	}
}
namespace B
{
	void solve()
	{
		long long ans = 0;
		for (int i = 1; i <= m; i++)
		{
			long long len = b[task[i].r] - b[task[i].l] + 1;
			ans += max(0ll, task[i].v - len * d);
		}
		printf("%lld\n", ans);
	}
}

void solve()
{
	scanf("%d%d%d%lld", &n, &m, &k, &d);
	_cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%lld", &task[i].r, &task[i].l, &task[i].v);
		if (task[i].l > k)
			continue;
		task[i].l = task[i].r - task[i].l + 1;
		b[++_cnt] = task[i].r;
		b[++_cnt] = task[i].l;
		b[++_cnt] = max(task[i].r - k + 1, 0);
	}

	sort(b + 1, b + _cnt + 1);
	_cnt = unique(b + 1, b + _cnt + 1) - b - 1;
	for (int i = 1; i <= m; i++)
	{
		task[i].l = lower_bound(b + 1, b + _cnt + 1, task[i].l) - b;
		task[i].r = lower_bound(b + 1, b + _cnt + 1, task[i].r) - b;
		vec[task[i].r].push_back(i);
	}
	for (int i = 1; i <= _cnt; i++)
	{
		sort(vec[i].begin(), vec[i].end(), cmp);
	}

	if (TestId <= 11)
		BF :: solve();
	else if (TestId == 15 || TestId == 16)
		A :: solve();
	else if (TestId == 17 || TestId == 18)
		B :: solve();
	else
		;

	for (int i = 0; i <= _cnt; i++)
		vec[i].clear();
	return ;
}

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);

	scanf("%d%d", &TestId, &TestCnt);
	while (TestCnt--)
		solve();
	return 0;
}
