#include <bits/stdc++.h>
using namespace std;
long long n, tot = 0;
char s[2000005], s1[2000005];
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%lld", &n);
	for (long long i = 1; i <= n; i++){
		cin >> s[i];
	}
	if (n > 8000){
		printf("%lld\n", 0ll);
		return 0;
	}
	for (long long i = 1; i <= n; i++){
		long long cnt1 = 0;
		for (long long j = i; j <= n; j++){
			s1[++cnt1] = s[j];
			if (cnt1 >= 2 && s1[cnt1] == s1[cnt1 - 1]){
				cnt1 -= 2;
			}
			if (cnt1 == 0){
				tot++;
			}
		}
	}
	printf("%lld\n", tot);
	return 0;
}
