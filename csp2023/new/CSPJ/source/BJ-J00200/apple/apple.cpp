#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
ll n = 0;
ll num1[10000010];
ll cnt = 0;
ll num2 = 0;
int main(){
    freopen("apple.in" , "r" , stdin);
    freopen("apple.out" , "w" , stdout);
	memset(num1 , 0 , sizeof(num1));
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
		num1[i] = i;
	}
    if(n <= 3){
		cout << n << " " << n;
		return 0;
	}
	int list = n;
    while(list != 0){
		int cc = 0;
		for(ll i = 1 ; i <= list ; i += 3){
			if(num1[i] == n){
				num2 = cnt + 1;
			}
			num1[i] = 1e9 + 10;
			cc++;
		}
		list -= cc;
		cnt++;
		sort(num1 + 1 , num1 + 1 + n);
	}
	cout << cnt << " " << num2;
	return 0;
}
