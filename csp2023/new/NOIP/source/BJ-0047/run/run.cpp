#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pii pair<int,int >
#define fir first
#define sec second
#define mk make_pair
const int MX = 1e6 + 7;
const ll INF = 1e18 + 7;
struct node{
	int l,r,v,h;
	ll maxn,f,tag,tag2;
}s[MX];
int tNode = 0,rt = 0;
void pushdown(int x){
	if(s[x].tag != 0){
		if(s[x].l != 0)s[s[x].l].v += s[x].tag;
		if(s[x].r != 0)s[s[x].r].v += s[x].tag;
		if(s[x].l != 0)s[s[x].l].tag += s[x].tag;
		if(s[x].r != 0)s[s[x].r].tag += s[x].tag;
		s[x].tag = 0;
	}
	if(s[x].tag2 != 0){
		if(s[x].l != 0)s[s[x].l].f += s[x].tag2;
		if(s[x].r != 0)s[s[x].r].f += s[x].tag2;
		if(s[x].l != 0)s[s[x].l].maxn += s[x].tag2;
		if(s[x].r != 0)s[s[x].r].maxn += s[x].tag2;
		if(s[x].l != 0)s[s[x].l].tag2 += s[x].tag2;
		if(s[x].r != 0)s[s[x].r].tag2 += s[x].tag2;
		s[x].tag2 = 0;
	}
}
void upd(int x){
	s[x].maxn = max(s[s[x].l].maxn,s[s[x].r].maxn);
	s[x].maxn = max(s[x].maxn,s[x].f);
}
int newnode(int id,ll x){
	++tNode;
	s[tNode].tag2 = s[tNode].tag = s[tNode].l = s[tNode].r = 0;
	s[tNode].h = rand();
	s[tNode].v = id;
	s[tNode].f = s[tNode].maxn = x;
	return tNode;
}
void split(int rt,int k,int &x,int &y){
	if(rt == 0)x = y = 0;
	else{
		pushdown(rt);
		if(s[rt].v <= k)
			x = rt,split(s[rt].r,k,s[rt].r,y);
		else
			y = rt,split(s[rt].l,k,x,s[rt].l);
		upd(rt);
	}
}
int merge(int x,int y){
	if(!x || !y)return x | y;
	pushdown(x);pushdown(y);
	if(s[x].h < s[y].h){
		s[x].r = merge(s[x].r,y);
		upd(x);
		return x;
	}
	else{
		s[y].l = merge(x,s[y].l);
		upd(y);
		return y;	
	}
}
void insert(int id,int x){
	int a,b;
	split(rt,id,a,b);
	rt = merge(a,merge(newnode(id,x),b));
}
void del(int id){
	int a,b,c;
	split(rt,id,a,c);
	split(a,id - 1,a,b);
	b = merge(s[b].l,s[b].r);
	rt = merge(a,merge(b,c));
}
vector<pii > meal[MX];
void print(int id){
	int a,b,c;
	split(rt,id,a,c);
	split(a,id - 1,a,b);
	cerr << "id = " << id << " f = " << s[b].f << '\n';
	rt = merge(a,merge(b,c));
}
void print_all(int x){
	if(x == 0)return;
	cerr << "id = " << s[x].v << " tag = " << s[x].tag << '\n';
	//cerr << "tag1 = " << s[x].tag << " tag2 = " << s[x].tag2 << '\n';
	cerr << "f = " << s[x].f << " maxn = " << s[x].maxn << '\n';
	cerr << "lc = " << s[x].l << " rc = " << s[x].r << '\n';
	print_all(s[x].l);
	print_all(s[x].r);
}
signed main(){
	s[0].f = -INF;s[0].maxn = -INF;
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		int n,m,k,d,cnt = 0;
		rt = tNode = 0;
		cin >> n >> m >> k >> d;
		for(int i = 1;i <= m;i++){
			int x,y,v;
			cin >> x >> y >> v;
			meal[x].push_back(mk(y,v));
		}
		insert(0,0);
		for(int i = 1;i <= k;i++)insert(i,-INF);
		//for(int i = 0;i <= k;i++)print(i);
		for(int i = 1;i <= n;i++){
			ll mx = s[rt].maxn;
			int a,b,c;
			split(rt,k,a,b);
			s[a].tag++;s[a].v++;
			s[a].tag2 -= d;s[a].f -= d;s[a].maxn -= d;
			rt = a;
			insert(0,mx);
			split(rt,k,a,b);
			rt = a;
			for(auto j : meal[i]){
				//cerr << "meal " << ++cnt << '\n';
				int y = j.fir,v = j.sec;
				split(rt,y - 1,a,b);
				s[b].tag2 += v;s[b].f += v;s[b].maxn += v;
				rt = merge(a,b);
			}
			//cerr << tNode << '\n';
		}
		cout << s[rt].maxn << '\n';
		for(int i = 1;i <= m;i++)meal[i].clear();
	}
	return 0;
}