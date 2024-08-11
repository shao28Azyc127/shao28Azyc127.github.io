#include <algorithm>
#include <cstdio>
#include <string>
#define ProblemName "dict"
#define INFILE ProblemName ".in"
#define OUTFILE ProblemName ".out"
using namespace std;
template<typename T> inline T ReadInt(){
	bool sgn = false;
	T ans = 0;
	char ch = getchar();
	while((ch < '0' || '9' < ch) && ch != '-')
		ch = getchar();
	if(ch == '-'){
		sgn = true;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		ans = (ans << 3) + (ans << 1) + (ch ^ 48);
		ch = getchar();
	}
	return ans * (sgn?-1:1);
}
template<typename T> inline void WriteInt(T x){
	if(x < 0) putchar('-'),x = -x;
	if(x >= 10) WriteInt(x / 10);
	putchar('0' + x % 10);
}
inline void ReadString(string &str,bool ClearStr = false){
	if(ClearStr) str = "";
	char ch = getchar();
	while(ch == ' ' || ch == '\n' || ch == '\r' || 
	      ch == '\t' || ch == '\v' || ch == '\f') ch = getchar();
	while(ch != ' ' && ch != '\n' && ch != '\r' && 
	      ch != '\t' && ch != '\v' && ch != '\f')
		str += ch,ch = getchar();
}
inline void WriteString(const string &str){
	for(int i = 0;i < str.size();i ++)
		putchar(str[i]);
}
string s[6010];
bool dir[6010];
bool ans[6010];
int id[6010];
inline bool cmp(int x,int y){
	return s[x] < s[y];
}
int main(){
	freopen(INFILE,"r",stdin);
	freopen(OUTFILE,"w",stdout);
	int n = ReadInt<int>();
	int m = ReadInt<int>();
	for(int i = 1;i <= n;i ++){
		ReadString(s[i * 2 - 1],true);
		s[i * 2] = s[i * 2 - 1],dir[i * 2] = true;
		id[i * 2 - 1] = i * 2 - 1,id[i * 2] = i * 2;
		sort(s[i * 2 - 1].begin(),s[i * 2 - 1].end());
		sort(s[i * 2].begin(),s[i * 2].end(),greater<char>());
	}
	stable_sort(id + 1,id + n * 2 + 1,cmp);
	for(int i = 1;i <= n * 2;i ++){
		if(dir[id[i]]) break;
		ans[(id[i] + 1) / 2] = true;
	}
	for(int i = 1;i <= n;i ++)
		WriteInt(ans[i]);
	return 0;
}
