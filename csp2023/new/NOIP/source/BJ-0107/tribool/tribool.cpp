#include<bits/stdc++.h>
#define ffor(i,l,r) for(int i=(l),i##_end=(r);i<=i##_end;i++)
#define rfor(i,l,r) for(int i=(l),i##_end=(r);i>=i##_end;i--)
#define file(name,dat) freopen(name".in","r",stdin),freopen(name dat,"w",stdout)
using namespace std;
using ll = long long;
int ns = 0;
int fa[600010];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int x0[100010],x1[100010];
int c0[100010],c1[100010];
int tag[100010];
void updateNode(int i){
	x0[i] = ++ns;
	x1[i] = ++ns;
	tag[i] = 0;
	//assert(ns<=400000);
	//cout<<ns<<"\n";
}
void addedge(int u,int v){
	u = getfa(u);
	v = getfa(v);
	fa[u] = v;
}
int constNode(char c){
	if(c=='T') return 100001;
	if(c=='F') return 100002;
	if(c=='U') return 100003;
}
int constId(char c){
	if(c=='T') return 600001;
	if(c=='F') return 600002;
	if(c=='U') return 600003;
	assert(1);
	return -1;
}
int n,m,ans;
bool is[100010];
set<int> die;
void init(){
	ns = 0;
	ans = 0;
	ffor(i,1,4*n) fa[i] = i;
	fa[constId('T')] = constId('T');
	fa[constId('F')] = constId('F');
	fa[constId('U')] = constId('U');
	ffor(i,1,n){
		updateNode(i);
		c0[i] = x0[i];
		c1[i] = x1[i];
	} 
		
}

void Do(){
	cin>>n>>m;
	//clear();
	init();
	
	ffor(www,1,m){
		char v;cin>>v;
		if(v=='+'){
			int i,j;cin>>i>>j;
			updateNode(i);
			addedge(x0[j],x0[i]);
			addedge(x1[j],x1[i]);
		}else if(v=='-'){
			int i,j;cin>>i>>j;
			updateNode(i);
			if(tag[j]) tag[i] = tag[j];
			addedge(x0[j],x1[i]);
			addedge(x1[j],x0[i]);
		}else{
			int i;cin>>i;
			updateNode(i);
			tag[i] = constId(v);
			// addedge(constId(v),x0[i]);
			// addedge(constId(v),x1[i]);
		}
	}
	//int qk = getfa(constId('U'));
	// ffor(i,1,n){
	// 	int z;
	// 	if((z=getfa(c0[i]))==getfa(x1[i])){
	// 		die.insert(z);
	// 		continue;
	// 	}
	// 	if((z=getfa(c1[i]))==getfa(x0[i])){
	// 		die.insert(z);
	// 		continue;
	// 	}
	// 	if(getfa(x0[i])==qk){
	// 		die.insert(c0[i]);
	// 	}
	// 	if(getfa(x1[i])==qk){
	// 		die.insert(c1[i]);
	// 	}
	// }
	
	// ffor(i,1,n){
	// 	int x = getfa(x0[i]),y = getfa(x1[i]);
	// 	if(die.find(x)!=die.end()||die.find(y)!=die.end()){
	// 		is[i] = true;
	// 	}
	// 	if(x==qk||y==qk){
	// 		is[i] = true;
	// 	}
	// }
	// ffor(i,1,n){
	// 	if(is[i]){
	// 		//cout<<i<<" :\n";
	// 		ans++;
			
	// 	} 
	// }
	ffor(i,1,n){
		addedge(c0[i],x0[i]);
		addedge(c1[i],x1[i]);
	}
	ffor(i,1,n){
		if(tag[i]==constId('U')){
			addedge(c0[i],c1[i]);
		}
	}
	ffor(i,1,n){
		if(getfa(x0[i])==getfa(x1[i])){
			//cout<<i<<":\n";
			ans++;
		}
	}
	cout<<ans<<"\n";
}
int c,t;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--) Do();
	return 0;
}