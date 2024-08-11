#include<stdio.h>
#include<algorithm>
using namespace std;
const int NR=3e3+5;
const int P1=1000010243;
const int P2=1000019249;
char s[NR][NR];
int has1[NR][NR];
int has2[NR][NR];
int h1[NR],h2[NR];
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i) sort(s[i]+1,s[i]+m+1,cmp);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j) has1[i][j]=(has1[i][j-1]*131ll+s[i][j])%P1;
		for(int j=1;j<=m;++j) has2[i][j]=(has2[i][j-1]*137ll+s[i][j])%P2;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=m;j>=1;--j) h1[j]=(h1[j+1]*131ll+s[i][j])%P1;
		for(int j=m;j>=1;--j) h2[j]=(h2[j+1]*137ll+s[i][j])%P2;
		int ans=1;
		for(int k=1;k<=n;++k)
		{
			if(i==k) continue;
			int l=1,r=m;
			int res=0;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(has1[k][mid]==h1[m+1-mid]&&has2[k][mid]==h2[m+1-mid]) res=mid,l=mid+1;
				else r=mid-1;
			}
			if(res==m) {ans=0;break;}
			if(s[k][res+1]<s[i][(m+1)-(res+1)]) {ans=0;break;}
		}
		putchar(ans+'0');
	}
	puts("");
	return 0;
}