#include<bits/stdc++.h>
using namespace std;
int main(){

	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n = 0;
	bool a[1001+5];
	for(int i = 1; i <= 1000; i++){
		a[i] = true;
	}
	cin >> n;
	int ans = floor(n / 2) + 1;
	for(int i = 1; i <= n; i++){
		int k = n + 1;
		for(int j = 1; j <= n; j++){
			if(a[j] == true){
				k = j;
				break;
			}
		}
		for(int j = k; j <= n; j += 3){
			if(j == n){
				printf("%d %d", ans, i);
				return 0;
			}
			a[i] = false;
		}
	}
	
	return 0;
}