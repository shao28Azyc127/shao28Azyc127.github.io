#include<stdio.h>
using namespace std;
int a[10][10];
int b[10];
int ans=0;
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i) 
		for(int j=1;j<=5;++j) scanf("%d",a[i]+j);
	for(b[1]=0;b[1]<=9;++b[1])
	for(b[2]=0;b[2]<=9;++b[2])
	for(b[3]=0;b[3]<=9;++b[3])
	for(b[4]=0;b[4]<=9;++b[4])
	for(b[5]=0;b[5]<=9;++b[5])
	{
		bool flag=1;
		for(int i=1;i<=n;++i)
		{
			bool ok=1;
			for(int j=1;j<=5;++j) ok&=(b[j]==a[i][j]);
			if(ok) {flag=0;break;}
		}
		if(!flag) continue;
		for(int i=1;i<=n;++i)
		{
			int c[10];
			int cnt=0;
			for(int j=1;j<=5;++j) c[j]=(a[i][j]-b[j]+10)%10,cnt+=(c[j]!=0);
			if(cnt>=3){flag=0;break;}
			if(cnt==1) continue;
			if(cnt==2)
			{
				bool ok=0;
				for(int j=1;j<=4;++j)
				{
					if(c[j]&&c[j+1]&&c[j]==c[j+1]) ok=1;
				}
				if(!ok) {flag=0;break;}
			}
		}
		if(flag) ++ans;
	}
	printf("%d\n",ans);
	return 0;
}