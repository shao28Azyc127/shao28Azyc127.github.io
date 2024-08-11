#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n=0,num=0;
	cin>>n;
	int bj[200000]={0};
	char a[200000]={};
	getchar();
	for(int i=0;i<n;i++)
	{
		a[i]=getchar();
	}
	for(int i=1;i<=n/2;i++)
	{
		for(int j=0;j<n+1-2*i;j++)
		{
			if(a[j]==a[j+2*i-1])
			{
				bool flag=false;
				for(int x=j+1;x<j+i*2-1;x++)
				{
					if(bj[x]==0)
					{
						flag=true;
						break;
					}
				}
				if(flag==false)
				{
					num++;
					bj[j]=1;
					bj[j+i*2-1]=2;
					if(i==1)
					{
						j++;
					}
				}
			}
		}
		for(int j=0;j<n+1-2*i;j++)
		{
			if(a[j]!=a[j+2*i-1]&&bj[j]==1&&bj[j+2*i-1]==2)
			{
				int s=0,e=0;
				for(int x=j;x<=a[j+2*i-1];x++)
				{
					if(bj[x]==0)
					{
						e=-1;
						break;
					}
					if(bj[x]==1)
					{
						s++;
					}
					if(bj[x]==2)
					{
						e++;
					}
				}
				if(s==e)
				{
					num++;
				}
			}
		}
	}
	cout<<num;
	fclose(stdin);
    fclose(stdout);
    return 0;
}