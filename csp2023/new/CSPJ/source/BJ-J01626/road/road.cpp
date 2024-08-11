#include<bits/stdc++.h>
using namespace std;
const int M = 100002;
int dp, v[M], a[M];
int n, d, chy, cost = 0;
double y = 0;

int main(){
	ios::sync_with_stdio(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	for(int i = 0; i < n - 1; i ++){
		cin >> v[i];
	}
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	chy = a[0];
	for(int i = 0; i < n; i ++){
		if(a[i] < chy){
			chy = a[i];
		}
		int tn = ceil(v[i] * 1.0 / d - y);
		if(tn > 0){
			cost += tn * chy;
			y += tn;
			y -= v[i] * 1.0 / d;
		}
		else{
			y -= v[i] * 1.0 / d;
		}
	}
	cout << cost;
	return 0;
}