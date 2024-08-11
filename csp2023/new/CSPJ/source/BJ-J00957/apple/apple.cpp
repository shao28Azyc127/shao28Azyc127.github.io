#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in", "r", stdin);	
	freopen("apple.out", "w", stdout);
	int n;
	cin >> n;
	int k = 0;
	int x = n;
	while(x){
		k ++;
		x -= ceil(1.0 * x / 3);
	}
	cout << k << " ";
	x = n;
	for(int i = 1;i <= k;i ++){
		if(x % 3 == 1){
			cout << i;
			return 0;
		}else{
			x -= ceil(1.0 * x / 3);
		}
	}
} 