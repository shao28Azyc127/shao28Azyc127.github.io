#include <cstdio>
#define PROBLEMNAME "apple"
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
	if(x >= 10) WriteInt(x / 10);
	putchar('0' + x % 10);
}
int main(){
	freopen(FILEIN,"r",stdin);
	freopen(FILEOUT,"w",stdout);
	int n = ReadInt<int>();
	int ans1 = 0,ans2 = -1;
	while(n){
		if(n % 3 == 1 && ans2 == -1)
			ans2 = ans1 + 1;
		n -= (n - 1) / 3 + 1,ans1 ++;
	}
	WriteInt(ans1),putchar(' '),WriteInt(ans2);
	return 0;
}
