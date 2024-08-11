#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define ll long long
using namespace std;
inline int read(){int x=1,f=0;char ch=getchar();
    while(ch<'0' && ch>'9'){if(ch=='-')x=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){f=f*10+ch-'0';ch=getchar();}
    return x*f;
}
/*
5 4
10 10 10 10
9 8 9 6 5
out:79
*/
const int N=1e5+5;
int n,d,v[N],a[N],b[N],you=0;
ll ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	n=read(),d=read();v[1]=0;
	for(int i=2;i<=n;++i) v[i]=read();
	rep(i,n) a[i]=read();
	a[n]=-1;int i=1;
	while(i<=n-1){
		int m=0;
		for(int j=i+1;j<=n;++j){
			m+=v[j];
			if(a[j]<=a[i]){
				if(you<m){
					int xu=((m-you)/d+(((m-you)%d)>=1));
					ans+=xu*a[i];
					you+=xu*d-m;
				}else you-=m;
				i=j;
				break;
			}
		}
	}printf("%lld",ans);
    return 0;
}
