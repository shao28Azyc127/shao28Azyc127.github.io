#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,ans;
bool vis[1005];
int org[1005];
struct node
{
	int index=0;
	bool con=true;	
} a[100005];
node search(node x)
{
	node ans;
	return ans;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++)
		{
			ans=0;
			memset(org,0,sizeof(org));
			memset(vis,false,sizeof(vis));
			cin>>n>>m;
			for(int i=1;i<=m;i++) 
			{
				
				char op;
				int ind1,ind2;
				cin>>op;
				if(op=='+')
				{
					cin>>ind1>>ind2;
					if(a[ind2].index) a[ind1]=a[ind2];
					else
					{
						a[ind1].index=ind2;
						a[ind1].con=true;
						vis[ind1]=true;
					}
					if(org[ind2]==-1) ans++;
				}
				if(op=='-')
				{
					cin>>ind1>>ind2;
					if(a[ind2].index)
					{
						a[ind1]=a[ind2];
						a[ind1].con=!a[ind2].con;
					} 
					else
					{
						a[ind1].index=ind2;
						a[ind1].con=false;
					}
				}
				if(op=='U')
				{
				scanf("%d",&ind1);
				org[ind1]=-1;
				vis[ind1]=true;
				if(c==3||c==4) ans++;
			}
				if(op=='F')
				{
				scanf("%d",&ind1);
				org[ind1]=0;
			}
				if(op=='T')
				{
				scanf("%d",&ind1);
				org[ind1]=1;
				}
			}
	if(c==1||c==2)
	{
		//for(int i=1;i<=n;i++) printf("%d ",a[i].index);
		//printf("\n");
		for(int i=1;i<=n;i++) if(a[i].index==i&&a[i].con==false)
		{
			org[i]=-1;
			ans++;
		}
		for(int i=1;i<=n;i++)
		{
			if(org[a[i].index]==-1&&org[i]!=-1) ans++;
		}
		printf("%d\n",ans);
	}
	if(c==3||c==4) printf("%d\n",ans);
	if(c==5||c==6)
	{
		
		//for(int i=1;i<=n;i++) printf("%d ",a[i].index);
		//printf("\n");
		printf("%d\n",ans);
	}
	if(c==7||c==8)
	{
		//for(int i=1;i<=n;i++) printf("%d ",a[i].index);
		//printf("\n");
		for(int i=1;i<=n;i++) if(a[i].index==i&&a[i].con==false)
		{
			org[i]=-1;
			ans++;
		}
		for(int i=1;i<=n;i++)
		{
			if(org[a[i].index]==-1&&org[i]!=-1) ans++;
		}
		printf("%d\n",ans);
	}
	if(c==9||c==10)
	{
		
	}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
