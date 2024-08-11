#include<iostream>
#include<fstream>
using namespace std;
typedef long long LL;
const int N=100010,M=200010;
int n;
int to[M],ne[M],h[N],idx;
LL a[N],d[N];
int b[N],c[N];
int size[N];
inline void getd(){
	for(int i=1;i<=n;i++){
		LL l=0,r=a[i]+n;
		while(l<r){
			int mid=l+r+1>>1;
			if((LL)b[i]>(LL)-mid*c[i])
				l=mid;
			else
				r=mid-1;
		}
		d[i]=l;
		//printf("%lld ",d[i]);
	}
	//puts("");
}
inline void add(int x,int y){
	to[++idx]=y,ne[idx]=h[x];
	h[x]=idx;
}
inline int get(int x,int t){
	if(c[x]>0||t<=d[x])
		return (LL)b[x]*t+(1+t)*t/2*c[x];
	return (LL)b[x]*d[x]+(1+d[x])*d[x]/2*c[x]+t-d[x];
}
/*LL dfs(int x,int t){
	size[x]=1;
	for(int i=h[x];i;i=ne[i]){
		int j=to[i];
		if(size[j])
			continue;
		dfs(j);
		size[x]+=size[j];
	}
}*/
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%d%d",&a[i],&b[i],&c[i]);
	getd();
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	LL ans=0;
	for(int i=1;i<=n;i++){
		LL l=i,r=a[i]+n;
		while(l<r){
			int mid=l+r>>1;
			if(get(i,mid)-get(i,i-1)>=a[i])
				r=mid;
			else
				l=mid+1;
		}
		ans=max(ans,l);
	}
	printf("%lld",ans);
	return 0;
}