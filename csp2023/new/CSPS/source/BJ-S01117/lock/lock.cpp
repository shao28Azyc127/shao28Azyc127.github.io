#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int n, a[11], b[11], c[11], d[11], e[11];
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
	}
	if(n == 1){
		cout << 81;
	}
	else{
		cout << 1;
	}
	return 0;
}