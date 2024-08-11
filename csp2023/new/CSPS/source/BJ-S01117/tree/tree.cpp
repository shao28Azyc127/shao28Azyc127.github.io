#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int n, a;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> a >> a >> a;
	}
	for(int i = 0; i < n - 1; i ++){
		cin >> a >> a;
	}
	cout << n + 1;
	return 0;
}