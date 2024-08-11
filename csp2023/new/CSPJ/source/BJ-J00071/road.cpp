#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int n, d;
	cin >> n >> d;
	int v[100005], a[100005], mina = 100005, sumv = 0, ma[100005];
	for(int i = 0; i < n - 1; i++){
		cin >> v[i];
		sumv += v[i];
	}
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] < mina){
			mina = a[i];
		}
		if(i == 0){
			ma[i] = a[i];
			continue;
		}
		if(a[i] < ma[i - 1]){
			ma[i] = a[i];
		}else{
			ma[i] = ma[i - 1];
		}
	}
	if(a[0] == mina){
		int ans = a[0] * (sumv / d);
		if(sumv % d != 0) ans += a[0];
		cout << ans;
		return 0;
	}
	int cst = 0, lftd = 0, j = 0, k = 0;
	for(int i = 0; i < n - 1; i += j){
		int dis = 0, litr = 0;
		j = 0;
		while(ma[i] <= ma[k] && k < n){
			dis += v[k];
			//cout << dis << ' ' << v[j] << ' ' << ma[k] << endl;
			j++;
			k++;
		}
		dis -= lftd;
		litr = dis / d;
		if(dis % d != 0) litr++;
		cst += litr * a[i];
		lftd = litr * d - dis;
		//cout << litr << ' ' << lftd << ' ' << cst << ' ' << i << endl;
	}
	cout << cst;
	return 0;
}
