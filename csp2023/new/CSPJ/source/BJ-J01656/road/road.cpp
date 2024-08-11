#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll n, d;
ll v[N], a[N];
ll ipre[N];
ll isum;
ll Ys;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld %lld", &n, &d);
	for(int i = 1; i <= n-1; i++){
		scanf("%lld", &v[i]);
		if(i == 1){
			ipre[i] = 0;
		} else {
			ipre[i] = ipre[i-1] + v[i-1];
		}
		
	}
	ipre[n] = ipre[n - 1] + v[n - 1];
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	/*for(int i = 1; i <= n; i++){
		cout << ipre[i] << " ";
	}*/
	ll idis = 0;
	ll ist = 1;
	for(int i = 2; i <= n; i++){
		if(a[ist] > a[i]){
			//cout << i;
			idis = ipre[i] - ipre[ist] - Ys;
			//cout << "ipre[i]=" << ipre[i] << "\n";
			//cout << "ipre[ist]=" << ipre[ist] << "\n";
			//cout << "ids=" << idis << "\n";
			Ys = 0;
			if(idis % d == 0){
				isum += idis / d * a[ist];
			} else {
				isum += (idis / d + 1) * a[ist];
				Ys += (idis / d + 1) * d - idis;
			}
			//cout << "isum=" << isum << "\n";
			//cout << "Ys=" << Ys << "\n";
			idis = 0;
			ist = i;
		} else if(i == n){
			idis = ipre[i] - ipre[ist] - Ys;
			//cout << "ipre[i]=" << ipre[i] << "\n";
			//cout << "ipre[ist]=" << ipre[ist] << "\n";
			//cout << "ids=" << idis << "\n";
			Ys = 0;
			if(idis % d == 0){
				isum += idis / d * a[ist];
			} else {
				isum += (idis / d + 1) * a[ist];
				Ys += (idis / d + 1) * d - idis;
			}
			//cout << "isum=" << isum << "\n";
			//cout << "Ys=" << Ys << "\n";
			idis = 0;
			ist = i;
		}
	}
	printf("%lld", isum);
	return 0;
}
