#include<iostream>
using namespace std;
int n, d[5], a[10], ten[6], ans;
bool dup(int x) {
	for(int i = 0; i < n; i++) {
		if(x == a[i]) return true;
	}
	return false;
}
int turn(int w, int d, int i) {
	int digit = w / ten[d] % 10;
	w -= digit * ten[d];
	digit = (digit + i) % 10;
	w += digit * ten[d];
	return w;
}
bool check(int w, int a) {
	for(int d = 0; d < 5; d++) {
		for(int i = 1; i <= 9; i++) {
			if(turn(w, d, i) == a) return true;
		}
	}
	for(int d = 0; d < 4; d++) {
		for(int i = 1; i <= 9; i++) {
			int tmp = turn(w, d, i);
			if(turn(tmp, d + 1, i) == a) return true;
		}
	}
	return false;
}
int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	ten[0] = 1;
	for(int i = 1; i < 6; i++) ten[i] = ten[i-1] * 10;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int tmp = 0;
		for(int j = 0; j < 5; j++) {
			cin >> d[j];
			tmp = tmp * 10 + d[j];
		}
		a[i] = tmp;
	}
	for(int w = 0; w < 100000; w++) {
		if(dup(w)) continue;
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			if(check(w, a[i])) cnt++;
		}
		if(cnt == n) ans++;
	}
	cout << ans << endl;
	return 0;
}