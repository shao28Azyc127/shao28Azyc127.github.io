#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,a[N][N];
int f,f1,f2,f3,f4;
long long s;
int check(int x,int y)
{
	if(x==y) return 11;
	if(x!=0&&x!=9) 
	{
		return x-y;
	}
	else if(x==0)
	{
		if(y==9) return y-x;
		else if(x<y) return y-x;
	}
	else
	{
		if(y==0) return x-y;
		else if(x>y) return x-y;
	}
	return 0;
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) cin>>a[i][j];
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				for(int l=0;l<=9;l++)
				{
					for(int m=0;m<=9;m++)
					{
						for(int p=1;p<=n;p++)
						{
							f=f1=f2=f3=f4=0;
							for(int o=1;o<=5;o++)
							{
								if(o==1) {if(check(a[p][o],i)==11) continue;if(check(a[p][o],i)) f=check(a[p][o],i);if(!check(a[p][o],i)){f3=1;break;}}
								else if(o==2) 
								{
									if(check(a[p][o],j)==11) 
									{
										if(f!=0) f4=1;
										continue;
									}
									if(check(a[p][o],j)&&f==check(a[p][o],j)) f1=1,f4=1;
									else if(check(a[p][o],j)&&f!=check(a[p][o],j)&&f!=0){f3=1;break;}
									else if(check(a[p][o],j)) f=check(a[p][o],j); 
									if(!check(a[p][o],j)){f3=1;break;}
								}
								else if(o==3)
								{
									if(check(a[p][o],k)==11)
									{
										if(f!=0) f4=1;
										continue;
									}
									else if(check(a[p][o],k)&&f4==1)
									{
										f3=1;
										break;
									}
									else if(check(a[p][o],k)&&((f==check(a[p][o],k))||(check(a[p][o],k)&&f==abs(check(a[p][o],k))&&(((a[p][o-1]==0||a[p][o-1]==9||a[p][o]==0||a[p][o]==9))||(((check(a[p][o],k)&&(10+k-a[p][o]==j-a[p][o-1]))||(10+j-a[p][o-1]==k-a[p][o]))))))) f1=1,f4=1;
									else if(check(a[p][o],k)&&f!=check(a[p][o],k)&&f!=0){f3=1;break;}
									else if(check(a[p][o],k)) f=check(a[p][o],k);
									if(!check(a[p][o],k)){f3=1;break;}
								}
								else if(o==4)
								{
									if(check(a[p][o],l)==11) 
									{
										if(f!=0) f4=1;
										continue;
									}
									else if(check(a[p][o],l)&&f4==1)
									{
										f3=1;
										break;
									}
									else if((check(a[p][o],l)&&f==check(a[p][o],l))||(check(a[p][o],l)&&f==abs(check(a[p][o],l))&&(a[p][o-1]==0||a[p][o-1]==9||a[p][o]==0||a[p][o]==9))||(check(a[p][o],k)&&((10+l-a[p][o]==k-a[p][o-1])||(10+k-a[p][o-1]==l-a[p][o])))) f1=1,f4=1;
									else if(check(a[p][o],l)&&f!=check(a[p][o],l)&&f!=0){f3=1;break;}
									else if(check(a[p][o],l)) f=check(a[p][o],l);
									if(!check(a[p][o],l)){f3=1;break;}
								}
								else if(o==5)
								{
									if(check(a[p][o],m)==11) continue;
									else if(check(a[p][o],m)&&f4==1)
									{
										f3=1;
										break;
									}
									else if((check(a[p][o],m)&&f==check(a[p][o],m))||(check(a[p][o],m)&&f==abs(check(a[p][o],m))&&(a[p][o-1]==0||a[p][o-1]==9||a[p][o]==0||a[p][o]==9))||(check(a[p][o],k)&&((10+m-a[p][o]==l-a[p][o-1])||(10+l-a[p][o-1]==m-a[p][o])))) f1=1,f4=1;
									else if(check(a[p][o],m)&&f!=check(a[p][o],m)&&f!=0){f3=1;break;}
									else if(check(a[p][o],m)) f=check(a[p][o],m);
									if(!check(a[p][o],m)){f3=1;break;}
								}
							}
							if(f3==1||(f==0&&f1==0)) 
							{
								f2=1;
								break;
							}
						}
						if(f2==0) s++;
					}
				}
			}
		}
	}
	cout<<s;
}
