#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

struct node{
	string type;
	string name;
};
inline node mknd(string a, string b){
	node ret;
	ret.type = a, ret.name = b;
	return ret;
}

struct stru{
	ll siz, v;
	string type;
	vector<node> vec;
};
stru Byte, Short, Int, Long;

map<string, stru> mp;
map<string, ll> mp2;
vector<node> V;

ll Minh(ll a, ll b){
	if(a==0) return 0;
	return b*((a-1)/b+1);
}

ll calcSiz(const stru &tmp){
	ll ret = 0;
	for(int i=0;i<tmp.vec.size();i++){
		node cur = tmp.vec[i];
		stru curt = mp[cur.type];
		ll k = Minh(ret, curt.v);
		ret = curt.siz+k;
	}
	ret = Minh(ret, tmp.v);
	return ret;
}

ll getsiz(stru s, string st){
	ll ret = 0;
	string t = "";
	int i = 0;
	for(i=0;i<st.size();i++){
		if(st[i]=='.'){
			t = st.substr(0, i);
			break;
		}
	}
	i++;
	if(!t.size()) return 0;
	for(int j=0;j<s.vec.size();j++){
		stru ss = mp[s.vec[i].type];
		ret = Minh(ret, ss.v);
		if(s.vec[j].name==t){
			return ret+getsiz(ss, st.substr(i));
		}
		ret += ss.siz;
	}
	return ret;
}

ll getans(string st){
	int l = st.length();
	ll ret = 0;
	string t = "";
	int i = 0;
	for(i=0;i<l;i++){
		if(st[i]=='.'){
			t = st.substr(0, i);
			break;
		}
	}
	
	ret = mp2[t];
	i++;
	
	if(!t.size()) return mp2[st];
	
	for(int j=0;j<V.size();j++){
		if(V[j].name==t){
			ret += getsiz(mp[V[j].type], st.substr(i));
			return ret;
		}
	}
	return ret;
}

string check(stru s, ll addr){
	ll q = 0;
	for(int i=0;i<s.vec.size();i++){
		node n = s.vec[i];
		ll qq = Minh(q, mp[n.type].v);
		if(q<=addr && addr<qq) return "ERR";
		q = qq+mp[n.type].siz;
		if(addr>=qq && addr<q){
			string k = "."+n.name;
			string c = check(mp[n.type], addr-qq);
			if(c=="ERR") return "ERR";
			else return k+c;
		}
	}
	return "ERR";
}

int main(){
	ios::sync_with_stdio(0);
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	
	cin >> n;
	
	Byte.type = "byte", Byte.siz = 1, Byte.v = 1;
	Short.type = "short", Short.siz = 2, Short.v = 2;
	Int.type = "int", Int.siz = 4, Int.v = 4;
	Long.type = "long", Long.siz = 8, Long.v = 8;
	
	mp["byte"] = Byte, mp["short"] = Short, mp["int"] = Int, mp["long"] = Long;
	
	ll p = 0;
	
	for(int i=1;i<=n;i++){
		int op;
		cin >> op;
		if(op==1){
			int k;
			stru tmp;
			cin >> tmp.type >> k;
			tmp.siz = tmp.v = 0;
			for(int j=0;j<k;j++){
				string t, n;
				cin >> t >> n;
				tmp.vec.push_back(mknd(t, n));
				stru s = mp[t];
				tmp.v = max(tmp.v, s.siz);
			}
			tmp.siz = calcSiz(tmp);
			mp[tmp.type] = tmp;
			cout << tmp.siz << ' ' << tmp.v << endl;
		}
		else if(op==2){
			string t, n;
			cin >> t >> n;
			stru s = mp[t];
			ll k = Minh(p, s.v);
			cout << k << endl;
			mp2[n] = k;
			V.push_back(mknd(t, n));
			p = k+s.siz;
		}
		else if(op==3){
			string st;
			cin >> st;
			cout << getans(st) << endl;
		}
		else if(op==4){
			bool flag = 0;
			ll addr;
			cin >> addr;
			for(int i=0;i<V.size();i++){
				node nd = V[i];
				ll q = mp2[nd.name];
				stru s = mp[nd.type];
				if(addr>=q && addr<q+s.siz){
					string t = check(s, addr-q);
					if(t=="ERR") cout << "ERR" << endl;
					else cout << nd.name << t << endl;
					flag = 1;
					break;
				}
			}
			if(!flag) cout << "ERR" << endl;
		}
	}
	
	return 0;
}
