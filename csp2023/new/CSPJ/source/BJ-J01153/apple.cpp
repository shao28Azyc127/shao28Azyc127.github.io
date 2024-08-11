#include <iostream>
using namespace std;
int main()
{
	int n, cnt = 0, pos;
	bool flag = false;
	cin >> n;
	while (true)
	{
		cnt++;
		if (n % 3 == 1 && !flag) pos = cnt, flag = true;
		n = n * 2 / 3;
		if (n == 0) break;
	}
	cout << cnt << " " << pos;
	return 0;
}