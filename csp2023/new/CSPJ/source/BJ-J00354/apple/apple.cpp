#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n;
	scanf("%lld", &n);
	int s = n,cnt1 = 0;
	while (s > 1) {
		cnt1++;
		s -= s / 3 + (s % 3 != 0);
	} 
	int cnt = 1;
	while (n % 3 != 1) {
		n -= n / 3 + (n % 3 != 0);
		cnt++;
	}
	cout << cnt1 + 1 << " " << cnt << endl;
	
	return 0;
}
