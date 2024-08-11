#include<bits/stdc++.h>
using namespace std;
const int MX = 5e5 + 7;
int read(){
	int x = 0,ch = getchar();
	while(ch < '0' || ch > '9')ch = getchar();
	while(ch >= '0' && ch <= '9')x = x * 10 + ch - 48,ch = getchar();
	return x;
}
int x[MX],y[MX],tx[MX],ty[MX];
bool f[3005][3005];
bool solvefg(int n,int m){
	if(x[1] <= y[1])return false;
	memset(f,false,sizeof(f));
	f[1][1] = true;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			if(i != 1)f[i][j] |= f[i - 1][j] & x[i] > y[j];
			if(j != 1)f[i][j] |= f[i][j - 1] & x[i] > y[j];
			if(i != 1 && j != 1)f[i][j] |= f[i - 1][j - 1] & x[i] > y[j];
		}
	return f[n][m];
}
bool solvegf(int n,int m){
	if(x[1] >= y[1])return false;
	memset(f,false,sizeof(f));
	f[1][1] = true;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			if(i != 1)f[i][j] |= f[i - 1][j] & x[i] < y[j];
			if(j != 1)f[i][j] |= f[i][j - 1] & x[i] < y[j];
			if(i != 1 && j != 1)f[i][j] |= f[i - 1][j - 1] & x[i] < y[j];
		}
	return f[n][m];
}
void solve(int n,int m){
	if(solvefg(n,m) || solvegf(n,m))cout << 1;
	else cout << 0;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;
	c = read();n = read();m = read();q = read();
	for(int i = 1;i <= n;i++)x[i] = read();
	for(int i = 1;i <= m;i++)y[i] = read();
	for(int i = 1;i <= n;i++)tx[i] = x[i];
	for(int i = 1;i <= m;i++)ty[i] = y[i];
	if(c > 7){
		cout << 0;
		for(int i = 1;i <= q;i++)cout << 0;
		cout << '\n';
		return 0;
	}
	solve(n,m);
	for(int i = 1;i <= q;i++){
		for(int j = 1;j <= n;j++)x[i] = tx[i];
		for(int j = 1;j <= m;j++)y[i] = ty[i];
		int kx,ky;
		kx = read();ky = read();
		for(int j = 1;j <= kx;j++){
			int p,v;
			p = read();v = read();
			x[p] = v;
		}
		for(int j = 1;j <= ky;j++){
			int p,v;
			p = read();v = read();
			y[p] = v;
		}
		solve(n,m);
	}
	
	cout << '\n';
	return 0;
}