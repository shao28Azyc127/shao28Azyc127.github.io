#include<bits/stdc++.h>
using namespace std;
int n,m,c,t,y,z;
int x[100005],xn[100005],vis[100005];
void ex()
{
	scanf("%d%d",&n,&m);
	char ch,cc[100005];
	int cnt=0,flag=1;
	for(int i=1;i<=m;i++)
	{
		cin>>ch;cc[i]=ch;
		if(ch=='T')scanf("%d",&y),xn[y]=1;
		if(ch=='F')scanf("%d",&y),xn[y]=-1;
		if(ch=='U')scanf("%d",&y),xn[y]=0;
		if(ch=='+')scanf("%d%d",&y,&z),xn[y]=xn[z],flag=0;
		if(ch=='-')scanf("%d%d",&y,&z),xn[y]=-1*xn[z],flag=0;
		vis[y]=1;
	}
	if(flag==0)
	{
		cout<<0<<endl;
		return;
		}
	for(int i=1;i<=n;i++)if(vis[i]==1&&xn[i]==0)cnt++;
	printf("%d\n",cnt);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	memset(x,0,sizeof(x)),memset(xn,0,sizeof(xn)),memset(vis,0,sizeof(vis)),ex();
	return 0;
	}
