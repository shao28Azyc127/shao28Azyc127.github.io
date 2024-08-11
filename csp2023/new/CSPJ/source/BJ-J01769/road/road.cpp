#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, d;
long long ans = 0;
int now;
int a[N], w[N];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    //cin >> n >> d;
    scanf("%d%d", &n, &d);
    for(int i = 2; i <= n; i++){
    	//cin >> a[i];
    	scanf("%d", &a[i]);
    	a[i] += a[i-1];
    	//cout << a[i] << endl;
	}
	for(int i = 1; i <= n; i++){
		//cin >> w[i];
		scanf("%d", &w[i]);
	}
	int w1 = 1e6;
	int i = 1;
	while(now < a[n]){
		if(now >= a[i]){
			w1 = min(w1, w[i]);
			i++;
		}
		now += d;
		ans += w1;
		//cout <<"w1 = "<< w1 << " " <<"now = " << now << "ans = " << ans << endl;
	}
	cout << ans;
	return 0;
}
