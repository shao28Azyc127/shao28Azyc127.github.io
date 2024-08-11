#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#define PROBLEMNAME "lock"
#define INFILE PROBLEMNAME ".in"
#define OUTFILE PROBLEMNAME ".out"
using namespace std;
int bkt[100010];
template<typename T> inline T ReadInt(){
	char ch = getchar();
	bool sgn = false;
	T ans = 0;
	while((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if(ch == '-') ch = getchar(),sgn = true;
	while('0' <= ch && ch <= '9'){
		ans = (ans << 3) + (ans << 1) + (ch ^ 48);
		ch = getchar();
	}
	return ans * (sgn?-1:1);
}
template<typename T> inline void WriteInt(T x){
	if(x < 0) putchar('-'),x *= -1;
	if(x >= 10) WriteInt(x / 10);
	putchar('0' + x % 10);
}
inline int Mix(int a,int b,int c,int d,int e){
	return a * 10000 + b * 1000 + c * 100 + d * 10 + e;
}
inline int Scroll(int x,int pos,int ofst){
	int wgt = 1;
	for(int i = 0;i < pos;i ++)
		wgt *= 10;
	int v = x / wgt % 10;
	int nx = x - v * wgt;
	v = (v + ofst % 10 + 10) % 10;
	return nx + v * wgt;
}
inline void GetScrollPerm(int x,vector<int> &p,bool ClearVec = true){
	vector<int> tmp;
	for(int i = 0;i < 5;i ++)
		for(int j = -9;j < 9;j ++)
			if(j) tmp.push_back(Scroll(x,i,j));
	for(int i = 0;i < 4;i ++){
		for(int j = -9;j < 9;j ++){
			if(!j) continue;
			int nx = Scroll(x,i,j);
			tmp.push_back(Scroll(nx,i + 1,j));
		}
	}
	sort(tmp.begin(),tmp.end()),ClearVec && (p.clear(),0);
	for(int i = 0;i < tmp.size();i ++)
		if(p.empty() || p[p.size() - 1] != tmp[i])
			p.push_back(tmp[i]);
}
int main(){
	freopen(INFILE,"r",stdin);
	freopen(OUTFILE,"w",stdout);
	int a,b,c,d,e,x,cnt = 0,n = ReadInt<int>();
	vector<int> p;
	for(int i = 1;i <= n;i ++){
		a = ReadInt<int>();
		b = ReadInt<int>();
		c = ReadInt<int>();
		d = ReadInt<int>();
		e = ReadInt<int>();
		GetScrollPerm(Mix(a,b,c,d,e),p);
		for(int j : p) bkt[j] ++;
	}
	for(int i = 0;i <= 100000;i ++)
		if(bkt[i] == n) cnt ++;
	WriteInt(cnt);
	return 0;
}
