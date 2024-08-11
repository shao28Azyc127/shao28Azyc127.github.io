#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int t, m;
	cin >> t >> m;
	for (int i = 1; i <= t; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (b * b - 4 * a * c < 0) cout << "NO" << endl;break;
		if (c == 0) cout << b << "/" << a; 
	}
	return 0;
}