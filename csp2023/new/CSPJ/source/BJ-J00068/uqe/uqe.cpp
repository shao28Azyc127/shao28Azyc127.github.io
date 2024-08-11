#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll N = 5E3 + 10;
const ll M2 = 2E6;

ll sqr[M2];
ll rem[M2];

ll t, m;
ll a, b, c;
ll gcd[N][N];

void swap(ll &a, ll &b){
	ll c = a;
	a = b;
	b = c;
}

ll cgcd(ll a, ll b){
    if(b > a) swap(a, b);
    if(b == 1) return 1;
    if(b == 0) return a;
    // if(gcd[a][b]) return gcd[a][b];
    return cgcd(a % b, b);
}

int main(){
    freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);

    scanf("%lld%lld", &t, &m);
	const ll M = 5 * m * m + 10;
	for(ll i = 1; i * i <= M; i++){
		for(ll j = 1; j * i * i <= M; j++){
            sqr[j * i * i] = i;
            rem[j * i * i] = j;
		}
    }
    while(t--){
        scanf("%lld%lld%lld", &a, &b, &c);
		// cout << cgcd(a, b);
        // cout << sqr[a] << "*sqrt( " << rem[a] << ")" << endl;
		ll z1, m1, z2, m2, det;
		det = b * b - 4 * a * c;
		if(det < 0){
			printf("NO\n");
			continue;
		}
		z1 = -b;
		m1 = 2 * a;
		z2 = sqr[det];
		m2 = 2 * a;
		if(rem[det] == 1){
			z1 += z2;
			z2 = 0;
		}
		ll g1, g2;
		g1 = cgcd(abs(z1), abs(m1));
		z1 /= g1;
		m1 /= g1;
		g2 = cgcd(abs(z2), abs(m2));
		z2 /= g2;
		m2 /= g2;
		if(m1 < 0) {
			z1 = -z1;
			m1 = -m1;
		}
		if(m2 < 0) m2 = -m2;

		if(z1 != 0){
			printf("%lld", z1);
			if(m1 != 1)
				printf("/%lld", m1);
			if(z2 != 0) printf("+");
		}
		if(z2 != 0){
			if(z2 != 1) printf("%lld*", z2);
			printf("sqrt(%lld)", rem[det]);
			if(m2 != 1) printf("/%lld", m2);
		}
		if(z1 == 0 && z2 == 0) printf("0");
		printf("\n");
    }


	fclose(stdin);
	fclose(stdout);

    return 0;
}
