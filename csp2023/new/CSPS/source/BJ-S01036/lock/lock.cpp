#include<bits/stdc++.h>
using namespace std;
int arr[10];
int brr[100000],crr[100000];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	int x=1,y=1;
	int num,num2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin>>arr[j];
		}
		if(n==1)cout<<81;
		if(n==2)
		{
			if(i==1)
			{
				for(int k=1;k<=5;k++)
				{
					for(int h=1;h<=9;h++)
					{
						num=arr[k]+h;
						num2=arr[k+1]+h;
						if(arr[k]+h>9)num=arr[k]+h-10;
						if(arr[k+1]+h>9)num2=arr[k]+h-10;
						if(k==1)
						{
							brr[x]=num*10000+arr[2]*1000+arr[3]*100+arr[4]*10+arr[5]*1;
							x++;
							brr[x]=num*10000+num2*1000+arr[3]*100+arr[4]*10+arr[5]*1;
							x++;
						}
						if(k==2)
						{
							brr[x]=num*1000+arr[1]*10000+arr[3]*100+arr[4]*10+arr[5]*1;
							x++;
							brr[x]=num*1000+num2*100+arr[1]*10000+arr[4]*10+arr[5]*1;
							x++;
						}
						if(k==3)
						{
							brr[x]=num*100+arr[1]*10000+arr[2]*1000+arr[4]*10+arr[5]*1;
							x++;
							brr[x]=num*100+num2*10+arr[1]*10000+arr[2]*1000+arr[5]*1;
							x++;
						}
						if(k==4)
						{
							brr[x]=num*10+arr[1]*10000+arr[2]*1000+arr[3]*100+arr[5]*1;
							x++;
							brr[x]=num*10+num2*1+arr[1]*10000+arr[2]*1000+arr[3]*100;
							x++;
						}
						if(k==5)
						{
							brr[x]=num*1+arr[1]*10000+arr[2]*1000+arr[3]*100+arr[4]*10;
							x++;
						}
					}
				}
			}
			if(i==2)
			{
				for(int k=1;k<=5;k++)
				{
					for(int h=1;h<=9;h++)
					{
						num=arr[k]+h;
						num2=arr[k+1]+h;
						if(arr[k]+h>9)num=arr[k]+h-10;
						if(arr[k+1]+h>9)num2=arr[k]+h-10;
						if(k==1)
						{
							crr[y]=num*10000+arr[2]*1000+arr[3]*100+arr[4]*10+arr[5]*1;
							y++;
							crr[y]=num*10000+num2*1000+arr[3]*100+arr[4]*10+arr[5]*1;
							y++;
						}
						if(k==2)
						{
							crr[y]=num*1000+arr[1]*10000+arr[3]*100+arr[4]*10+arr[5]*1;
							y++;
							crr[y]=num*1000+num2*100+arr[1]*10000+arr[4]*10+arr[5]*1;
							y++;
						}
						if(k==3)
						{
							crr[y]=num*100+arr[1]*10000+arr[2]*1000+arr[4]*10+arr[5]*1;
							y++;
							crr[y]=num*100+num2*10+arr[1]*10000+arr[2]*1000+arr[5]*1;
							y++;
						}
						if(k==4)
						{
							crr[y]=num*10+arr[1]*10000+arr[2]*1000+arr[3]*100+arr[5]*1;
							y++;
							crr[y]=num*10+num2*1+arr[1]*10000+arr[2]*1000+arr[3]*100;
							y++;
						}
						if(k==5)
						{
							crr[y]=num*1+arr[1]*10000+arr[2]*1000+arr[3]*100+arr[4]*10;
							y++;
						}
					}
				}
				x--,y--;
				for(int j=1;j<=x;j++)
				{
					for(int k=1;k<=y;k++)
					{
						if(brr[j]==crr[k])
						{
							cnt++;
							//cout<<brr[j]<<endl;
							break;
						}
					}
				}
				cout<<cnt;
			}
			//x--,y--;
			/**/
			//cout<<cnt;
		}
	}
	//cout<<y;
	return 0;
}
