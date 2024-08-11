#include<bits/stdc++.h>
using namespace std;
int n,m,a[3005],kk=0;
char c[3005][3005];
struct node
{
	char ch[3005];
	int x;
}cmin[3005],cmax[3005],nm1,nm2;

node ck(node n1,node n2)
{
	if(n1.x==0)return n2;
	for(int i=1;i<=m;i++)
	{
		if(n1.ch[i]>n2.ch[i])return n2;
		if(n1.ch[i]<n2.ch[i])return n1;
	}
	node huh;
	huh.x=-1;
	return(huh);
}
int cmpmin(char c1,char c2)
{
	if(c1<c2)return 1;
	return 0;
}
int cmpmax(char c1,char c2)
{
	if(c1>c2)return 1;
	return 0;
}
int cmp(node n1,node n2)
{
	if(ck(n1,n2).x==n1.x)return 1;
	return 0;
}
int main()
{	
	nm1.x=nm2.x=0;
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n<=1)
	{
		cout<<1;
		return 0;
	}
	scanf("%c",&c[0][0]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%c",&c[i][j]);
			cmin[i].ch[j]=cmax[i].ch[j]=c[i][j];
			cmin[i].x=cmax[i].x=i;
			//cin>>c[i][j];
		}
		scanf("%c",&c[0][0]);
	}
	if(m<=1)
	{
		int k;
		for(int i=1;i<=n;i++)
		{
			k=1;
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				if(c[i][1]>=c[j][1]){cout<<0;k=0;break;}
			}
			if(k==1)
			cout<<1;
		}
		return 0;
	}
	if(m<=2)
	{
		for(int i=1;i<=n;i++)
		{
			int k=1;
			if(c[i][1]>c[i][2])swap(c[i][1],c[i][2]);
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				if(c[j][1]<c[j][2])swap(c[j][1],c[j][2]);
				if(c[i][1]>c[j][1]||(c[i][1]==c[j][1]&&c[i][2]>=c[j][2]))
				{
					cout<<0;
					k=0;
					break;
				}
			}
			if(k==1)
			cout<<1;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		sort(cmin[i].ch+1,cmin[i].ch+m+1,cmpmin);
		sort(cmax[i].ch+1,cmax[i].ch+m+1,cmpmax);
		int l=ck(nm1,cmax[i]).x;
		if(l==-1||l==cmax[i].x)
		{
			for(int j=1;j<=m;j++)nm2.ch[j]=nm1.ch[j];
			nm2.x=nm1.x;
			for(int j=1;j<=m;j++)nm1.ch[j]=cmax[i].ch[j];
			nm1.x=cmax[i].x;
			continue;
		}
		if(ck(nm2,cmax[i]).x==cmax[i].x)
		{
			for(int j=1;j<=m;j++)nm2.ch[j]=cmax[i].ch[j];
			nm2.x=cmax[i].x;
		}
	}
	sort(cmin+1,cmin+n+1,cmp);
	cmin[n+1].ch[1]='z'+10;
	cmin[n+1].x=n+1;
	int l=0,r=n+1,mid;
	int k=0;
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(cmin[mid].x==nm1.x)
		{
			k=ck(cmin[mid],nm2).x;
			if(k==cmin[mid].x)l=mid;
			if(k==nm2.x)r=mid;
			if(k==-1)r=mid;
			continue;
		}
		k=ck(cmin[mid],nm1).x;
		if(k==cmin[mid].x)l=mid;
		if(k==nm1.x)r=mid;
		if(k==-1)r=mid;
	}
	for(int i=1;i<=l;i++)
	{
		if(cmin[i].x==nm1.x)
		{
			if(ck(cmin[i],nm2).x!=cmin[i].x)a[cmin[i].x]=0;
			else a[cmin[i].x]=1;
			continue;
		}
		a[cmin[i].x]=1;
	}
	for(int i=r;i<=n;i++)
	{
		if(cmin[i].x==nm1.x)
		{
			if(ck(cmin[i],nm2).x!=cmin[i].x)a[cmin[i].x]=0;
			else a[cmin[i].x]=1;
			continue;
		}
		a[cmin[i].x]=0;
	}
	
	
	/*for(int i=1;i<=n;i++)
	{
		if(cmin[i].x==nm1.x)
		{
			if(ck(cmin[i],nm2).x!=cmin[i].x)a[cmin[i].x]=0;
			else a[cmin[i].x]=1;
			continue;
		}
		if(ck(cmin[i],nm1).x!=cmin[i].x)a[cmin[i].x]=0;
		else a[cmin[i].x]=1;
	}*/
	for(int i=1;i<=n;i++)printf("%d",a[i]);
	return 0;	
	}
