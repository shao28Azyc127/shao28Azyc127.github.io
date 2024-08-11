#include <fstream>
#define N 100010

using namespace std;

ifstream cin("road.in");
ofstream cout("road.out");

int v[N], a[N];
int qzh[N];

int main()
{
	int i, j;
	int n, d;
	int dis;
	int s = 0, ans = 0;
	cin >> n >> d;
	for (i = 2; i <= n; i++)
	{
		cin >> v[i];
		qzh[i] = qzh[i - 1] + v[i];
	}
	for (i = 1; i <= n; i++)
		cin >> a[i];
	i = 1;
	while (i < n)
	{
		for (j = i + 1; j < n; j++)
			if (a[j] < a[i])
				break;
		dis = qzh[j] - qzh[i] - s;
		s = dis / d * d - dis;
		ans += dis / d * a[i];
		if (dis % d != 0)
		{
			s += d;
			ans += a[i];
		}
		i = j;
	}
	cout << ans;
	return 0;
}