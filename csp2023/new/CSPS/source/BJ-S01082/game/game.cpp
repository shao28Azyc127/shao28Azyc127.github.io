#include <fstream>
#include <stack>

using namespace std;

ifstream cin("game.in");
ofstream cout("game.out");

stack<int> s;

void clear()
{
	while (!s.empty())
		s.pop();
}

int main()
{
	int n;
	long long ans = 0;
	string a;
	cin >> n >> a;
	for (int i = 0 ; i < n; i++)
		for (int j = i + 1; j < n; j += 2)
		{
			clear();
			for (int k = i; k <= j; k++)
				if (!s.empty() && a[s.top()] == a[k])
					s.pop();
				else
					s.push(k);
			if (s.empty())
				ans++;
		}
	cout << ans;
	return 0;
}
