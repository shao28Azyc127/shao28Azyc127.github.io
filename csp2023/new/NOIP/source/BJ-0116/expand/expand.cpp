#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 5e5+5;
long long bakx[N], baky[N], x[N], y[N];
int a[N], b[N], c[N], d[N];
int T, n0, m0, n, m, q;
long long smx[N], smy[N], bmx[N], bmy[N];
pii tx[N];

bool solve(){
	if((x[1]-y[1])*(x[n]-y[m])<=0) return 0;
	if(x[1]<y[1]){
		for(int i=1;i<=max(n, m);i++) swap(x[i], y[i]);
		swap(n, m);
	}
	for(int i=1;i<=n;i++) smx[i] = max(smx[i-1], x[i]);
	for(int i=1;i<=m;i++) smy[i] = max(smy[i-1], y[i]);
	for(int i=n;i>=1;i--) bmx[i] = max(bmx[i+1], x[i]);
	for(int i=m;i>=1;i--) bmy[i] = max(bmy[i+1], y[i]);
	
	for(int i=1;i<=n;i++){
		tx[i].first = x[i];
		tx[i].second = i;
	}
	sort(tx+1, tx+n+1);
	int j = 1;
	for(int i=n;i>=1;i--){
		while(j<=m && y[j]>=tx[i].first) j++;
		if(j>m) return 0;
		a[tx[i].second] = j;
	}
//	for(int i=1;i<=n;i++) cout << a[i] << ' '; cout << endl;
	for(int i=1;i<=n;i++){
		if(smy[a[i]-1]>=smx[i]) return 0;
	}
	j = m;
	for(int i=n;i>=1;i--){
		while(j>=1 && y[j]>=tx[i].first) j--;
		if(j<1) return 0;
		c[tx[i].second] = j;
	}
	for(int i=1;i<=n;i++){
		if(bmy[c[i]+1]>=bmx[i]) return 0;
	}
/*	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(y[j]<x[i]){
				c[i] = j;
				break;
			}
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(x[i]>y[j]){
				b[j] = i;
				break;
			}
		}
		if(!b[j]) return 0;
	}
	for(int j=1;j<=m;j++){
		for(int i=n;i>=1;i--){
			if(x[i]>y[j]){
				d[j] = i;
				break;
			}
		}
	}
//	for(int i=1;i<=n;i++) cout << a[i] << ' '; cout << endl;
//	for(int i=1;i<=m;i++) cout << b[i] << ' '; cout << endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]>j && b[j]>i) return 0;
			if(c[i]<j && d[j]<i) return 0;
		}
	}*/
	return 1;
}

int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	cin >> T >> n0 >> m0 >> q;
	
	for(int i=1;i<=n0;i++) cin >> bakx[i], x[i] = bakx[i];
	for(int i=1;i<=m0;i++) cin >> baky[i], y[i] = baky[i];
	n = n0, m = m0;
	cout << solve();
	while(q--){
		memset(bmx, 0, sizeof(bmx));
		memset(bmy, 0, sizeof(bmy));
		memset(smx, 0, sizeof(smx));
		memset(smy, 0, sizeof(smy));
		n = n0, m = m0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memcpy(x, bakx, sizeof(x));
		memcpy(y, baky, sizeof(y));
		int kx, ky;
		cin >> kx >> ky;
		for(int i=0;i<kx;i++){
			int p, v;
			cin >> p >> v;
			x[p] = v;
		}
		for(int i=0;i<ky;i++){
			int p, v;
			cin >> p >> v;
			y[p] = v;
		}
//		for(int i=1;i<=n;i++) cout << x[i] << ' '; cout << endl;
//		for(int i=1;i<=m;i++) cout << y[i] << ' '; cout << endl;
		cout << solve();
	}
	
	return 0;
}
