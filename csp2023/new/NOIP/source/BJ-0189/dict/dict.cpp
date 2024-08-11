#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3010;
int n,m,ans[N];
struct str{
	char s[N];
	int t;
};
bool cmp1(char x,char y){
	return x>y;
}
bool cmp(str x,str y){
	int i=0;
	while(i<m && x.s[i]==y.s[i])
		++i;
	return i>=m?x.t>y.t:x.s[i]<y.s[i];
}
str a[N<<1];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d %d",&n,&m);
	memset(ans,0,sizeof(ans));
	for(int i=0; i<n; ++i){
		scanf("%s",a[i*2].s);
		a[i*2].t=i+1;
		a[i*2+1]=a[i*2];
		sort(a[i*2+1].s,a[i*2+1].s+m);
		sort(a[i*2].s,a[i*2].s+m,cmp1);
		a[i*2+1].t=-i-1;
	}
	sort(a,a+n*2,cmp);
	/*for(int i=0; i<n*2; ++i)
		printf("%d %s\n",a[i].t,a[i].s);*/
	int i=0;
	while(a[i].t<0){
		ans[-a[i].t]=1;
		++i;
	}
	if(a[i].t==-a[i+1].t)
		ans[a[i].t]=1;
	for(int i=1; i<=n; ++i)
		printf("%d",ans[i]);
	putchar('\n');
	return 0;
}