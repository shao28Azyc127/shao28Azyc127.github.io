#include <fstream>

using namespace std;

ifstream cin("apple.in");
ofstream cout("apple.out");

int main()
{
	bool a = 1;
	int n;
	int s = 0, ans;
	cin >> n;
	while (n > 0)
	{
		s++;
		if ((n - 1) % 3 == 0 && a)
		{
			ans = s;
			a = 0;
		}
		n -= 1 + (n - 1) / 3;
	}
	cout << s << ' ' << ans;
	return 0;
}