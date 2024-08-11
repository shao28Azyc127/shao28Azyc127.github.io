#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define REPG(i,h,x) for(int i=h[x];~i;i=edge[i].next)
#define CLR(a,x) memset(a,x,sizeof(a))
const int INF=0x3f3f3f3f;

const int N=5e5+5;
int n,m,q,a[N],b[N],oa[N],ob[N];
inline void check(){
		if(a[1]==b[1]||a[n]==b[m]||((a[1]>b[1])!=(a[n]>b[m]))) printf("0");
		else{
			bool flag=false;
			if(a[1]>b[1]){
				int i=1,j=1;
				while(i<=n||j<=m){
					// printf("%d %d\n",i,j);
					// if(a[i]>b[j]) continue;
					if(a[i]<b[j]){
						if(a[i-1]>b[j]){i=j;break;}
						else if(a[i]>b[j-1]) j--;
						else{printf("0");flag=true;break;}
					}
					if(i<=n) i++;
					if(j<=m) j++;
				}
			}else{
				int i=1,j=1;
				while(i<=n||j<=m){
					// if(a[i]<b[j]) continue;
					if(a[i]>b[j]){
						if(a[i-1]<b[j]) i--;
						else if(a[i]<b[j-1]) j--;
						else{printf("0");flag=true;break;}
					}
					if(i<=n) i++;
					if(j<=m) j++;
				}
			}
			if(!flag) printf("1");
		}
}
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%*d%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),oa[i]=a[i];
	for(int i=1;i<=m;i++) scanf("%d",&b[i]),ob[i]=b[i];
	check();
	while(q--){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		for(int i=1,p,v;i<=k1;i++) scanf("%d%d",&p,&v),a[p]=v;
		for(int i=1,p,v;i<=k2;i++) scanf("%d%d",&p,&v),b[p]=v;
		check();
		for(int i=1;i<=n;i++) a[i]=oa[i];
		for(int i=1;i<=m;i++) b[i]=ob[i];
	}
	return 0;
}