#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	freopen("apple.in" , "r" , stdin);
	freopen("apple.out" , "w" , stdout);
	cin >> n;
	int tot = 0 , cnt = 1 , lst = n;
	while(n) {
		tot++;
		if(lst%3 != 1) {
			cnt++;
			lst -= (n-1)/3+1;
		}
		n -= (n-1)/3+1;
	}
	cout << tot << " " << cnt << endl;
	return 0;
}