#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n, ans;
	scanf("%d", &n);
	int sum = 0, sum_times = 0, now_left = n;
	bool flag = false;
	while(sum < n){
		sum_times++;
		if(!flag && now_left % 3 == 1){
			ans = sum_times, flag = true;
		}
		sum += (now_left + 2) / 3;
		now_left -= (now_left + 2) / 3;
	}
	printf("%d %d", sum_times, ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}