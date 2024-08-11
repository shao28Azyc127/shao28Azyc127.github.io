#include <iostream>

using namespace std;

typedef long long ll;
const int N = 110;
ll n, cnt, num;

struct Node{
	ll k, a, siz;
	string nam, t[N], n[N];
	ll o[N];
}f[N];

struct Yuansu{
	string t, nam;
	ll st, T, siz;
}Y[N];

void Init(){
	f[++cnt].k = 0;
	f[cnt].a = 1;
	f[cnt].siz = 1;
	f[cnt].nam = "byte";
	f[++cnt].k = 0;
	f[cnt].a = 2;
	f[cnt].siz = 2;
	f[cnt].nam = "short";
	f[++cnt].k = 0;
	f[cnt].a = 4;
	f[cnt].siz = 4;
	f[cnt].nam = "int";
	f[++cnt].k = 0;
	f[cnt].a = 8;
	f[cnt].siz = 8;
	f[cnt].nam = "long";
}

ll Find(string tmp, ll x, int T){
	string now = "";
	if(T <= 4){
		return 0;
	}
	for(int i = x; i < tmp.size(); ++i){
		if(tmp[i] != '.'){
			now += tmp[i];
		}else{
			for(int j = 1; j <= f[T].k; ++j){
				if(now == f[T].n[j]){
					for(int k = 1; k <= cnt; ++k){
						if(f[k].nam == f[T].t[j]){
							return f[T].o[j] + Find(tmp, i + 1, k);
						}
					}
				}
			}
		}
	}
	for(int j = 1; j <= f[T].k; ++j){
		if(now == f[T].n[j]){
			for(int k = 1; k <= cnt; ++k){
				if(f[k].nam == f[T].t[j]){
					return f[T].o[j];
				}
			}
		}
	}
	return 0;
}

bool Check(ll addr, ll T, string &ans){
	if(T <= 4){
		if(addr < f[T].siz){
			return true;
		}else{
			return false;
		}
	}
	for(int i = 1; i < f[T].k; ++i){
		if(addr >= f[T].o[i] && addr < f[T].o[i + 1]){
			ll tmp;
			for(int j = 1; j <= cnt; ++j){
				if(f[j].nam == f[T].t[i]){
					tmp = j;
					break;
				}
			}
			if(tmp <= 4){
				ans += f[T].n[i];
			}else{
				ans += f[T].n[i] + ".";
			}
			return Check(addr - f[T].o[i], tmp, ans);
		}
	}
	ll tmp;
	for(int j = 1; j <= cnt; ++j){
		if(f[j].nam == f[T].t[f[T].k]){
			tmp = j;
			break;
		}
	}
	if(tmp <= 4){
		ans += f[T].n[f[T].k];
	}else{
		ans += f[T].n[f[T].k] + ".";
	}
	return Check(addr - f[T].o[f[T].k], tmp, ans);
}

int main(){
	ios::sync_with_stdio(false);
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	Init();
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int op;
		cin >> op;
		if(op == 1){
			cnt++;
			cin >> f[cnt].nam >> f[cnt].k;
			ll last = 0;
			for(int j = 1; j <= f[cnt].k; ++j){
				cin >> f[cnt].t[j] >> f[cnt].n[j];
				for(int k = 1; k < cnt; ++k){
					if(f[k].nam == f[cnt].t[j]){
						if(j == 1){
							f[cnt].a = f[k].a;
							f[cnt].o[j] = 0;
							last += f[k].siz;
						}else{
							f[cnt].a = max(f[cnt].a, f[k].a);
							if(last % f[k].a == 0){
								f[cnt].o[j] = last;
								last += f[k].siz;
							}else{
								f[cnt].o[j] = (last / f[k].a + 1) * f[k].a;
								last = f[cnt].o[j] + f[k].siz;
							}
						}
						break;
					}
				}
			}
			if(last % f[cnt].a == 0){
				f[cnt].siz = last;
			}else{
				f[cnt].siz = (last / f[cnt].a + 1) * f[cnt].a;
			}
			cout << f[cnt].siz << " " << f[cnt].a << endl;
		}else if(op == 2){
			num++;
			cin >> Y[num].t >> Y[num].nam;
			for(int j = 1; j <= cnt; ++j){
				if(f[j].nam == Y[num].t){
					Y[num].T = j;
					Y[num].siz = f[j].siz;
					if(num == 1){
						Y[num].st = 0;
					}else{
						if((Y[num - 1].st + Y[num - 1].siz) % f[j].a == 0){
							Y[num].st = Y[num - 1].st + Y[num - 1].siz;
						}else{
							Y[num].st = ((Y[num - 1].st + Y[num - 1].siz) / f[j].a + 1) * f[j].a;
						}
					}
					break;
				}
			}
			cout << Y[num].st << endl;
		}else if(op == 3){
			string tmp, nam = "";
			cin >> tmp;
			for(int j = 0; j < tmp.size(); ++j){
				if(tmp[j] != '.'){
					nam += tmp[j];
				}else{
					for(int k = 1; k <= num; ++k){
						if(Y[k].nam == nam){
							cout << Y[k].st + Find(tmp, j + 1, Y[k].T) << endl;
						}
					}
					break;
				}
			}
		}else{
			ll addr, op = 0;
			cin >> addr;
			for(int j = 1; j < num; ++j){
				if(Y[j].st <= addr && Y[j + 1].st > addr){
					string ans = Y[j].nam + ".";
					if(Check(addr - Y[j].st, Y[j].T, ans)){
						cout << ans << endl;
					}else{
						cout << "ERR" << endl;
					}
					op = 1;
				}
			}
			if(op == 0){
				string ans = Y[num].nam + ".";
				if(Check(addr - Y[num].st, Y[num].T, ans)){
					cout << ans << endl;
				}else{
					cout << "ERR" << endl;
				}
			}
		}
	}
	return 0;
}