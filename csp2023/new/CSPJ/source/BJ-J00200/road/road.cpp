#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
#define ll long long
int n , d;
int v[100010];
int q[100010];
int dp[3010][3010];
int sum = 0;
int mini = 1e9;
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
    cin >> n >> d;
    for(int i = 1 ; i <= n - 1 ; i++){
		cin >> v[i];
		sum += v[i];
	}
	for(int i = 1 ; i <= n ; i++){
	    cin >> q[i];
	}
    cout << (sum/d) * q[1];
	return 0;
}
