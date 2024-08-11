#include<bits/stdc++.h>
using namespace std;

int T, M;
int a, b, c, del;

int gcd(int a, int b){
	if (a == 0 || b == 0) return 1;
	while(1){
		a = a % b;
		if (a == 0) return b;
		b = b % a;
		if (b == 0) return a;
	}
}

int abs(int a){
	if (a >= 0) return a;
	else return -a;
}

int ssqrt(int a){
	int ans = 1;
	for (int i = 2; i <= (int)sqrt(a); i++){
		while(a % (int)pow(i, 2) == 0){
			ans *= i;
			a /= pow(i, 2);
		} 
	}
	return ans;
}

int main (){
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	
	scanf("%d %d", &T, &M);
	for (int i = 1; i <= T; i++){
		scanf("%d %d %d", &a, &b, &c);
		del = pow(b, 2) - 4*a*c;
		if (del < 0){
			printf("NO\n");
			continue;
		}
		if (del == 0){
			if (b != 0){
				if (a * b > 0)
					printf("-");
				printf("%d", abs(-b) / gcd(abs(b), abs(2*a)));
				if (abs(2*a) / gcd(abs(b), abs(2*a)) != 1)
				printf("/%d", abs(2*a) / gcd(abs(b), abs(2*a)));
			}else printf("0");
			printf("\n");
			continue;
		}
		if (del > 0){
			if (del / ssqrt(del) / ssqrt(del) != 1){
				if (b != 0){
					if (a * b > 0)
						printf("-");
					printf("%d", abs(-b) / gcd(abs(b), abs(2*a)));
					if (abs(2*a) / gcd(abs(b), abs(2*a)) != 1)
					printf("/%d", abs(2*a) / gcd(abs(b), abs(2*a)));
				}
				
				if (b != 0){
					printf("+");
				}
			
				if (ssqrt(del) / gcd(abs(ssqrt(del)), abs(2*a)) != 1 && ssqrt(del) / gcd(abs(ssqrt(del)), abs(2*a)) != 0){
					printf("%d*", abs(ssqrt(del) / gcd(abs(ssqrt(del)), abs(2*a))));
				}
				if (del / ((int)ssqrt(del) * (int)ssqrt(del)) != 1){
					printf("sqrt(%d)", abs(del / (int)ssqrt(del) / (int)ssqrt(del)) );
				}
				if (abs((2*a) / gcd(abs(ssqrt(del)), abs(2*a))) != 1){
					printf("/%d", abs((2*a) / gcd(abs(ssqrt(del)), abs(2*a))));
				}
			}
			else {
				int k = 0;
				if (a > 0)
					k = -b + ssqrt(del);
				else 
					k = -b - ssqrt(del);
				b = k;
				if (b != 0){
					if (a * b < 0)
						printf("-");
					printf("%d", abs(b) / gcd(abs(b), abs(2*a)));
					if (abs(2*a) / gcd(abs(b), abs(2*a)) != 1)
					printf("/%d", abs(2*a) / gcd(abs(b), abs(2*a)));
				}
				else {
					printf("0");
				}
			}
			
			printf("\n");
			continue;
		}
	}
	
	return 0;
}