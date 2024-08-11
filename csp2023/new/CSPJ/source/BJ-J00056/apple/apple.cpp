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
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1]={0},i,j,t,flag=2;
	bool c=true,ft=false;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(a[j]==0){
				flag=2;
				break;
			}
		}
		for(int l=j;l<=n;l++){
			if(a[l]==0&&flag==2){
				a[l]=1;
				flag=0;
				continue;
			}
			if(a[l]==0&&flag==0){
				flag=1;
				continue;
			}
			if(a[l]==0&&flag==1){
				flag=2;
				continue;
			}
		}
		if(a[n]==1&&ft==false){
			t=i;
			ft=true;
		}
		c=true;
		for(int l=1;l<=n;l++){
			if(a[l]==0){
				c=false;
				break;
			}
		}
		if(c){
			cout<<i<<' '<<t;
			break;
		}
	}
	return 0;
}
