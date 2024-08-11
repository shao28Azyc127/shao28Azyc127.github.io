

#include <bits/stdc++.h>

using namespace std;

int T;
int M;
int a[5009];
int b[5009];
int sqr[1009];
int c[5009];
int delta[5009];
int twoa[5009];
int negab[5009];

void tairitsu(int a, int b){
	int neg = 1;
	if(a < 0){
		a = a * -1;
		neg = neg * -1;
	}
	if(b < 0){
		b = b * -1;
		neg = neg * -1;
	}
	int hikari = __gcd(a,  b);
	a = a / hikari;
	b = b / hikari;
	if(b == 1){
		cout << neg * a;
		return;
	}
	if(a == 0){
		cout << 0;
		return;
	}
	cout << neg * a << '/' << b;
	return;
}

int main(){
	freopen("uqe.in" , "r" , stdin);
	freopen("uqe.out" , "w" , stdout);
	cin >> T >> M;
	for(int i = 1; i <= T ; i++){
		cin >> a[i] >> b[i] >> c[i];
		delta[i] = (b[i] * b[i]) - (4 * a[i] * c[i]);
		twoa[i] = a[i] * 2;
		negab[i] = -1 * b[i];
	}
	
	for(int i = 2; i <= 1000; i++){
		sqr[i] = i * i;
	}
	
	for(int i = 1 ; i <= T ; i++){
		if(delta[i] < 0){
			cout << "NO" << endl;
		}else{
			if(delta[i] == 0){
				tairitsu(negab[i] , twoa[i]);
				cout << endl;
			}else{
				int multiplier = 1;
				for(int j = 2; j <= M; j++){
					if(delta[i] % sqr[j] == 0){
						while(delta[i] % sqr[j] == 0){
							multiplier *= j;
							delta[i] = delta[i] / sqr[j];
						}
					}
				}
				if(delta[i] == 1){
					if(twoa[i] < 0){
						negab[i] -= multiplier;
					}else{
						negab[i] += multiplier;
					}
					tairitsu(negab[i] , twoa[i]);
				}else{
					bool deltaneg = false;
					int neg = 1;
					if(negab[i] < 0){
						negab[i] = negab[i] * -1;
						neg = neg * -1;
					}
					if(twoa[i] < 0){
						twoa[i] = twoa[i] * -1;
						neg = neg * -1;
						deltaneg = true;
					}
					int hikari = __gcd(negab[i],  twoa[i]);
					negab[i] = negab[i] / hikari;
					twoa[i] = twoa[i] / hikari;
					if(negab[i] != 0){
						if(twoa[i] == 1){
							cout << negab[i] * neg;
						}else{
							cout << negab[i] * neg << '/' << twoa[i];
						}
					}
					twoa[i] = twoa[i] * hikari;
					if(negab[i] != 0){
						cout << '+';
					}
					if(multiplier == 1){
						cout << "sqrt(" << delta[i] << ")";
						if(twoa[i] != 1){
							cout << "/" << twoa[i];
						}
					}else{
						hikari = __gcd(twoa[i] , multiplier);
						twoa[i] /= hikari;
						multiplier /= hikari;
						if(twoa[i] == 1){
							if(multiplier != 1){
								cout << multiplier << "*sqrt(" << delta[i] << ")";
							}else{
								cout << "sqrt(" << delta[i] << ")";
							}
						}else{
							if(multiplier == 1){
								cout << "sqrt(" << delta[i] << ")/" << twoa[i];
							}else{
								cout << multiplier << "*sqrt(" << delta[i] << ")/" << twoa[i];
							}
						}
					}
				}
				cout << endl;
			}
		}
	}
	
	return 0;

}