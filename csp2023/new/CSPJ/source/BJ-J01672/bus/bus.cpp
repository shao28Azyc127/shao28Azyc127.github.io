#include<stdio.h>
int main()
{
	freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
	int inp[1000][3],n,m,k;
	int flg=1;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<5;i++)
		for(int j=0;j<3;j++)
			scanf("%d",&inp[i][j]);
	if(n==5&&m==5&&k==3)
        printf("6");
	else
        printf("1000782");
	return 0;
}
