#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
mt19937 rnd((unsigned long long)new char);
void file(){freopen("struct.in", "r", stdin); freopen("struct.out", "w", stdout);}
void INIT(){ios::sync_with_stdio(false);}
const bool File = 1;
struct node{
	string tp, nm;
	int num;
	string ctp[105], cnm[105];
	ll id[105], nc[105], s[105], e[105];
	ll anc;
	ll st, ed, dq;
}sct[110];
struct nd{string tp, nm; ll st, ed;}ys[105]; int tmp;
int n;
int cnt = 4;
ll lst;
unordered_map<string, int> mp;
unordered_map<string, string> mp1;
ll get(string tp, string s, int p, ll now){
	if(p == -1) return now;
	int dot = -2;
	string ss = "";
	for(int i = p; i < s.size(); i++){
		if(s[i] != '.') ss = ss + s[i];
		else {dot = i; break;}
	}
	//cout << ss << " " << tp << endl;;
	//if(dot == -1) return now;
	if(p == 0){
		int fl = 0;
		for(int i = 1; i <= tmp; i++){
			if(ys[i].nm == ss){
				fl = i;//, now += ys[i].st;
				break;
			}
			now += ys[i].ed;
		}
		//cout << now << endl;
		return get(ys[fl].tp, s, dot + 1, now);
	}
	int id = mp[tp], fl = 0;
	//cout << ss << "**********\n";
	for(int i = 1; i <= sct[id].num; i++){
		//now += sct[id].e[i];
		if(sct[id].cnm[i] == ss){
			fl = i;//, now = sct[id].s[i];
			break;
		}
		//cout << sct[id].ctp[i] << "*** " << sct[id].e[i] << " " << now << endl;
		now += sct[id].e[i];
		//cout << now << " " << dot << endl;
	}
	//cout << now << "*****\n";
	return get(sct[id].ctp[fl], s, dot + 1, now);
}
string sst;
void get2(ll a, bool t, ll now, int id){
	//cout << now << "***\n";
	if(!t){
		t = 1;
		int fl = 0;
		for(int i = 1; i <= tmp; i++){
			if(a <= ys[i].ed){
				fl = i; now = ys[i].st;
				sst = sst + ys[i].nm;
				break;
			}
		}
		get2(a, t, now, mp[ys[fl].tp]); return;
	}
	//cout << id << "***\n";;
	for(int i = 1; i <= sct[id].num; i++){
		if(now + sct[id].nc[i] >= a){
			if(sct[id].id[i] <= 4){sst = sst + '.' + sct[id].cnm[i]; return;}
			else {get2(a, t, now, sct[id].id[i]); break;}
		}
		now += sct[id].e[i];
	}
}
int main(){ File ? file() : void(); INIT();
	cin >> n;
	mp["byte"] = 1, mp["short"] = 2, mp["int"] = 3, mp["long"] = 4;
	sct[1].anc = 1, sct[2].anc = 2, sct[3].anc = 4, sct[4].anc = 8;
	sct[1].num = sct[2].num = sct[3].num = sct[4].num = 0;
	while(n--){
		int op; cin >> op;
		if(op == 1){
			cin >> sct[++cnt].tp >> sct[cnt].num;
			for(int i = 1; i <= sct[cnt].num; i++)
				cin >> sct[cnt].ctp[i] >> sct[cnt].cnm[i];
			int lst = 0;
			sct[cnt].st = lst;
			for(int i = 1; i <= sct[cnt].num; i++){
				sct[cnt].id[i] = mp[sct[cnt].ctp[i]];
				sct[cnt].nc[i] = sct[sct[cnt].id[i]].anc;
				//sct[cnt].anc += sct[cnt].nc[i];
				sct[cnt].dq = max(sct[cnt].dq, sct[cnt].nc[i]);
			}
			for(int i = 1; i <= sct[cnt].num; i++){
				sct[cnt].s[i] = lst, sct[cnt].e[i] = lst + sct[cnt].dq;
				lst += sct[cnt].dq;
			}
			sct[cnt].ed = lst - 1; sct[cnt].anc = sct[cnt].ed - sct[cnt].st + 1;
			mp[sct[cnt].tp] = cnt;
			cout << sct[cnt].anc << " " << sct[cnt].dq << endl;
		}else if(op == 2){
			string t, st;
			cin >> t >> st;
			ys[++tmp] = {t, st, lst, lst + sct[mp[t]].anc - 1};
			cout << lst << endl; lst = lst + sct[mp[t]].anc - 1;
		}else if(op == 3){
			string s;
			cin >> s;
			cout << get("aaa", s, 0, 0) << endl;
		}else{
			ll a; cin >> a;
			sst = "";
			get2(a, 0, 0, 0);
			cout << sst << endl;
		}
	}
	return 0;
}