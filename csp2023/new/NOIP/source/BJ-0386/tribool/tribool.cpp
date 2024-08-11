#include <fstream>
#define N 100010

using namespace std;

ifstream cin("tribool.in");
ofstream cout("tribool.out");

char a[N];

void csh()
{
	for (int i = 1; i <= 100000; i++)
		a[i] = 'A';
}

int main()
{
	int c, t;
	int n, m;
	int x, ans;
	char v;
	cin >> c >> t;
	if (c == 3 || c == 4)
		while (t--)
		{
			csh();
			ans = 0;
			cin >> n >> m;
			for (int i = 1; i <= m; i++)
			{
				cin >> v >> x;
				a[x] = v;
			}
			for (int i = 1; i <= n; i++)
				if (a[i] == 'U')
					ans++;
			cout << ans << endl;
		}
	return 0;
}