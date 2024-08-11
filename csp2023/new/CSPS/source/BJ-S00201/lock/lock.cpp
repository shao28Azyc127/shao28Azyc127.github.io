#include <bits/stdc++.h>
using namespace std;

int n;
int s[10][10];
bool change[10];

int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			scanf("%d",&s[i][j]);
	if(n==1)
	{
		printf("81\n");
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=5;i++)
    {
        bool flag=false;
        for(int j=1;j<=n;j++)
            if(s[j][i]!=s[1][i])
                flag=true;
        if(flag)
        {
            cnt++;
            change[i]=true;
        }
    }
	for(int i=1;i<=5;i++)
		if(change[i]==true&&(change[i-1]!=true&&change[i+1]!=true)&&cnt>1)
		{
			printf("0\n");
			return 0;
		}
	for(int i=2;i<=n;i++)
	{
		int zf=0;
		for(int j=1;j<=5;j++)
		{
			if(change[j])
			{
				if(zf==0)
					zf==abs(s[1][j]-s[i][j]);
				else if((zf%2==0&&abs(s[1][j]-s[i][j])!=zf)&&zf%2==1&&s[1][j]-s[i][j]!=zf)
				{
					printf("0\n");
					return 0;
				}
			}
		}

	}

	if(n==2&&cnt==1)
	{
		printf("10\n");
		return 0;
	}
	printf("%d",10-n);

	fclose(stdin);
	fclose(stdout);
	return 0;
}