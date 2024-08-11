#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 3000+5, INF = 0x3f3f3f3f;
const LL MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f;
int n, m;
string word[N], mx[N], mn[N];
inline bool cmp(string a, string b){ // a < b
	for(int i = 0; i < m; i++) if(a[i] != b[i]) return a[i] < b[i];
	return 0; // a == b;
}
struct Node{
	int id;
	string w;
	bool operator<(Node x){ return cmp(w, x.w); } // <= O(m)
	Node(int i){ id = i, w = mx[i]; }
};
vector<Node> bkt;
inline bool cmp1(char a, char b){ return a < b; }
inline bool cmp2(char a, char b){ return a > b; }
#define File "dict"
int main(){
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>word[i];
		mx[i] = word[i];
		mn[i] = word[i];
		sort(mx[i].begin(), mx[i].end(), cmp2);
		sort(mn[i].begin(), mn[i].end(), cmp1);
		//cout<<word[i]<<' '<<mx[i]<<' '<<mn[i]<<endl;
		bkt.push_back(Node(i));
	}
	sort(bkt.begin(), bkt.end()); // <= O(nmlogn)
	//for(auto w : bkt) cout<<w.id<<' '<<word[w.id]<<' '<<w.w<<endl;
	for(int i = 1; i <= n; i++){
		if(i == bkt[0].id || cmp(mn[i], bkt[0].w)) cout<<1; // O(nm)
		else cout<<0;
	}
	return 0;
}
