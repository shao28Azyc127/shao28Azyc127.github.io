#include <bits/stdc++.h>
using namespace std;
struct shu{
	long long high;
	int b, c;
}a[100005];
int n;
long long h[100005]={-1};
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].high >> a[i].b >> a[i].c;
	}
	int ok = 0;
	int i;
	for(i = 1; ok != n; i++){
		if(i <= n) h[i] = 0;
		for(int j = i-1; j >= 1; j--){
			if(h[i] == -2) continue;
			h[i] += max(a[i].b+i*a[i].c, 1);
			if(h[i] >= a[i].high){
				ok++;
				h[i] = -2;
			}
		}
	}
	cout << i-1;
	return 0;
}
