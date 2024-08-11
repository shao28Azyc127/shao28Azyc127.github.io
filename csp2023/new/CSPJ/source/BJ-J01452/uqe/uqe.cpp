#include <bits/stdc++.h>
using namespace std;
long long T, M, okornot[100005], cnt = 0, primes[100005];
long long gcd(long long a, long long b){
		if (b == 0){
			return a;
		}
		return gcd(b, a % b);
}
int main(){
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	scanf("%lld%lld", &T, &M);
	okornot[1] = 1;
	for (long long i = 2; i <= 100000; i++){
		if (!okornot[i]){
				for (long long j = i + i; j <= 100000; j += i){
						okornot[j] = 0;
				}
		}
	}
	for (long long i = 1; i <= 100000; i++){
			if (!okornot[i]){
					primes[++cnt] = i;
			}
	}
	while (T--){
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		long long deta = b * b - 4 * a * c;
		if (deta < 0){
			printf("NO\n");
		}else if (deta == 0){
			long long fenzi = -b;
			long long fenmu = 2 * a;
			if (fenmu < 0){
				fenzi = -fenzi;
				fenmu = -fenmu;
			}
			long long s1 = abs(fenzi), s2 = abs(fenmu);
			long long gcds = gcd(s1, s2);
			fenzi /= gcds;
			fenmu /= gcds;
			if (fenzi == 0){
				printf("%lld\n", 0ll);
			}else if (fenmu == 1){
				printf("%lld\n", fenzi);
			}else{
				printf("%lld/%lld\n", fenzi, fenmu);
			}
		}else{
			long long s = sqrt(deta);
			bool book = false;
			if (2 * a < 0){
				book = true;
			}
			if (s * s == deta){ // ok
				long long fenzi = -b;
				if (book){
					fenzi -= s;
				}else{
					fenzi += s;
				}
				long long fenmu = 2 * a;
				if (fenmu < 0){
					fenzi = -fenzi;
					fenmu = -fenmu;
				}
				long long s1 = abs(fenzi), s2 = abs(fenmu);
				long long gcds = gcd(s1, s2);
				fenzi /= gcds;
				fenmu /= gcds;
				if (fenzi == 0){
					printf("%lld\n", 0ll);
				}else if (fenmu == 1){
					printf("%lld\n", fenzi);
				}else{
					printf("%lld/%lld\n", fenzi, fenmu);
				}
			}else{
				long long huajian = deta, lft = 1;
				for (long long i = 1; i <= cnt && primes[i] * primes[i] <= huajian; i++){
					long long cnt1 = 0, tot = 1;
					while (huajian % primes[i] == 0){
						huajian /= primes[i];
						tot *= primes[i];
						cnt1++;
					}
					if (cnt1 % 2 == 1){
						tot /= primes[i];
					}
					if (cnt1 >= 2){
						lft *= tot;
					}
					if (cnt1 == 1){
						huajian *= primes[i];
					}else if (cnt1 % 2 == 1){
						huajian *= primes[i];
					}
				}
				lft = sqrt(lft);
				long long fenmu1 = 2 * a, fenzi1 = -b;
				if (fenmu1 < 0){
					fenmu1 = -fenmu1;
					fenzi1 = -fenzi1;
				}
				long long fenmu2 = abs(fenmu1), fenzi2 = abs(fenzi1);
				long long sq = gcd(fenmu2, fenzi2);
				fenmu1 /= sq;
				fenzi1 /= sq;
				bool flg1 = false;
				if (fenzi1 != 0){
					if (fenmu1 == 1){
						printf("%lld", fenzi1);
					}else if (fenmu2 != 0){
						printf("%lld/%lld", fenzi1, fenmu1);
					}
					flg1 = true;
				}
				long long fenzi3 = lft, fenmu3 = 2 * a;
				if (book){
					fenzi3 = -fenzi3;
				}
				if (fenmu3 < 0){
					fenzi3 = -fenzi3;
					fenmu3 = -fenmu3;
				}
				long long fenmu4 = abs(fenmu3), fenzi4 = abs(fenzi3);
				long long sq2 = gcd(fenmu4, fenzi4);
				fenmu3 /= sq2;
				fenzi3 /= sq2;
				if (fenmu3 == 1 && fenzi3 == 1){
					if (fenzi3 > 0 && flg1){
						printf("+");
					}
					printf("sqrt(%lld)\n", huajian);
				}else if (fenmu3 == 1){
					if (fenzi3 == 1){
						if (fenzi3 > 0 && flg1){
							printf("+");
						}
						printf("sqrt(%lld)\n", huajian);
					}else{
						if (fenzi3 > 0 && flg1){
							printf("+");
						}
						printf("%lld*sqrt(%lld)\n", fenzi3, huajian); 
					}
				}else{
					if (fenzi3 == 1){
						if (fenzi3 > 0 && flg1){
							printf("+");
						}
						printf("sqrt(%lld)/%lld\n", huajian, fenmu3);
					}else{
						if (fenzi3 > 0 && flg1){
							printf("+");
						}
						printf("%lld*sqrt(%lld)/%lld\n", fenzi3, huajian, fenmu3);
					}
				}
				// 5 * 10^3 * 10^3 * 10
			}
		}
	}
	return 0;
}

// 
