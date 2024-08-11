#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
int n;
int a[10][10];
bool s[100000];
int flag=0;
int cnt=0;
int pos[6];
int checkeq(int x,int y)
{
	int cnt=0;
	for(int i=0;i<=5;i++) pos[i]=0;
	for(int i=5;i>=1;i--)
	{
		if(x%10==a[y][i])
		{
			cnt++;
			pos[i]=1;
		}
		x/=10;
	}
	if(cnt<3||cnt==5)
	{
		return -1;
	}
	else if(cnt==4)
	{
		return 4;
	}
	else if(cnt==3)
	{
		if((pos[1]==0&&pos[2]==0)||(pos[2]==0&&pos[3]==0)||(pos[3]==0&&pos[4]==0)||(pos[4]==0&&pos[5]==0))
		    return 3;
		else 
		    return -1;
	}
	else 
	    return -1;
}
bool checkdeg(int x,int y)
{
	int dif=0;
	for(int i=5;i>=1;i--)
	{
		if(x%10!=a[y][i])
		{
			if(dif!=0)
			{
				if(dif==(x%10)-a[y][i] || dif==(x%10)-a[y][i]-10 || dif==(x%10)-a[y][i]+10)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				dif=(x%10)-a[y][i];
			}
		}
		x/=10;
	}
	return false;
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	    scanf("%d%d%d%d%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4],&a[i][5]);
	}
	for(int i=0;i<=99999;i++)
	{
		s[i]=true;
		for(int j=1;j<=n;j++)
		{
			flag=checkeq(i,j);
			if(flag==-1)
			{
				s[i]=false;
			}
			else 
			{
				if(flag==4)
			    {
			    	s[i]=true;
			    }
			    if(flag==3)
			    {
			    	s[i]=checkdeg(i,j);
			    }
			}
			
			if(!s[i])break;
		}
	}
	for(int i=0;i<=99999;i++)
	{
		if(s[i]==true)
		    cnt++;
	}
	cout<<cnt;
    return 0;
}
