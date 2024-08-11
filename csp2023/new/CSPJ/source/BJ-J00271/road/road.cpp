#include <iostream>
#include <cmath>
using namespace std;

long long n,d,chp = 2e9,cost,oil;
long long v[100005];
long long pr[100005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin >> n >> d;
	for(int i = 2;i <= n;i++){
		cin >> v[i];
	}
	for(int i = 1;i <= n;i++){
		cost += ceil(1.0 * (v[i] - oil) / d) * chp;
		oil = d * ceil(1.0 * (v[i] - oil) / d) - (v[i] - oil);
		// cout << cost << ' ' << oil << endl;
		cin >> pr[i];
		if(pr[i] < chp){
			chp = pr[i];
		}
	}

	cout << cost;
}