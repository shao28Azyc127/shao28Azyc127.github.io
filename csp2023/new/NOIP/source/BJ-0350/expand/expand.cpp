#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+3;
long long c, n, m, q;
long long x[maxn], y[maxn];
long long a[maxn], b[maxn];
long long kx, ky, cur1, cur2;
long long read(){
	long long p = 0, pn = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') pn = -1;
		ch = getchar();
	}
	while(ch <= '9' && ch >= '0'){
		p = (p << 3) + (p << 1) + ch - '0';
		ch = getchar();
	}
	return p * pn;
}
void change(){
	int z[maxn];
	memset(z, 0, sizeof(z));
	for(int i = 0; i <= n; i ++){
		z[i] = x[i];
	}
	memset(x, 0, sizeof(x));
	for(int i = 0; i <= m; i ++){
		x[i] = y[i];
	}
	memset(y, 0, sizeof(y));
	for(int i = 0; i <= n; i ++){
		y[i] = z[i];
	}
	return;
}
void hello(){
	for(int i = 0; i <= n; i ++)
		x[i] = a[i];
	for(int i = 0; i <= m; i ++)
		y[i] = b[i];
	return;
}
bool genshin(int lx, int ly){
	if(lx == n && ly == m){
		return x[n] > y[m];
	}
	if(ly == m){
		for(int i = lx; i <= n; i ++){
			if(x[i] <= y[ly]) return false;
		}
		return true;
	}
	if(lx == n){
		for(int i = ly; i <= m; i ++){
			if(x[lx] <= y[i]) return false;
		}
		return true;
	}
	if(x[lx] < y[ly]) return false;
	int alpha = lx;
	while(x[lx] > y[ly] && lx <= n){
		lx ++;
	}
	lx --;
	while(!genshin(lx, ly + 1)){
		lx --;
		if(alpha > lx){
			return false;
		}
	}
	return true;
}
	
void impact(){
	if(x[1] < y[1]){
		change();
	}
	if(x[1] == y[1]){
		printf("0");
		return;
	}
	if(genshin(1, 1)){
		printf("1");
	}
	else{
		printf("0");
	}
	return;
}
int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read();
	n = read();
	m = read();
	q = read();
	for(int i = 1; i <= n; i ++){
		a[i] = read();
	}
	for(int i = 1; i <= m; i ++){
		b[i] = read();
	}
	hello();
	impact();
	while(q--){
		hello();
		kx = read();
		ky = read();
		for(int i = 0; i < kx; i ++){
			cur1 = read();
			cur2 = read();
			x[cur1] = cur2;
		}
		for(int i = 0; i < ky; i ++){
			cur1 = read();
			cur2 = read();
			y[cur1] = cur2;
		}
		impact();
	}
	fcloseall();
	return 0;
}
