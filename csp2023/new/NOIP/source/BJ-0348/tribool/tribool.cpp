#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2e5 + 5;
const int M = 2e5 + 5;

struct node{
	int idx,val;
	bool tag;
}b[N];

struct que{
	int u,x,y;// T1 F0 U2 +3 -4
}opt[M];

int n,m;

void calc(){
	for(int i = 1;i <= m;i++){
		if(opt[i].u == 3){
			b[opt[i].x] = b[opt[i].y];
		} else if(opt[i].u == 4){
			b[opt[i].x] = b[opt[i].y];
			b[opt[i].x].tag ^= 1;
		} else {
			b[opt[i].x].val = opt[i].u;
			b[opt[i].x].idx = 0;
			b[opt[i].x].tag = 0;
		}
	}
}

int fa[N*2];
int val[N*2];
bool ok[N*2];

int find(int xx){
	//~ cerr << "find:" << xx << "\n";
	return (xx == fa[xx]? xx:fa[xx] = find(fa[xx]));
}

void init(){
	//set?
	for(int i = 1;i <= n*2;i++){
		fa[i] = i;
		ok[i] = true;
		val[i] = 0;
	}
	for(int i = 1;i <= n;i++){
		b[i].idx = i;
		b[i].tag = 0;
		b[i].val = -1;
	}
}

inline void merge(int xx,int yy,bool tag){
	if(tag == 0){
		if(!ok[find(xx)] || !ok[find(yy)] || find(xx+n) == find(yy)){
			ok[find(xx)] = 0;
			ok[find(yy)] = 0;
			ok[find(xx+n)] = 0;
			ok[find(yy+n)] = 0;
			return;
		}
		//~ cerr << "merge same:" << xx << " " << yy << "\n";
		fa[find(xx)] = find(yy);//find!!!
		val[find(yy)] = max(val[find(yy)],val[find(xx)]);
		fa[find(xx+n)] = find(yy+n);
		val[find(yy+n)] = max(val[find(yy+n)],val[find(xx+n)]);
	} else {
		if(!ok[find(xx)] || !ok[find(yy)] || find(xx) == find(yy)){
			ok[find(xx)] = 0;
			ok[find(yy)] = 0;
			ok[find(xx+n)] = 0;
			ok[find(yy+n)] = 0;
			return;
		}
		//~ cerr << "merge diff:" << xx << " " << yy << "\n";
		fa[find(xx)] = find(yy+n);
		val[find(yy+n)] = max(val[find(yy+n)],val[find(xx)]);
		fa[find(xx+n)] = find(yy);
		val[find(yy)] = max(val[find(yy)],val[find(xx+n)]);
	}
}

int proc(){
	int res = 0;
	//~ for(int i = 1;i <= n;i++){
		//~ cerr << i << "(" << b[i].idx << ", " << b[i].val << ", " << b[i].tag << ")\n";
	//~ }
	for(int i = 1;i <= n;i++){
		if(b[i].idx != 0){
			merge(i,b[i].idx,b[i].tag);
		} else if(b[i].val == 2){
			val[find(i)] = 2;
			val[find(i+n)] = 2;
		}
	}
	for(int i = 1;i <= n;i++){
		if(!ok[find(i)] || val[find(i)] == 2)
			res++;
	}
	return res;
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int C,T;
	cin >> C >> T;
	while(T--){
		cin >> n >> m;
		init();//!!!
		for(int i = 1;i <= m;i++){
			char tmp;
			cin >> tmp;
			if(tmp == '+'){
				opt[i].u = 3;
				cin >> opt[i].x >> opt[i].y;
			} else if(tmp == '-'){
				opt[i].u = 4;
				cin >> opt[i].x >> opt[i].y;
			} else{
				cin >> opt[i].x;
				if(tmp == 'U') opt[i].u = 2;
				else if(tmp == 'T') opt[i].u = 1;
				else if(tmp == 'F') opt[i].u = 0;
			}
		}
		calc();
		int ans = proc();
		cout << ans << "\n";
	}
	return 0;
}
