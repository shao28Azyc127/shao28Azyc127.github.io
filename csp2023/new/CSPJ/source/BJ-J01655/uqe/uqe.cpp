#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
void gcd(int a, int b){
	for(int i = 2; i <= min(abs(a), b); i++){
		while(abs(a) % i == 0 && b % i == 0){
			a /= i, b /= i;
		}
	}
	if(b == 1) printf("%d", a);
	else printf("%d/%d", a, b);
	return;
}
int main(){
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int t, m;
	int a, b, c, delta, max1, temp;
	scanf("%d%d", &t, &m);
	for(int i = 1; i <= t; i++){
		scanf("%d%d%d", &a, &b, &c);
		if(a < 0){
			a = -a, b = -b, c = -c;
		}
		delta = b * b - 4 * a * c;
		if(delta < 0){
			printf("NO\n");
			continue;
		}
		if(int(sqrt(delta)) * int(sqrt(delta)) == delta){
			max1 = -b + (int)sqrt(delta);
			if(max1 == 0) printf("0");
			else gcd(max1, 2 * a);
			printf("\n");
		}
		else{
			if(b == 0);
			else if(b % (2 * a) == 0) printf("%d+", -b / (2 * a));
			else{
				gcd(-b, 2 * a), printf("+");
			}
			temp = 1;
			for(int i = 2; i * i <= delta; i++){
				while(delta % (i * i) == 0){
					delta /= (i * i), temp *= i;
				}
			}
			a *= 2;
			if(temp != 1){
				for(int i = 2; i <= min(temp, a); i++){
					while(temp % i == 0 && a % i == 0){
						temp /= i, a /= i;
					}
				}
				if(temp != 1) printf("%d*", temp);
			}
			printf("sqrt(%d)", delta);
			if(a != 1){
				printf("/%d", a);
			}
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}