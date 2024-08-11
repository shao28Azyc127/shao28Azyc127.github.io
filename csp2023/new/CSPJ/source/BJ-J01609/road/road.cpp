#include <iostream>
using namespace std;

int u[100005], a[100005];

int n, d;
double ans;
void op(int beg, int end)
{
	if (beg == end) 
	{
		ans += 1.0*a[beg]*u[beg]/d;
		return;
	}
	int mini = beg;
	for (int i = beg; i < end; i++) {
		if (a[i] < a[mini]) mini = i;
	}
	op(beg, mini);
	for (int i = mini; i < end; i++)
		ans += 1.0*a[mini]*u[i]/d;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	for (int i = 1; i < n; i++)
		cin >> u[i];
	for (int i = 1; i <= n; i++)
		cin >> a[i]; 
	op(1, n+1);
	cout << ans << endl;
	return 0;
}
