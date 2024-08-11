#include <iostream>
#include <map>
#include <vector>

#define ONLINE

using namespace std;

inline int end_prog()
{
	fclose(stdout);
	return 0;
}

int main()
{
#ifdef ONLINE
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
#endif
	
	int n;
	vector<vector<int>> states;

	cin >> n;
	states.resize(n, vector<int>(5));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j)
			cin >> states[i][j];
	}

	map<vector<int>, int> passwds;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 10; ++k) {
				states[i][j] = (states[i][j] + 1) % 10;
				++passwds[states[i]];
			}

			if (j == 0)
				continue;

			for (int k = 0; k < 10; ++k) {
				states[i][j] = (states[i][j] + 1) % 10;
				states[i][j - 1] = (states[i][j - 1] + 1) % 10;
				++passwds[states[i]];
			}
		}
	}

	long long cnt = 0;

	for (const auto& passwd : passwds) {
		if (passwd.second == n)
			++cnt;
	}

	cout << cnt << endl;
	return end_prog();
}
