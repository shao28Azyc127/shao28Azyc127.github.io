#include <bits/stdc++.h>
using namespace std;
int buc[3011][26],mx[3011],mn[3011],n,m;char s[3011];
int main()
{
	freopen("dict.in","r",stdin);freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);mn[i]=1e9;
		for(int j=1;j<=m;++j)++buc[i][s[j]-'a'],mx[i]=max(mx[i],s[j]-'a'),mn[i]=min(mn[i],s[j]-'a');
	}
	for(int i=1;i<=n;++i)
	{
		int flg=1;
		//if(mn[i]==mx[i])
		//{
			for(int j=1;j<=n;++j)if(i!=j)
			{
				if(mx[j]<=mn[i]){flg=0;break;}
			}
		//}
		//else
		//{
		//	for(int j=1;j<=n;++j)
		//}
		printf("%d",flg);
	}putchar(10);
	fclose(stdin);fclose(stdout);return 0;
}