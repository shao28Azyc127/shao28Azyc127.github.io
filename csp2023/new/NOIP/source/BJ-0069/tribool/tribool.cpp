#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int tid;
int n,m;
struct node {
	int v,id;
	node(int a=0,int b=0):v(a),id(b){}
}num[N];
int rv[500];
char get_char()
{
	char ch;
	ch=getchar();
	while(ch!='T'&&ch!='F'&&ch!='U'&&ch!='+'&&ch!='-')
		ch=getchar();
	return ch;
}
bool vis[N];
vector<int> edg[N];
queue<int> q;
node dfs(int idx)
{
	//cout<<idx<<" "<<num[idx].id<<endl;
	vis[idx]=1;
	if(num[idx].id==idx) return num[idx];
	else if(vis[num[idx].id]) return num[idx];
	else {
		node tmp=dfs(num[idx].id);
		tmp.v^=num[idx].v;
		num[idx]=tmp;
		return num[idx];
	}
}
void sol()
{
	scanf("%d%d",&n,&m);
	int i,j,k;
	for(i=1;i<=n+3;i++) {
		num[i]=node(0,i);
		vis[i]=0;
		edg[i].clear();
	}
	rv['T'-'A']=n+1;
	rv['F'-'A']=n+2;
	rv['U'-'A']=n+3;
	char op;
	for(i=1;i<=m;i++)
	{
		op=get_char();
		if(op=='+') {
			scanf("%d%d",&j,&k);
			num[j]=num[k];
		}
		else if(op=='-'){
			scanf("%d%d",&j,&k);
			num[j]=num[k];
			num[j].v=(!num[j].v);
		}
		else {
			scanf("%d",&j);
			num[j].v=0;
			num[j].id=rv[op-'A'];
		}
	}
	//for(i=1;i<=n;i++) cout<<num[i].v<<" "<<num[i].id<<endl;
	for(i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);
	
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++) {
		edg[num[i].id].push_back(i);
	}
	while(!q.empty()) q.pop();
	q.push(n+3);
	for(i=1;i<=n;i++)
	{
		if(num[i].id==i&&num[i].v)
			q.push(i);
	}
	int ans=0,x;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		++ans;
		for(int to:edg[x]) {
			if(vis[to]) continue;
			q.push(to);
		}
	}
	printf("%d\n",ans-1);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int t;
	scanf("%d%d",&tid,&t);
	while(t)
	{
		--t;
		sol();
	}	
	return 0;
}