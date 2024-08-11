#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#define int long long
#define rep(i,a,n) for(register int i=a;i<=n;++i)
#define dwn(i,n,a) for(register int i=n;i>=a;--i)
using namespace std;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x==0)return;
	write(x/10);
	putchar(x%10+'0');
}
struct st{
	int u,v,a;
};
signed main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	st b[m+1];
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].a;
	}
	int f[m+1]={0},x;
	bool flag=true;
	f[1]=k;
	for(int i=2;i<=m;i++){
		x=0;
		for(int j=1;j<=m;j++){
			if(b[j].v==i){
				x=b[j].u;
				break;
			}
		}
		if(!x){
			cout<<-1;
			flag=false;
			break;
		}
		if(f[x]+1<f[i]||f[i]==0) f[i]=f[x]+1;
		if(f[i]<b[x].a) f[i]=b[x].a;
	}
	if(flag) cout<<ceil(double(f[m])/double(k))*k;
	return 0;
}
