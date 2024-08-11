#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, m;
ll a, b, c, dt, g1, g2;
ll fj(ll num){
	ll res = 1;
	ll ghn = sqrt(num);
	for(int i=2; i<=ghn; ++i){
		int cnt = 0;
		while(num && num%i==0){
			++cnt;
			num /= i;
		}
		cnt /= 2;
		for(int j=1; j<=cnt; ++j){
			res *= i;
		}
		if(num==0) return res;
	}
	return res;
}
int main(){
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin>>t>>m;
	while(t--){
		scanf("%lld%lld%lld", &a, &b, &c);
		dt = b * b - 4 * a * c;
		if(dt<0){
			printf("NO\n");
			continue;
		}
		int gdt = sqrt(dt);
		if(gdt*gdt==dt){
			if(a>0){
				ll fz = gdt - b;
				ll fm = 2 * a;
				if(fz==0){
					printf("0\n");
					continue;
				}
				ll d = __gcd(fz, fm);
				if(d<0) d = -d;
				fz /= d;
				fm /= d;
				if(fm==1){
					printf("%lld\n", fz);
					continue;
				}else{
					printf("%lld", fz);
					putchar('/');
					printf("%lld\n", fm);
				}
			}else{
				ll fz = -gdt - b;
				ll fm = 2 * a;
				if(fz==0){
					printf("0\n");
					continue;
				}
				fz = -fz;
				fm = -fm;
				ll d = __gcd(fz, fm);
				if(d<0) d = -d;
				fz /= d;
				fm /= d;
				if(fm==1){
					printf("%lld\n", fz);
					continue;
				}else{
					printf("%lld", fz);
					putchar('/');
					printf("%lld\n", fm);
				}
			}
		}else{
			if(a>0){
				ll fz1 = -b;
				ll fm1 = 2 * a;
				if(fz1!=0){
					ll d1 = __gcd(fz1, fm1);
					if(d1<0) d1 = -d1;
					fz1 /= d1;
					fm1 /= d1;
					if(fm1==1){
						printf("%lld", fz1);
					}else{
						printf("%lld", fz1);
						putchar('/');
						printf("%lld", fm1);
					}
					putchar('+');
				}
				ll fzx = fj(dt);
				ll fzf = dt / fzx / fzx;
				ll fm2 = 2 * a;
				ll d2 = __gcd(fzx, fm2);
				if(d2<0) d2 = -d2;
				fzx /= d2;
				fm2 /= d2;
				if(fzx!=1){
					printf("%lld", fzx);
					putchar('*');
				}
				printf("sqrt(%lld)", fzf);
				if(fm2!=1){
					putchar('/');
					printf("%lld", fm2);
				}
				putchar('\n');
			}else{
				ll fz1 = b;
				ll fm1 = -2 * a;
				if(fz1!=0){
					ll d1 = __gcd(fz1, fm1);
					if(d1<0) d1 = -d1;
					fz1 /= d1;
					fm1 /= d1;
					if(fm1==1){
						printf("%lld", fz1);
					}else{
						printf("%lld", fz1);
						putchar('/');
						printf("%lld", fm1);
					}
					putchar('+');
				}
				ll fzx = fj(dt);
				ll fzf = dt / fzx / fzx;
				ll fm2 = -2 * a;
				ll d2 = __gcd(fzx, fm2);
				if(d2<0) d2 = -d2;
				fzx /= d2;
				fm2 /= d2;
				if(fzx!=1){
					printf("%lld", fzx);
					putchar('*');
				}
				printf("sqrt(%lld)", fzf);
				if(fm2!=1){
					putchar('/');
					printf("%lld", fm2);
				}
				putchar('\n');
			}
		}
	}
	return 0;
}
