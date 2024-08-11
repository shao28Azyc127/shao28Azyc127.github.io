#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 5e5 + 5;
const int HN = 2005;

int C,n,m,Q;
int x[N],y[N],ox[N],oy[N];
int nxx[N],nxy[N];
int mxx,mix,mxy,miy;

void ckmax(int &xx,int yy){
	if(xx < yy) xx = yy;
}

void ckmin(int &xx,int yy){
	if(xx > yy) xx = yy;
}

bool solve(vector<int> a,vector<int> b){
	if(a.size() == 0 && b.size() == 0)
		return true;
	if(a.size() == 0 || b.size() == 0)
		return false;
	if(!(a[0] > b[0] && a[a.size()-1] > b[b.size()-1]))
		return false;
	vector<int> u(0),v(0);
	for(int i = 1;i < (int)a.size()-1;i++){
		if((a[i-1]<a[i]) && (a[i]>a[i+1]))
			u.push_back(a[i]);
		else if((a[i-1]>a[i]) && (a[i]<a[i+1]))
			u.push_back(a[i]);
	}
	for(int i = 1;i < (int)b.size()-1;i++){
		if((b[i-1]<b[i]) && (b[i]>b[i+1]))
			v.push_back(b[i]);
		else if((b[i-1]>b[i]) && (b[i]<b[i+1]))
			v.push_back(b[i]);
	}
	if(u.size() == 0 || v.size() == 0)
		return true;
	return solve(u,v);
}

bool f[HN][HN];

bool solve_DP(){
	if(!(x[1] > y[1] && x[n] > y[m]))
		return false;
	//~ cerr << "QAQ\n";
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= m;j++){
			f[i][j] = 0;
		}
	}
	f[1][1] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(f[i][j] == 1){
				if(x[i] > y[j+1])
					f[i][j+1] = true;
				if(x[i+1] > y[j])
					f[i+1][j] = true;
				if(x[i+1] > y[j+1])
					f[i+1][j+1] = true;
			}
		}
	}
	return f[n][m];
}

int sta[N];
int top;

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C >> n >> m >> Q;
	mxx = mxy = -1e9;
	mix = miy = 1e9;
	for(int i = 1;i <= n;i++){
		cin >> x[i];
		ox[i] = x[i];
	}
	for(int i = 1;i <= m;i++){
		cin >> y[i];
		oy[i] = y[i];
	}
	bool ck = false;
	if(x[1] < y[1]){
		for(int i = 1;i <= max(n,m);i++){
			swap(x[i],y[i]);
			swap(ox[i],oy[i]);
		}
		swap(n,m);
		ck ^= 1;
	}
	if(max(n,m) <= 2001){
			cout << solve_DP();
	} else {
		vector<int> a(0),b(0);
		for(int i = 1;i <= n;i++)
			a.push_back(x[i]);
		for(int i = 1;i <= m;i++)
			b.push_back(y[i]);
		cout << solve(a,b);
	}
	for(int tt = 1;tt <= Q;tt++){
		int kx,ky,idx,val;
		for(int i = 1;i <= n;i++){
			x[i] = ox[i];
		}
		for(int i = 1;i <= m;i++){
			y[i] = oy[i];
		}
		cin >> kx >> ky;
		for(int i = 1;i <= kx;i++){
			cin >> idx >> val;
			if(!ck){
				x[idx] = val;
			} else {
				y[idx] = val;
			}
		}
		for(int i = 1;i <= ky;i++){
			cin >> idx >> val;
			if(!ck){
				y[idx] = val;
			} else {
				x[idx] = val;
			}
		}
		if(x[1] < y[1]){
			for(int i = 1;i <= max(n,m);i++){
				swap(x[i],y[i]);
				swap(ox[i],oy[i]);
			}
			swap(n,m);
			ck ^= 1;
		}
		//~ for(int i = 1;i <= n;i++)
			//~ cerr << x[i] << " ";
		//~ cerr << "\n";
		//~ for(int i = 1;i <= m;i++)
			//~ cerr << y[i] << " ";
		//~ cerr << "\n";
		//~ cout << solve(1,n,1,m);
		if(max(n,m) <= 2001){
			cout << solve_DP();
		} else {
			vector<int> a(0),b(0);
			for(int i = 1;i <= n;i++)
				a.push_back(x[i]);
			for(int i = 1;i <= m;i++)
				b.push_back(y[i]);
			cout << solve(a,b);
		}
	}
	return 0;
}
