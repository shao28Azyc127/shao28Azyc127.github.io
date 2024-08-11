#include <bits/stdc++.h>
using namespace std;

int n, t, num;
int c(int n){
	if (n % 3 == 0) {
		return n / 3;
	}
	return n / 3 + 1;
}
int main(){
	//freopen("apple.in", "r", stdin);
	//freopen("apple.out", "w", stdout);
	cin >> n;
	if (n == 1) {
		cout << "1 ";
		return 0;
	}
	if (n == 2) {
		cout << "2 ";
		return 0;
	}
	if (n == 3) {
		cout << "3 ";
		return 0;
	}
	int tmp = n;
	while (tmp > 3) {
		num++;
		tmp = tmp - c(tmp);
	}
	cout << num + tmp << " ";
	if (n % 3 == 1) {
		cout << "1";
		return 0;
	}
	int k = n;
	while (1) {
		int j = 0;
		for (int i = 1; i <= k; i++) { 
			if (i % 3 != 1) {
				j++;
			}
		}
		t++;
		if (j % 3 == 1) {
			cout << t + 1;
			return 0;
		}
		if (j <= 3) {
			cout << t + j;
			return 0;
		}
		k = 0;
		for (int i = 1; i <= j; i++) {
			if (i % 3 != 1) {
				k++;
			}
		}
		t++;
		if (k % 3 == 1) {
			cout << t + 1;
			return 0;
		}
		if (k <= 3) {
			cout << t + k;
			return 0;
		}
	}
 	return 0;
}
