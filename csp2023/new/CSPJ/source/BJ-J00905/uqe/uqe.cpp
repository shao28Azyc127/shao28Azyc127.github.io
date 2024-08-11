#include <cstdio>
#define int long long
#define PROBLEMNAME "uqe"
#define FILEIN PROBLEMNAME ".in"
#define FILEOUT PROBLEMNAME ".out"
using namespace std;
template<typename T> inline T ReadInt(){
	char ch = getchar();
	bool sgn = false;
	while((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if(ch == '-') sgn = true,ch = getchar();
	T ans = 0;
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
template<typename T> inline T min(T a,T b){
	return a < b?a:b;
}
template<typename T> inline T max(T a,T b){
	return a > b?a:b;
}
template<typename T> inline T abs(T x){
	return max(x,-x);
}
template<typename T> inline T GCD(T x,T y){
	if(y == 0) return x;
	else return GCD(y,x % y);
}
inline void OutputRatio(int x,int y){
	if(x < 0 && y < 0) x *= -1,y *= -1;
	if(x == 0){
		putchar('0');
		return;
	}
	int G = GCD(abs(x),abs(y));
	WriteInt(x / G);
	if(y != G){
		putchar('/');
		WriteInt(y / G);
	}
}
signed main(){
	freopen(FILEIN,"r",stdin);
	freopen(FILEOUT,"w",stdout);
	int T,M,a,b,c;
	T = ReadInt<int>();
	M = ReadInt<int>();
	while(T --){
		a = ReadInt<int>();
		b = ReadInt<int>();
		c = ReadInt<int>();
		int x = -b,z = 2 * a,w = 1;
		int y = b * b - 4 * a * c;
		if(y < 0){
			putchar('N'),putchar('O'),putchar('\n');
			continue;
		}
		for(int i = 2;i * i <= y;i ++)
			while(y % (i * i) == 0)
				y /= i * i,w *= i;
		if(z < 0) x *= -1,z *= -1;
		if(y == 1){
			OutputRatio(x + w,z),putchar('\n');
			continue;
		}
		if(x) OutputRatio(x,z);
		if(y){
			if(x) putchar('+');
			int g = GCD(w,z);w /= g,z /= g;
			if(w > 1) WriteInt(w),putchar('*');
			putchar('s'),putchar('q'),putchar('r'),putchar('t'),putchar('(');
			WriteInt(y),putchar(')');
			if(z > 1) putchar('/'),WriteInt(z);
		}
		if(!x && !y) putchar('0');
		putchar('\n');
	}
	return 0;
}