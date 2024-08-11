#include <cstring>
#include <cstdio>
#include <list>
#define PROBLEMNAME "game"
#define INFILE PROBLEMNAME ".in"
#define OUTFILE PROBLEMNAME ".out"
using namespace std;
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
char a[2000010];
char b[2000010];
char c[2000010];
char s[2000010];
inline bool solve(int n){
	bool flg = false;
	while(n){
		if(flg) return false;
		else flg = true;
		int m = 0;
		for(int i = 1;i <= n;i ++){
			if(i < n && c[i] == c[i + 1])
				i ++,flg = false;
			else s[++ m] = c[i];
		}
		for(int i = (n = m,1);i <= n;i ++)
			c[i] = s[i];
	}
	return true;
}
int main(){
	freopen(INFILE,"r",stdin);
	freopen(OUTFILE,"w",stdout);
	int n = ReadInt<int>(),cnt = 0;
	char ch;
	while(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r');
		ch = getchar();
	for(int i = 1;i <= n;i ++)
		a[i] = ch,ch = getchar();
	for(int l = 1;l <= n;l ++){
		for(int r = l;r <= n;r ++){
			b[r - l + 1] = a[r];
			memcpy(c,b,sizeof(b));
			cnt += solve(r - l + 1);
		}
	}
	WriteInt(cnt);
	return 0;
}
