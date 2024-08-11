// #include<bits/stdc++.h>
#include<iostream>
#include<stack>
using namespace std;
#define ll long long
#define N 2000005
int n, ans;
char a[N];
stack<char> s;

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d", &n);
	cin >> a;
	for (int i=0;i<n-1;i++) {
		for (int j=i+2;j<=n;j+=2) {
			while (!s.empty()) {
				s.pop();
			}
			for (int k=i;k<j;k++) {
				if (!s.empty() && s.top() == a[k]) {
					s.pop();
				} else {
					s.push(a[k]);
				}
			}
			if (s.empty()) {
				ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
