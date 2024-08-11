#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#define ProblemName "tribool"
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
struct Solution1{
	Solution1(){
		int n = ReadInt<int>();
		int m = ReadInt<int>();
		string o;
		for(int i = 1;i <= m;i ++){
			ReadString(o,true);
			if(o == "-" || o == "+"){
				op[i] = o == "+";
				x[i] = ReadInt<int>();
				y[i] = ReadInt<int>();
			}else{
				op[i] = (o == "U"?2:o == "T") + 2;
				x[i] = ReadInt<int>();
			}
		}
		int ans = n + 1,cnt = 1;
		for(int i = 1;i <= n;i ++) cnt *= 3;
		for(int i = 1;i <= cnt;i ++){
			int t = i,Ucnt = 0;
			for(int j = 1;j <= n;j ++)
				Ucnt += (d[j] = _d[j] = t % 3) == 2,t /= 3;
			Work(m);
			for(int j = 1;j <= n;j ++)
				if(d[j] != _d[j]) goto _label;
			ans = min(ans,Ucnt);
			_label:;
		}
		WriteInt(ans),putchar('\n');
	}
	inline int Rev(int x){return x == 2?2:!x;}
	inline void Work(int m){
		for(int i = 1;i <= m;i ++){
			if(op[i] == 0) d[x[i]] = Rev(d[y[i]]);
			else if(op[i] == 1) d[x[i]] = d[y[i]];
			else d[x[i]] = op[i] - 2;
		}
	}
	int op[11],x[11],y[11],d[11],_d[11];
};
struct Solution2{
	Solution2(){
		int n = ReadInt<int>();
		int m = ReadInt<int>();
		string o;
		for(int i = 1;i <= n;i ++)
			isU[i] = false;
		for(int i = 1;i <= m;i ++){
			ReadString(o,true);
			isU[ReadInt<int>()] = o == "U";
		}
		int ans = 0;
		for(int i = 1;i <= n;i ++)
			ans += isU[i];
		WriteInt(ans),putchar('\n');
	}
	bool isU[100010];
};
int sval[100010];
bool vis[100010];
int val[100010];
int main(){
	freopen(INFILE,"r",stdin);
	freopen(OUTFILE,"w",stdout);
	int c = ReadInt<int>();
	int T = ReadInt<int>();
	if(c <= 2)
		while(T --) Solution1();
	else if(c <= 4)
		while(T --) Solution2();
	else{
		int n,m,i,j,now,ans;
		vector<int> vec,rev;
		string op;
		while(T --){
			n = ReadInt<int>(),m = ReadInt<int>();
			for(int i = 1;i <= n;i ++)
				val[i] = i,vis[i] = false;
			while(m --){
				ReadString(op,true);
				if(op == "-"){
					i = ReadInt<int>(),j = ReadInt<int>();
					if(val[j] < 0) val[i] = -3 - val[j];
					else if(val[j] == 0) val[i] = 0;
					else val[i] = j + n;
				}else if(op == "+"){
					i = ReadInt<int>(),j = ReadInt<int>();
					val[i] = val[j] <= 0?val[j]:j;
				}else if(op == "T")
					i = ReadInt<int>(),val[i] = -1;
				else if(op == "F")
					i = ReadInt<int>(),val[i] = -2;
				else i = ReadInt<int>(),val[i] = 0;
			}
			for(int i = 1;i <= n;i ++){
				if(!vis[i]){
					now = i,vec.clear(),rev.clear();
					while(true){
						vis[now] = true,vec.push_back(now);
						rev.push_back(val[now] > n);
						if(vis[(val[now] - 1) % n + 1] || val[now] <= 0)
							break;
						now = (val[now] - 1) % n + 1;
					}
					for(int j = rev.size() - 2;j >= 0;j --)
						rev[j] ^= rev[j + 1];
					for(int j = 0;j < vec.size();j ++)
						val[vec[j]] = (rev[j]?(val[now] > 0?(val[now] - 1) % n + n + 1:
							      (val[now]?-3 - val[now]:val[now])):(val[now] - 1) % n + 1);
				}
				sval[i] = val[i] == 0 || val[i] == i + n?0:-1;
			}
			ans = 0;
			for(int i = 1;i <= n;i ++)
				ans += val[i] > 0?!sval[(val[i] - 1) % n + 1]:!val[i];
			WriteInt(ans),putchar('\n');
		}
	}
	return 0;
}
