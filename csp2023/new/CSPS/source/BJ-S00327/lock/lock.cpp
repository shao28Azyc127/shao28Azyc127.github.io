#include <bits/stdc++.h>
using namespace std;
const int N=100000;
int n,a[10][10],b[10];
int dif[10],kk=0;
bool check(int xa,int xb,int ya,int yb)
{
	int da,db,dc,dd;
	if(xa<xb) {
		da=xb-xa;
		db=xa+10-xb;
	}
	else {
		da=xb+10-xa;
		db=xa-xb;
	}
	if(ya<yb) {
		dc=yb-ya;
		dd=ya+10-yb;
	}
	else {
		dc=yb+10-ya;
		dd=ya-yb;
	}
	return ((da!=dc)&&(db!=dd));
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++) 
		for(j=1;j<=5;j++) scanf("%d",&a[i][j]);
	int f;
	int ans=0;
	for(i=0;i<N;i++)
	{
		k=i;
		f=1;
		for(j=0;j<5;j++) {
			b[5-j]=(k%10);
			k/=10;
		}
		for(j=1;j<=n;j++)
		{
			kk=0;
			for(k=1;k<=5;k++)
				if(a[j][k]!=b[k]) dif[++kk]=k;
			if(kk==1) continue;
			else if(kk==2) {
				if(check(a[j][dif[1]],b[dif[1]],a[j][dif[2]],b[dif[2]])||			   
					dif[1]!=dif[2]-1) {
					f=0;
					break;
				}
			}
			else {
				f=0;
				break;
			}
		}
		if(f) {
			++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}