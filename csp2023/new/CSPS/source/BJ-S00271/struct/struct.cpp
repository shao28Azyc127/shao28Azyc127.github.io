#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000010;
map<string,int> mp;
map<string,int> sz;
map<string,int> dir;
map<string,int> sun;
int n,idx;
int tot;
string ans[1000010];
bool vis[N];
vector<string> stc[110];
vector<string> nam[110];
int get(int k,int x)
{
	int num = k/x;
	if(k%x == 0) return k;
	else return (num+1)*x;
}
void solve1()
{
	string s;
	int k;
	int now = 0;
	cin >> s >> k;
	dir[s] = ++idx;
	for(int i = 1;i <= k;++i)
	{
		string t,na;
		cin >> t >> na;
		stc[idx].push_back(t);
		nam[idx].push_back(na);
		mp[s] = max(mp[s],mp[t]);
		now = get(now,mp[t]);
		now = now + mp[t];
	}
	cout << now << ' ' << mp[s] << endl;
	sz[s] = now;
}
/*
4
1 a 2
byte a1
long a2
2 a sb
4 7
3 sb.a1
*/
void solve2()
{
	string t,na;
	cin >> t >> na;
	//cout << tot << endl;
	tot = get(tot,mp[t]);
	//cout << tot << ' ' << mp[t] << endl;
	cout << tot << endl;
	if(t == "long" || t == "int" || t == "short" || t == "byte")
	{
		sun[na] = tot;
		for(int i = 0;i < sz[t];++i)
		{
			vis[tot] = true;
			ans[tot++] = na;
		}
		return ;
	}
	int d = dir[t];
	//cout << d << endl;
	for(int i = 0;i < stc[d].size();++i)
	{
		//cout << "Ok" << endl;
		int siz = sz[stc[d][i]];
		tot = get(tot,mp[stc[d][i]]);
		sun[na + "." + nam[d][i]] = tot;
		//cout << tot << endl;
		//cout << tot << ' ' << siz << endl;
		for(int j = 0;j < siz;++j)
		{
			ans[tot] = na + "." + nam[d][i];
			//cout << na + "." + nam[d][i] << ' ';
			vis[tot++] = true;
		}
		//cout << endl;
	}
	//for(int i = 0;i < tot;++i) 
		//if(vis[i]) cout << ans[i] << ' ';
		//else cout << ' ';
	//cout << endl;
	//cout << tot << endl;
}

void solve3()
{
	string s;
	cin >> s;
	cout << sun[s] << endl;
}
void solve4()
{
	LL d;
	cin >> d;
	if(!vis[d]) cout << "ERR" << endl;
	else cout << ans[d] << endl;
}
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	mp["long"] = 8,mp["byte"] = 1,mp["int"] = 4,mp["short"] = 2;
	sz["long"] = 8,sz["byte"] = 1,sz["int"] = 4,sz["short"] = 2;
	cin >> n;
	for(int i = 1;i <= n;++i)
	{
		int opt;
		cin >> opt;
		if(opt == 1) solve1();
		else if(opt == 2) solve2();
		else if(opt == 3) solve3();
		else solve4();
	} 
	return 0;
}
