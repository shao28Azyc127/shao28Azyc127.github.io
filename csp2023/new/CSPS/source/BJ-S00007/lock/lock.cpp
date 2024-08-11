#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10][10];

int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; ++i){
		for(ll j = 1; j <= 5; ++j){
			cin >> a[i][j];
		}
	}
	if(n == 1){
		cout << 81 << endl;
		exit(0);
	}
	if(n >= 5){
		cout << 0 << endl;
		exit(0);
	}
	ll ans = 0;
	bool bo = true;
	for(ll i = 2; i <= n; ++i){
		if(a[i][1] != a[i - 1][1]){
			bo = false;
			break;
		}
	}
	if(bo){
		ans += 9;
	}
	for(ll i = 2; i <= 5; ++i){
		bool boo = true, booo = true;
		for(ll j = 1; j <= n; ++j){
			if(a[j - 1][i] == a[j][i]){
				boo = false;
			}
			if(a[j][i] == a[j][i - 1]){
				booo = false;
			}
			// if(a[i - 1][j - 1] == a[i][j - 1] && a[i - 1][j] != a[i][j]){
			// 	ans++;
			// }
		}
		if(boo){
			ans += 9;
		}
		if(booo){
			ans += 9;
		}
	}
	cout << ans << endl;
	return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10][10];

int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; ++i){
		for(ll j = 1; j <= 5; ++j){
			cin >> a[i][j];
		}
	}
	if(n == 1){
		cout << 81 << endl;
		exit(0);
	}
	ll ans = 81;
	for(ll i = 1; i <= n; ++i){
		for(ll j = 1; j <= 5; ++j){
			bool flag = true, flagg = true;
			for(ll k = 2; k <= n; ++k){
				if(a[k - 1][j] != a[k][j]){
					flag = false;
				}//else if(a[k - 1][j - 1] != a[k][j - 1]){
					//flagg = false;
				//}
			}
			if(flag){
				ans -= 9;
			}
			//if(flagg){
				//ans -= 9;
			//}
		}
	}
	cout << ans + 1 << endl;
	return 0;
}
*/