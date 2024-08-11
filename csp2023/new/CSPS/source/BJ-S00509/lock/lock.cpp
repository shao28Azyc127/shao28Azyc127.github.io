#include<bits/stdc++.h>
using namespace std;

#define FILE "lock"
void redirIO() {
	string obj = FILE;
	if (obj != "") {
		freopen(FILE".in", "r", stdin);
		freopen(FILE".out", "w", stdout);
	}
}

int n, a[8];
string state;

map<string, int> bucket;

string setst() {
	state = "11111";
	for (int i = 1; i <= 5; i++)
		state[i - 1] = a[i] + '0';
	return state;
}

int main() {
	redirIO();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			scanf("%d", &a[j]);
		}
		for (int j = 1; j <= 5; j++) {	//change one
			for (int k = 1; k <= 9; k++) {
				(a[j] += 1) %= 10;
				bucket[setst()]++;
			}
			(a[j] += 1) %= 10;
		}
		for (int j = 1; j < 5; j++) {	//change two
			for (int k = 1; k <= 9; k++) {
				(a[j] += 1) %= 10;
				(a[j + 1] += 1) %= 10;
				bucket[setst()]++;
			}
			(a[j] += 1) %= 10;
			(a[j + 1] += 1) %= 10;
		}
	}
	int cnt = 0;	//check
	for (auto _a:bucket)
		if (_a.second == n)
			cnt++;
	printf("%d", cnt);
	return 0;
}
