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
int a[100001],v[100001];
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
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int r=0,ai=1,aa=a[1],li=0;
	bool flag=true;
	while(ai<n){
		int cnt=0,bi;
		for(int i=ai;i<=n;i++){
			if(aa>a[i]&&i!=n){
				bi=i;
				break;
			}
			if(aa>a[i]&&i==n){
				flag=false;
				break;
			}
		}
		int j=ai;
		do{
			cnt+=v[j];
			j++;
		}while(j<bi);
		r+=ceil(double(cnt-li)/double(d))*aa;
		if(!flag) break;
		li+=ceil(double(cnt)/double(d))*d;
		li-=cnt;
		aa=a[bi];
		ai=bi;
	}
	cout<<r;
	return 0;
}