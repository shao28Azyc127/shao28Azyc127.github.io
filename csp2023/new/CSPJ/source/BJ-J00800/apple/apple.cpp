#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
mt19937 rnd((unsigned long long)new char);
void file(){freopen("apple.in", "r", stdin); freopen("apple.out", "w", stdout);}
void INIT(){ios::sync_with_stdio(false);}
const bool File = 1;
int n, m, day, tmp;
bool fl = 0;
int main(){ File ? file() : void(); INIT();
	cin >> n, m = n;
	while(m > 0){
		if(m % 3 == 1 && !fl) fl = 1, tmp = day + 1;
		day++; m -= ceil(m / 3.0);
	}
	cout << day << " " << tmp << endl;
	return 0;
}