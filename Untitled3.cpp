#include<bits/stdc++.h>
using namespace std;
const int bse = 1e7;
struct haa {
	ll a[105];
	int len;
	haa() {
		len = 1, memset(a,0,sizeof(a));
	}
	haa(int x) {
		memset(a,0,sizeof(a));
		len = 1;
		while(x) {
			a[len++] = x % bse,x /= bse;
		}
		len --;
	}
	void print() {
		printf("%lld",a[len]);
		for (int i = len-1 ; i ; i --)printf("%07lld",a[i]);
	}
}
;
haa operator + (haa& a,haa& b) {
	haa ret = 0;
	ret.len = max(a.len,b.len) + 1;
	for (int i = 1 ; i <= ret.len ; i ++)
			ret.a[i] += a.a[i] + b.a[i],
			ret.a[i+1] += ret.a[i] / bse,
			ret.a[i] %= bse;
	for (int i = 1 ; i <= ret.len ; i ++)
			ret.a[i+1] += ret.a[i] / bse,
			ret.a[i] %= bse;
	while(ret.len > 1 && !ret.a[ret.len]) ret.len --;
	return ret;
}
haa operator * (haa& a,haa& b) {
	haa ret = 0;
	ret.len = a.len + b.len + 1;
	for (int i = 1 ; i <= a.len ; i ++)
			for (int j = 1 ; j <= b.len ; j ++)
				ret.a[i+j-1] += a.a[i] * b.a[j],
				ret.a[i+j] += ret.a[i+j-1] / bse,
				ret.a[i+j-1] %= bse;
	for (int i = 1 ; i <= ret.len ; i ++)
			ret.a[i+1] += ret.a[i] / bse ,
			ret.a[i] %= bse;
	while(ret.len > 1 && !ret.a[ret.len]) ret.len --;
	return ret;
}
haa operator * (haa& a,int b) {
	haa ret = 0 ;
	ret.len = a.len;
	int x = b;
	while(x) ret.len ++ , x /= bse;
	for (int i = 1 ; i <= a.len ; i ++)
			ret.a[i] += a.a[i] * b,
			ret.a[i+1] += ret.a[i] / bse,
			ret.a[i] %= bse;
	for (int i = 1 ; i <= ret.len ; i ++)
			ret.a[i+1] += ret.a[i] / bse,
			ret.a[i] %= bse;
	while(ret.len > 1 && !ret.a[ret.len]) ret.len --;
	return ret;
}
inline void operator += (haa& a,haa& b) {
	a = a+b;
}
inline void operator *= (haa& a,int b) {
	a = a*b;
}
inline void operator *= (haa& a,haa& b) {
	a = a*b;
}
bool operator < (const haa& a,const haa& b) {
	if(a.len != b.len) return a.len < b.len;
	for (int i = a.len ; i ; i --)
			if(a.a[i] != b.a[i]) return a.a[i] < b.a[i];
	return 0;
}
bool operator == (const haa& a,const haa& b) {
	if(a.len != b.len) return 0;
	for (int i = a.len ; i ; i --)
			if(a.a[i] != b.a[i]) return 0;
	return 1;
}
bool operator > (const haa& a,const haa& b) {
	return !(a<b) && !(a == b);
}
int main() {
}
