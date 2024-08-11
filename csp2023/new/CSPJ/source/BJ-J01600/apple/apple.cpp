#include <bits/stdc++.h>
using namespace std;
int ans=0, total=0;
int flag = 0;
int main (){
    freopen ("apple.in","r",stdin);
    freopen ("apple.out","w",stdout);
	int n;
	cin >> n;
	total = 0;
	while (n > 0){
	    total += 1 ; // 1 2 3 4 5
		if (n % 3 == 0) {
            //cout << n << endl;
			n = n / 3 * 2;
            //cout << n;
		}// n -> 2
		else if (n % 3 == 1) {
			if (flag == 0) ans = total; // ans = 5;
			n = n / 3;
			n = n * 2;
			flag = 1;
		}
		else if (n % 3 == 2){
			n = n / 3 * 2 + 1; // n -> 5 n -> 3 n -> 1
		}
		//cout << n << endl;
	}
	cout << total << " " << ans;
    return 0;
}
