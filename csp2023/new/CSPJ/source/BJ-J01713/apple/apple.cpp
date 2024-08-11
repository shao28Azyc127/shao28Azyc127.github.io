#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n, day = 0, dayn = 0;
	cin >> n;
	while (n > 0){
		int tmp = n;
		day++;
		for (int i = 1 ; i <= n ; i += 3){
			if (i == n && dayn == 0){
				dayn = day;
			}
			tmp--;
		}
		n = tmp;
	}
	cout << day << " " << dayn << endl;
	return 0;
}