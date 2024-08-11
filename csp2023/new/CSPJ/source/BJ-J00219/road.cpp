#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 10;
int v[N];
int p[N];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, d, i, j;
	int s = 0;//total price
	int x = N;//the lowest price per liter now
	int t;//liters
	int c = 0;//complement distance
	int r = 0;//distance to the lowwer price
	cin >> n >> d;
	for(i = 0; i < n - 1; i++)
	{
		cin >> v[i];
	}
	for(i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	
	for(i = 0; i < n; i = j)
	{
		for(j = i; j < n; j++)
		{
			if(j != i)
			r += v[j];
			if(p[j] < x and j != n - 1)
			{
				t = ceil(1.0 * (r - c) / d);
				s += t * p[i];
				c = t * d - (r - c);
				x = p[j];
				cout << j + 1 << ' ' << r << ' ' << p[j] << t << c << endl;
				r = 0;
				break;
			}
		}
	}
	cout << s + c / d * p[j];
	
	
	return 0;
}