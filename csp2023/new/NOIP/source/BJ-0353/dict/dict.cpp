#include<bits/stdc++.h>
using namespace std;
int n,m;
struct book
{
	int id;
	char ch[3005];
} b[3005];
struct sp
{
	int id;
	char ch; 
} spb[50];
int ans[3005];
bool cmp1(char x,char y)
{
	return (int)x<(int)y;
}
bool cmp2(book x,book y)
{
	int ind=0;
	while(ind++<m)
	{
		if(x.ch[ind]==y.ch[ind]) continue;
		return x.ch[ind]<y.ch[ind];
	}
	return true;
	
}
bool cmp3(sp x,sp y)
{
	return x.ch<y.ch;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(m>1)
	{
		for(int i=1;i<=n;i++)
	{
		cin>>b[i].ch;
		sort(b[i].ch,b[i].ch+m,cmp1);
		b[i].id=i;
	}
	sort(b+1,b+n+1,cmp2);
	int minn=1;
	ans[b[1].id]++;
	for(int i=2;i<=n;i++)
	{
		if(b[i].ch[0]<b[minn].ch[m-1]) ans[b[i].id]++;
		if(b[i].ch[m-1]<b[minn].ch[m-1]) minn=i;
		//cout<<b[i].ch<<endl;
		
	}
	for(int i=1;i<=n;i++) printf("%d",ans[i]);
	}
	else 
	{
		int minc=int('z'+1);
		int f=0;
		for(int i=1;i<=n;i++)
		{
			cin>>spb[i].ch;
			spb[i].id=i;
			
		}
		for(int i=1;i<=n;i++)
		{
			if((int)spb[i].ch<minc)
			{
				f=spb[i].id;
				minc=(int)spb[i].ch;
			} 
		}
		ans[f]++;
		for(int i=1;i<=n;i++) printf("%d",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
