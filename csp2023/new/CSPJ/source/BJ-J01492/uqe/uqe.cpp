#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int func(int t)
{
	int x = t;
	string ans = "";
	int a = 1;
	int last = x;
	while (x != 1){
		for (int i = last+1; i <= x; i++){
			int cnt = 0;
			while (x % i == 0){
				cnt++;
				x /= i;
			}
			if (cnt) a *= cnt/2;
		}
	}
	return a;
}
int gcd(int x, int y){
	int temp = x%y;
	while (temp > 0){
		x = y;
		y = temp;
		temp = x%y;
	}
	return y;
}
int main() {
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int t, m;
	for (int i = 1; i <= t; i++){
		int a, b, c;
		cin >> a >> b >> c;
		int dt = b*b-4*a*c;
		if (dt < 0){
			cout << "NO" << endl;
			continue;
		}
		int u = gcd(-b, 2*a);
		if (u == 2*a){
			printf("%d", -b/(2*a));
		}
		else printf("%d/%d", -b/u, (2*a)/u);
		if (sqrt(dt) != int(sqrt(dt))){
			int x = func(dt);
			if (x == 1) printf("+sqrt(%d)\n", dt);
			else printf("+%d*sqrt(%d)\n", x, dt/x/x);
		}
		else if (dt) cout << "+" << sqrt(dt) << endl;
	}
	return 0;
}