#include<algorithm>
#include<iostream>
#include<ctime>
#include<set>
using namespace std;
const int N = 15002;
int n, m;
int root, tot;
string s1[N];
string s2[N];
struct node{
	int l, r;
	string s;
	int v;
	int cnt;
	int size;
}tree[N];
int get_node(string s){
	++tot;
	tree[tot].size = tree[tot].cnt = 1;
	tree[tot].s = s;
	tree[tot].v = rand();
	return tot;
}
void update(int p){
	tree[p].size = tree[tree[p].l].size + tree[tree[p].r].size + tree[p].cnt;
}
void ru(int &p){
	int x = tree[p].r;
	tree[p].r = tree[x].l;
	tree[x].l = p;
	update(p);
	update(x);
	p = x;
}
void lu(int &p){
	int x = tree[p].l;
	tree[p].l = tree[x].r;
	tree[x].r = p;
	update(p);
	update(x);
	p = x;
}
void insert(int &p, string s){
	if(!p){
		p = get_node(s);
		return;
	}
	if(s < tree[p].s){
		insert(tree[p].l, s);
		if(tree[p].v > tree[tree[p].l].v){
			lu(p);
		}
	}else if(s == tree[p].s){
		tree[p].cnt++;
	}else{
		insert(tree[p].r, s);
		if(tree[p].v > tree[tree[p].r].v){
			ru(p);
		}
	}
	update(p);
}
int merge(int &u, int &v){
	if(!u || !v){
		return u | v;
	}
	if(tree[u].v <= tree[v].v){
		tree[u].r = merge(tree[u].r, v);
		update(tree[u].r);
		update(u);
		return u;
	}else{
		tree[v].l = merge(u, tree[v].l);
		update(tree[v].l);
		update(v);
		return v;
	}
}
void del(int &p, string s){
	if(!p){
		p = get_node(s);
		return;
	}
	if(s < tree[p].s){
		del(tree[p].l, s);
	}else if(s == tree[p].s){
		tree[p].cnt--;
		if(!tree[p].cnt){
			p = merge(tree[p].l, tree[p].r);
		}
	}else{
		del(tree[p].r, s);
	}
	update(p);
}
void dfs(int p){
	if(!p){
		return;
	}
	dfs(tree[p].l);
	cout << "p:" << p << "\tl:" << tree[p].l << "\tr:" << tree[p].r << "\ts:" << tree[p].s << "\tcnt:" << tree[p].cnt << "\tsize:" << tree[p].size << endl;
	dfs(tree[p].r);
}
string get_first(int p){
	if(!p){
		return "ERR";
	}
	if(tree[p].l){
		return get_first(tree[p].l);
	}else{
		return tree[p].s;
	}
}
int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s1[i];
		sort(s1[i].begin(), s1[i].end());
		for(int j = m - 1; j >= 0; j--){
			s2[i] += s1[i][j];
		}
		insert(root, s2[i]);
	}
	for(int i = 1; i <= n; i++){
		del(root, s2[i]);
		insert(root, s1[i]);
		string get = get_first(root);
		cout << (get == s1[i]);
		del(root, s1[i]);
		insert(root, s2[i]);
	}
	cout << endl;
}