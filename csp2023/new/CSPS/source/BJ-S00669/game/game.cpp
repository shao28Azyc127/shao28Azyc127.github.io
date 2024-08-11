#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    long long n;
    cin >> n;
    char a[2000005];
    scanf("%s", a);
    long long sum = 0, i = 0;
    while (i < n) {
    	if (a[i] == '0') {
    		i++;
    		continue;
		}
    	long long j=0;
    	for (long long o = i+1; ; o++) {
    		if (a[o] != '0') {
    			j = o;
    			break;
			} else {
				continue;
			}
		}
        if (a[i] == a[j]) {
            sum += 1;
            a[i] = '0';
			a[j] = '0';
            i = 0;
        }
        i++;
    }
    for (long long i = 0; i < n; i++) {
    	if (a[i] == '0') continue;
    	for (long long j = i+1; j < n; j++) {
    		if (a[j] == '0') continue;
    		if (a[i] == a[j]) {
    			sum += 1;
    			a[i] = '0';
    			a[j] = '0';
    			continue;
			}
			if (a[i] != a[j]) {
				break;
			}
		}
	}
    if (n == 2) {
    	sum -= 1;
	}
    cout << sum+1;
    return 0;
}
