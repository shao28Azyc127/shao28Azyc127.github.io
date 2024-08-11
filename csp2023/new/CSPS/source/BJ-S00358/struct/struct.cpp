#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pis pair<int, string>
#define mp make_pair
const int MAXN=1e2+5, MAXL=1e7+5, MOD=1e7+7;
ll n, k, cnt=0, tot=0, op, addr, now=0, place[MAXL], bit[MOD+5];
string s, t, name;
struct Node{
	int num;
	vector<pis> mem;
}jgt[MAXN];
struct col{
	ll type, st;
	string app;
}col[MAXN*MAXN];
inline int Change(string x){
	if(x=="byte") return 1;
	if(x=="short") return 2;
	if(x=="int") return 4;
	if(x=="long") return 8;
	return -1;
}
inline ll Plus(string x){
	ll sum=0;
	for(int i=0; i<x.size(); i++){
		sum=(sum*131+x[i]-'a')%MOD;
	}
	return sum;
}
inline void Address(int k){
	int len=col[k].type;
	if(now%len){
		now=(now/len+1)*len;
	}
	for(int i=now; i<now+len; i++){
		place[i]=k;
	}
	col[k].st=now;
	now=now+len;
}
inline void Addstr(){
	cin >> k >> s;
	jgt[++cnt].num=k;
	bit[Plus(s)]=cnt;
	for(int i=1; i<=k; i++){
		cin >> t >> name;
		jgt[cnt].mem.push_back(mp(Change(t), name));
	}
}
inline void Addmem(){
	cin >> t >> name;
	col[++tot].type=Change(t);
	col[tot].app=name;
	bit[Plus(name)]=tot;
	Address(tot);
	cout << col[tot].st << endl;
}
int main(){
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	while(n--){
		cin >> op;
		if(op==1){
			Addstr();
		}
		else if(op==2){
			Addmem();
		}
		else if(op==3){
			cin >> s;
			cout << col[bit[Plus(s)]].st << endl;
		}
		else{
			cin >> addr;
			if(!place[addr]) cout << "ERR" << endl;
			else{
				cout << col[place[addr]].app << endl;
			}
		}
	}
	return 0;
}