#include <bits/stdc++.h>
using namespace std;
int n,a[100011][5],ans,A[5];
bool check(int *A,int *a)
{
	int dif[5]={0,0,0,0,0};
	for(int i=0;i<5;++i)dif[i]=(a[i]-A[i]+10)%10;
	int cnt=0;
	for(int i=0;i<5;++i)cnt+=!!dif[i];
	if(!cnt||cnt>=3)return 0;
	if(cnt==1)return 1;
	if(cnt==2)
	{
		for(int i=0;i<4;++i)
		{
			if(dif[i]&&dif[i+1]&&dif[i]==dif[i+1])return 1;
		}
		return 0;
	}
	return 0;
}
int main()
{
	freopen("lock.in","r",stdin);freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d%d%d%d",a[i],a[i]+1,a[i]+2,a[i]+3,a[i]+4);
	for(A[0]=0;A[0]<10;++A[0])for(A[1]=0;A[1]<10;++A[1])for(A[2]=0;A[2]<10;++A[2])for(A[3]=0;A[3]<10;++A[3])for(A[4]=0;A[4]<10;++A[4])
	{
		bool flg=1;
		for(int i=1;i<=n;++i)if(!check(A,a[i])){flg=0;break;}
		//if(flg)printf("%d %d %d %d %d\n",A[0],A[1],A[2],A[3],A[4]);
		ans+=flg;
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);return 0;
}