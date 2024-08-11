#include <cstdio>
using namespace std;
const int lg[5]={1,10,100,1000,10000};
int n,num[5],cnt[100000];
long long ans;
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int i,j,k,tmp,tar;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		ans=0;
		for(j=0;j<5;j++)
			scanf("%d",&num[j]);
		for(j=0;j<5;j++)
		{
			for(k=1;k<=9;k++)
			{
				num[j]=(num[j]+1)%10;
				tmp=num[0]*lg[4]+num[1]*lg[3]+num[2]*lg[2]+num[3]*lg[1]+num[4];
				if(cnt[tmp]==i-1)
				{
					cnt[tmp]++;
					ans++;
				}
			}
			num[j]=(num[j]+1)%10;
		}
		for(j=0;j<4;j++)
		{
			for(k=1;k<=9;k++)
			{
				num[j]=(num[j]+1)%10;
				num[j+1]=(num[j+1]+1)%10;
				tmp=num[0]*lg[4]+num[1]*lg[3]+num[2]*lg[2]+num[3]*lg[1]+num[4];
				if(cnt[tmp]==i-1)
				{
					cnt[tmp]++;
					ans++;
				}
			}
			num[j]=(num[j]+1)%10;
			num[j+1]=(num[j+1]+1)%10;
		}
	}
	printf("%lld",ans);
	return 0;
}