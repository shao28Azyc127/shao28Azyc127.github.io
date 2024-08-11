#include <iostream>
#include <cstdio>

using namespace std;

int main ()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int i1, i2, i3, i4, i5, i6;
	int a[10][5], n, ans = 0;
	cin >> n;
	for (i1 = 0; i1 < n; i1++)
	{
		for (i2 = 0; i2 < 5; i2++)
		{
			cin >> a[i1][i2];
		}
	}
	for (i1 = 0; i1 < 10; i1++)
	{
		for (i2 = 0; i2 < 10; i2++)
		{
			for (i3 = 0; i3 < 10; i3++)
			{
				for (i4 = 0; i4 < 10; i4++)
				{
					for (i5 = 0; i5 < 10; i5++)
					{
						for (i6 = 0; i6 < n; i6++)
						{
							if (i1 == a[i6][0] && i2 == a[i6][1] && i3 == a[i6][2] && i4 == a[i6][3] && i5 != a[i6][4] || i1 == a[i6][0] && i2 == a[i6][1] && i3 == a[i6][2] && i4 != a[i6][3] && i5 == a[i6][4] || i1 == a[i6][0] && i2 == a[i6][1] && i3 != a[i6][2] && i4 == a[i6][3] && i5 == a[i6][4] || i1 == a[i6][0] && i2 != a[i6][1] && i3 == a[i6][2] && i4 == a[i6][3] && i5 == a[i6][4] ||  i1 != a[i6][0] && i2 == a[i6][1] && i3 == a[i6][2] && i4 == a[i6][3] && i5 == a[i6][4])
							{
								continue;
							}
							break;
						}
						if (i6 == n)
						{
							ans++;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}