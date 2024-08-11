/*flower*/
#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
constexpr int mod = 998244353;
int fpw(int a, int b) {
	int ans = 1;
	for(; b; b >>= 1, a = 1ll * a * a % mod) if(b & 1) {
		ans = 1ll * ans * a % mod;
	}
	return ans;
}
struct matrix {
	int a[2][2];
	int * operator [](int x) {return a[x];}
	friend matrix operator * (matrix a, matrix b) {
		matrix z;
		z[0][0] = (1ll * a[0][0] * b[0][0] + 1ll * a[0][1] * b[1][0]) % mod;
		z[0][1] = (1ll * a[0][0] * b[0][1] + 1ll * a[0][1] * b[1][1]) % mod;
		z[1][0] = (1ll * a[1][0] * b[0][0] + 1ll * a[1][1] * b[1][0]) % mod;
		z[1][1] = (1ll * a[1][0] * b[0][1] + 1ll * a[1][1] * b[1][1]) % mod;
		return z;
	}
	matrix() {
		a[0][0] = a[1][1] = 1;
		a[1][0] = a[0][1] = 0;
	}
	matrix inv() {
		matrix a = *this, inv;
		inv[0][0] = inv[1][1] = 1;
		inv[0][1] = inv[1][0] = 0;
		auto o1 = [&] (int x, int y, int c) {
			for(int i = 0; i < 2; i ++) {
				a[y][i] = (a[y][i] + 1ll * a[x][i] * c) % mod;
			}
			for(int i = 0; i < 2; i ++) {
				inv[y][i] = (inv[y][i] + 1ll * inv[x][i] * c) % mod;
			}
		};
		o1(0, 1, mod - 1ll * a[1][0] * fpw(a[0][0], mod - 2) % mod);
		o1(1, 0, mod - 1ll * a[0][1] * fpw(a[1][1], mod - 2) % mod);	
		auto o2 = [&] (int x, int c) {
			for(int i = 0; i < 2; i ++) {
				inv[x][i] = 1ll * inv[x][i] * c % mod;
			}
		};
		o2(0, fpw(a[0][0], mod - 2));
		o2(1, fpw(a[1][1], mod - 2));
		return inv;
	}
	friend bool operator == (matrix a, matrix b){
		return a[0][0] == b[0][0] && a[0][1] == b[0][1] && a[1][0] == b[1][0] && a[1][1] == b[1][1];
	}
	void debug() {
		std::cout << "(" << a[0][0] << ' ' << a[0][1] << ' '<< a[1][0] << ' '<< a[1][1] << ")\n";
	}
}; 
struct my_hash {
	u64 operator () (matrix a) const {
		return (a[0][0]) ^ (u64(a[0][1]) << 16) ^ (u64((a[1][0])) << 32) ^ (u64((a[1][1])) << 48);
	}
};
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	int n;
	std::string str;
	std::cin >> n >> str;
	std::vector<matrix> base(26), invbase(26);
	std::mt19937 hua(20060411);
	for(int i = 0; i < 26; i ++) {
		for(int j : {0, 1}) for(int k : {0, 1}) {
			base[i][j][k] = hua() % mod;
		}
		invbase[i] = base[i].inv();
	}
	matrix mul;
	std::unordered_map<matrix, int, my_hash> map;
	map.reserve(n);
	i64 ans = 0;
	map[mul] ++;
	for(int i = 0; i < n; i ++) {
		int c = str[i] - 'a';
		if(i & 1) mul = mul * base[c];
		else mul = mul * invbase[c];
		ans += map[mul];
		map[mul] ++;
	}
	std::cout << ans << '\n';
	return 0;
}