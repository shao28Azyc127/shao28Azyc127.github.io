#include<iostream>
#include<cstdio>
using namespace std;

int p[10][6];
int n;
int a[6];

bool Check_()
{
	for(int i=1;i<=n;i++)
	{
		int fd=0;
		for(int j=1;j<=5;j++) if(a[j]!=p[i][j]) {fd=j; break;}
		if(fd==0) return 0;
		if(fd==5) continue;
		int dif1=p[i][fd]-a[fd];
		fd++;
		int dif2=p[i][fd]-a[fd];
		int dif=dif1-dif2;
		if(dif!=10&&dif!=0&&dif!=-10&&dif2!=0) return 0;
		for(++fd;fd<=5;fd++) if(a[fd]!=p[i][fd]) return 0;
	}
	return 1;
}

int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++) cin>>p[i][j];
	int ans=0;
	for(a[1]=0;a[1]<=9;a[1]++)
		for(a[2]=0;a[2]<=9;a[2]++)
			for(a[3]=0;a[3]<=9;a[3]++)
				for(a[4]=0;a[4]<=9;a[4]++)
					for(a[5]=0;a[5]<=9;a[5]++)
						if(Check_()) ans++;
	cout<<ans;
	return 0;
}
