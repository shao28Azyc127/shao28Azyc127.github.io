#include <bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
struct node {
	int a[N],id;
	bool operator<(node b) {
		for(int i=1;i<=m;i++)
			if(a[i]<b.a[i]) return true;
			else if(a[i]>b.a[i]) return false;
		return false;
	}
}p[N],rp[N];
char s[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(j=1;j<=m;j++)
			p[i].a[j]=s[j]-'a';
		sort(p[i].a+1,p[i].a+1+m);
		for(j=m;j>=1;--j)
			rp[i].a[j]=s[j]-'a';
		sort(rp[i].a+1,rp[i].a+1+m,[](int i,int j){ return i>j;});
		p[i].id=i,rp[i].id=i;
	}
	sort(rp+1,rp+1+n);
	for(i=1;i<=n;i++)
	{
		if(rp[1].id==i&&p[i]<rp[2]) printf("1");
		else if(rp[1].id!=i&&p[i]<rp[1]) printf("1");
		else printf("0");
	}
	puts("");
	return 0;
}