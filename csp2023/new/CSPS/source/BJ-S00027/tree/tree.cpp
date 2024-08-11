#include<bits/stdc++.h>
using namespace std;
int n,head[100005],nxt[200005],to[200005],cnt;
long long a[100005],b[100005],c[100005];
bool kb=true;
long long max(long long x,long long y){
	if(x>y) return x;
	return y;
}
struct edge{
	long long f,g;
}e[100005];
void add(int x,int y){
	nxt[++cnt]=head[x];
	head[x]=cnt;
	to[cnt]=y;
}
bool cmp(edge aa,edge bb){
	return aa.f>bb.f;
}
void dfs(int x,int fa){
	int s=0;
	e[x].f=a[x]/b[x]-1;
	if(a[x]%b[x]!=0) e[x].f++;
	e[x].g=1;
	for(int i=head[x];i!=0;i=nxt[i]){
		if(to[i]==fa) continue;
		dfs(to[i],x);
		e[x].g+=e[to[i]].g;
		s++;
	}
	e[x].f=max(1,e[x].f-e[x].g+1);
	if(s==0) return;
	const int ss=s+5;
	int j=0;
	edge k[ss];
	for(int i=head[x];i!=0;i=nxt[i]){
		if(to[i]==fa) continue;
		k[++j].g=e[to[i]].g;
		k[j].f=e[to[i]].f;
	}
	sort(k+1,k+s+1,cmp);
	//if(j!=s) cout<<111;
	int p=e[x].g-1;
	for(int i=1;i<=s;i++){
		//if(x==1) cout<<k[i].g<<" "<<k[i].f<<endl;
		p-=k[i].g;
		e[x].f=max(e[x].f,k[i].f-p);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		if(c[i]!=0) kb=false;
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	if(kb==false){
		cout<<n<<endl;
		return 0;
	}
	dfs(1,0);
	cout<<e[1].g+e[1].f;
	return 0;
}
/*4
2 1 0
4 1 0
5 1 0
7 1 0
1 2
1 3
1 4
*/
