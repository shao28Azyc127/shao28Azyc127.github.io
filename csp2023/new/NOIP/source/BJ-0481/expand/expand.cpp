#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int c, n, m, q;

int a[500005], b[500005];

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out","w",stdout);
	cin >> c >> n >> m >> q;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
	}
	for(int i = 0 ; i < m ; i++)
	{
		cin >> b[i];
	}
	if((a[n-1]-b[m-1])*(a[0]-b[0]) <= 0)
	{
		cout << "0";
	}
	else
	{
		cout << "1";
	}
	while(q > 0)
	{
		q--;
		int kx, ky;
		cin >> kx >> ky;
		for(int i = 0 ; i < kx ; i++)
		{
			int aa, bb;
			cin >> aa >> bb;
			a[aa] = bb;
		}
		for(int i = 0 ; i < ky ; i++)
		{
			int aa, bb;
			cin >> aa >> bb;
			b[aa] = bb;
		}
		if((a[n-1]-b[m-1])*(a[0]-b[0]) <= 0)
		{
			cout << "0";
		}
		else
		{
			cout << "1";
		}
	}
	cout << endl;
	return 0;
}