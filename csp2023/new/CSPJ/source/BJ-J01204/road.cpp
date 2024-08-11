#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int n , d , cost = 0;
int v[MAXN] , a[MAXN];
int len[MAXN];
int main() {
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> d;
	for(int i = 1;i <= n-1;i++)
		cin >> v[i];
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n-1;i++)
		len[i+1] = len[i] + v[i];
	int pos = 1 , exdis = 0;
	while(pos < n) {
	
		int aim = pos , pri = 1e9;
		for(int i = pos;i <= n;i++) {
			if(a[aim] > a[i] && len[i] - len[aim] >= exdis) {
				aim = i;
				break;
			}
		}
		for(int i = pos;i <= n;i++) {
			if(len[i] - len[pos] > exdis) 
				break;
			pri = min(pri , a[i]);
		}
		
		if(aim == pos)
			aim = n;
		cost += ((len[aim] - len[pos] - exdis) / d + (((len[aim] - len[pos] - exdis) % d == 0)?0:1)) * pri;
		exdis = d - (len[aim] - len[pos] - exdis) % d;
		//cout << pos << "  ->  " << aim << endl;
		//cout << "Have gone " << exdis << "km" << endl;
		//cout << "Price : 1L " << pri << "$" << endl;
		//cout << "Total cost : " << cost << "$" << endl;
		pos = aim;	
	}
	cout << cost << endl;
	return 0;
}