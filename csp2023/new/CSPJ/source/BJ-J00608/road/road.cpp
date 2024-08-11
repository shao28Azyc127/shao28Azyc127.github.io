

#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int d;
int v[100009];
int price[100009];
int dp[100009];
int presum[100009];
int oil[100009];
int curprice;
int res;
int curplace = 1;

signed main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	
	memset(dp , 0x3f, sizeof(dp));	
	memset(presum , 0 , sizeof(presum));
	cin >> n >> d;
	for(int i = 2; i <= n; i++){
		cin >> v[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> price[i];
	}
	
	for(int i = 1; i <= n; i++){
		presum[i] = presum[i - 1] + v[i]; 
	}
	
	for(int i = 1; i <= n; i++){
		oil[i] = presum[i] / d;
		if(presum[i] % d != 0){
			oil[i] ++;
		}
	}
	curprice = price[1];
	for(int i = 2; i < n; i++){
		if(price[i] < curprice){
			curprice = price[i];
			res += (oil[i] - oil[curplace]) * price[curplace];
			curplace = i;
		}
	}
	res += (oil[n] - oil[curplace]) * price[curplace];
	cout << res << endl;
	
//how to prove it is right?
//assuming we have three numbers : a1 , a2 , a3
//let a2 > a1 > a3
//for the trip between a1 and a2 , we should use: a1 * used
//since the oil cost is same , we will always use the lowest amount of price
//so this method is technically right
	return 0;
}

/*
freopen not feropen
  10 10 10 10
0 10 20 30 40
9 8 9 6 5
0 3 5 8 10
dp[i]
0  1  2  3  4  5
0  0 27 43  
used oil;
0  0  3  5
is 2 star really hard? I got rks 12.66
*/ 