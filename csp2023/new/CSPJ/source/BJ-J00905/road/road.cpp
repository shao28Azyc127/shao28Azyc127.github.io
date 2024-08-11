#include <cstdio>
#define PROBLEMNAME "road"
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
int dis[100010],a[100010];
int main(){
	freopen(FILEIN,"r",stdin);
	freopen(FILEOUT,"w",stdout);
	int n = ReadInt<int>(),d = ReadInt<int>();
	for(int i = 2;i <= n;i ++)
		dis[i] = dis[i - 1] + ReadInt<int>();
	for(int i = 1;i <= n;i ++)
		a[i] = ReadInt<int>();
	int remdis = 0,ans = 0;
	for(int i = 1,j = i;i < n;i = j){
		while(j < n && a[j] >= a[i]) j ++;
		int reqdis = dis[j] - dis[i] - remdis;
		int reqfuel = reqdis / d + bool(reqdis % d);
		remdis += reqfuel * d - dis[j] + dis[i];
		ans += reqfuel * a[i];
	}
	WriteInt(ans);
	return 0;
}
