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

signed main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m;
	cin>>t>>m;
	int a[t],b[t],c[t];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	return 0;
}
