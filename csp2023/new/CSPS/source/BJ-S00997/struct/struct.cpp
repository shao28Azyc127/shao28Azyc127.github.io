#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=110;
#define int long long

int n,cnt,addr;
map<string,int> mp;
vector<int> v;
vector<int> adp;
vector<string> nam;
map<string,int> rnk;
struct Node {
	string name;
	int siz,add,maxn;
	vector<int> v;
	vector<int> pos;
	vector<string> nam;
	map<string,int> rnk;
} a[N];

void work1() {
	string s,ty,nm; cin>>s;
	int k; cin>>k;
	mp[s]=++cnt; a[cnt].name=s; a[cnt].siz=k;
	a[cnt].v.push_back(0);
	a[cnt].pos.push_back(0);
	a[cnt].nam.push_back("");
	for (int i=1; i<=k; i++) {
		cin>>ty>>nm; int id=mp[ty];
		int pos=a[cnt].pos[i-1]+a[a[cnt].v[i-1]].add;
		while (pos%a[id].maxn) pos++;
		a[cnt].v.push_back(id);
		a[cnt].rnk[nm]=i;
		a[cnt].pos.push_back(pos);
		a[cnt].maxn=max(a[cnt].maxn,a[id].maxn);
		a[cnt].add=pos;
		a[cnt].nam.push_back(nm);
	} int pos=a[cnt].add+a[a[cnt].v.back()].add;
	while (pos%a[cnt].maxn) pos++;
	a[cnt].add=pos;
	cout<<a[cnt].add<<' '<<a[cnt].maxn<<'\n';
}

void work2() {
	string ty,nm; cin>>ty>>nm;
	int id=mp[ty];
	int pos=adp.back()+a[v.back()].add;
	while (pos%a[id].maxn) pos++;
	v.push_back(id); adp.push_back(pos);
	rnk[nm]=v.size()-1;
	nam.push_back(nm);
	cout<<pos<<'\n';
}

void work3() {
	string str; cin>>str;
	int len=str.length(),cnt=0;
	for (int i=0; i<len; i++)
		if (str[i]=='.') cnt++;
	int i=0,last=0,belong=-1,pos=0;
	while (cnt--) {
		last=i;
		while (str[i]!='.') i++;
		string tmp="";
		for (int j=last; j<i; j++) tmp+=str[j];
		int id;
		if (belong==-1) {
			id=rnk[tmp];
			belong=v[id];
			pos=adp[id];
		} else {
			id=a[belong].rnk[tmp];
			pos+=a[belong].pos[id];
			belong=a[belong].v[id];
		} i++;
	} string tmp="";
	for (int j=i; j<len; j++) tmp+=str[j];
	int id;
	if (belong==-1) {
		id=rnk[tmp];
		belong=v[id];
		pos=adp[id];
	} else {
		id=a[belong].rnk[tmp];
		pos+=a[belong].pos[id];
		belong=a[belong].v[id];
	} cout<<pos<<'\n';
}

void work4() {
	string ans="";
	ll query; cin>>query;
	int belong=upper_bound(adp.begin(),adp.end(),query)-adp.begin()-1;
	query-=adp[belong];
	ans+=nam[belong];
	belong=v[belong];
	while (a[belong].siz>1) {
		int tmp=upper_bound(a[belong].pos.begin(),a[belong].pos.end(),query)-a[belong].pos.begin()-1;
		query-=a[belong].pos[tmp];
		ans+='.';
		ans+=a[belong].nam[tmp];
		belong=a[belong].v[tmp];
	}
	if (query<=a[belong].add) cout<<ans<<'\n';
	else cout<<"ERR\n";
}

signed main() {
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	mp["byte"]=++cnt; mp["short"]=++cnt; mp["int"]=++cnt; mp["long"]=++cnt;
	a[1].name="byte"; a[2].name="short"; a[3].name="int"; a[4].name="long";
	a[1].siz=1; a[1].add=a[1].maxn=1;
	a[2].siz=1; a[2].add=a[2].maxn=2;
	a[3].siz=1; a[3].add=a[3].maxn=4;
	a[4].siz=1; a[4].add=a[4].maxn=8;
	a[0].add=0; v.push_back(0); adp.push_back(0); nam.push_back("");
	cin>>n;
	while (n--) {
		int op; cin>>op;
		if (op==1) work1();
		else if (op==2) work2();
		else if (op==3) work3();
		else work4();
	}
	return 0;
}