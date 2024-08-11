#include<bits/stdc++.h>
using namespace std;

int n = 0;
int ans1 = 0, ans2 = 0;

int main (){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	
	scanf("%d", &n);
	int x = n;
	int y = 0;
	bool flag = 0;
	for (ans1 = 0; x > 0; ans1++){
		if (!flag && x % 3 == 1){
			ans2 = ans1;
			flag = true;
		} 
		y = x / 3 + 1;
		if (x % 3 == 0) y--;
		x -= y;
	}
	
	printf("%d %d", ans1, ans2 + 1);
	
	return 0;
}