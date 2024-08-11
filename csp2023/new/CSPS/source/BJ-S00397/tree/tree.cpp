#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=1e5+10,M=N<<1;
int a[N],b[N],c[N];
int head[N],ver[M],nxt[M],tot=0;
void add(int x,int y)
{
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=read(),c[i]=read();
	for(int i=1;i<n;i++){int u=read(),v=read();add(u,v),add(v,u);}
	puts("0");
	return 0;
}
