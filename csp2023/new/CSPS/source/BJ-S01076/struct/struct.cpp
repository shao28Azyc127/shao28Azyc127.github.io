#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 100+5, INF = 0x3f3f3f3f;
const LL MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f;
string B = "byte", S = "short", I = "int", L = "long";
map<string, LL> ps, sz, mp;
map<string, string> tp;
map<string, map<string, LL>> mem;
LL tot = 0;
void init(){
	sz[B] = 1;
	sz[S] = 2;
	sz[I] = 4;
	sz[L] = 8;
}
void def(){
	string st, t, n;
	LL k, p = 0, s, mx = 0;
	cin>>st>>k;
	for(int i = 1; i <= k; i++){
		cin>>t>>n;
		tp[st+"."+n] = t;
		s = sz[t];
		mx = max(mx, s);
		if(p%s)
			p = (p/s+1)*s;
		mem[st][n] = p;
		sz[st+"."+n] = s;
		ps[st+"."+n] = p;
		p += s;
	}
	if(p%mx) p = (p/mx+1)*mx;
	ps[st] = 0;
	sz[st] = p;
	cout<<p<<' '<<mx<<endl;
}
void crt(){
	string t, n;
	cin>>t>>n;
	tp[n] = t;
	LL s = sz[t];
	if(tot%s) tot = (tot/s+1)*s;
	mp[n] = tot;
	cout<<tot<<endl;
}
void find(){
	string s;
	cin>>s;
	LL pos = 0;
	int f = 0;
	s = s+".";
	string t, cur;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '.'){
			cur = s.substr(f, i-f);
			if(!f){
				pos = mp[cur];
				t = tp[cur];
			}
			else{
				pos += ps[t+"."+cur];
				t = tp[t+"."+cur];
			}
			f = i+1;
		}
	}
	cout<<pos<<endl;
}
string vis(LL ad, map<string, LL> mp){
	LL pos;
	string n, tn;
	for(auto val : mp){
		n = val.first, pos = val.second, tn = tp[n];
		if(pos <= ad && pos+sz[tn] >= ad){
			if(tn == B || tn == S || tn == I || tn == L)
				return n;
			else{
				string res = vis(ad-pos, mem[tn]);
				if(res != "ERR") return n+"."+res;
				else return res;
			}
		}
	}
	return "ERR";
}
#define FILE "struct"
int main(){
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int n, op;
	cin>>n;
	while(n--){
		cin>>op;
		if(op == 1) def();
		else if(op == 2) crt();
		else if(op == 3) find();
		else{
			LL ad;
			cin>>ad;
			cout<<vis(ad, mp)<<endl;
		}
	}
	return 0;
}
