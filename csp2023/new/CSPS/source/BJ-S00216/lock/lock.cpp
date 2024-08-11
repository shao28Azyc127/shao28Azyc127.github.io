#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int ret=0,f=1;char c=getchar();
	while(!(c>='0'&&c<='9'))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ret=ret*10+c-'0';
		c=getchar();
	}
	return f*ret;
}
int n,a[105][105],t[50],ans1=0,ans2=0;
signed main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++) 
		{
			cin>>a[i][j];
		}
	}
	int ans=0;
	for(t[1]=0;t[1]<=9;t[1]++)
	{
		for(t[2]=0;t[2]<=9;t[2]++)
		{
			for(t[3]=0;t[3]<=9;t[3]++)
			{
				for(t[4]=0;t[4]<=9;t[4]++)
				{
					for(t[5]=0;t[5]<=9;t[5]++)
					{
						int flag=0;
						int dif=0,ap=0;
						for(int i=1;i<=5;i++)
						{
							if(t[i]!=a[1][i])
							{
								if(dif==2)
								{
									dif++;
									flag=1;break;
								}
								else if(dif==0)
								{
									dif++;
									ap=(t[i]-a[1][i]+10)%10;
								}
								else if(dif==1)
								{
									dif++;
									if((t[i]-a[1][i]+10)%10!=ap)
									{
										flag=1;break;
									}
								}
							}
						}
						if(dif==2&&!flag)
						{
							for(int i=2;i<=4;i++)
							{
								if(a[1][i]!=t[i]&&a[1][i-1]==t[i-1]&&a[1][i+1]==t[i+1])
								{
									flag=1;break;
								}
							}
						}
						if(flag||dif==0||t[1]!=a[1][1]&&t[5]!=a[1][5])
						{
							flag=1;
							continue;
						}
						for(int j=2;j<=n;j++)
						{
							flag=0;
							dif=0,ap=0;
							for(int i=1;i<=5;i++)
							{
								if(t[i]!=a[j][i])
								{
									if(dif==2)
									{
										flag=1;break;
									}
									else if(dif==0)
									{
										dif++;
										ap=(t[i]-a[j][i]+10)%10;
									}
									else if(dif==1)
									{
										dif++;
										if((t[i]-a[j][i]+10)%10!=ap)
										{
											flag=1;break;
										}
									}
								}
							}
							if(dif==2)
							{
								for(int i=2;i<=4;i++)
								{
									if(a[j][i]!=t[i]&&a[j][i-1]==t[i-1]&&a[j][i+1]==t[i+1])
									{
										flag=1;break;
									}
								}
							}
							if(flag||dif==0||t[1]!=a[j][1]&&t[5]!=a[j][5])
							{
								flag=1;
								break;
							}
						}
						if(!flag) 
						{
							ans++;
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}