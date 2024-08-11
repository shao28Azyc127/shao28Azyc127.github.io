#include <iostream>
#include <algorithm>
using namespace std;

int a[100005], b[100005], s[100005];

int main()
{
	int n, d, p;
	cin >> n >> d;
	for (int i = 1; i <= n - 1; i++) 
	{
		cin >> a[i];
		p += a[i];
	}
	for (int i = 1; i <= n; i++) 
	{
		cin >> b[i];
	}	
	if (p % d == 0) cout << p % d * b[1];
	else cout << (p % d + 1) * b[1];
	return 0;
}