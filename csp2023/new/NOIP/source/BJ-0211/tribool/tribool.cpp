//NOIP2023 RP++
#include<iostream>
using namespace std;
const int N=1e5+5;
int c,t,n,m,s,p[N],d[N],l[N];
int func(int x)
{
	if(p[x]==0)	return x;
	if(p[x]==x||d[x])	return x;
	else if(p[x]<0)	return -func(-p[x]);
	else	return func(p[x]);
}
int qfunc(int x)
{
	if(p[x]==x||d[x])	return x;
	else if(p[x]<0)	return qfunc(-p[x]);
	else	return qfunc(p[x]);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==7||c==8)
	{
		while(t--)
		{
			s=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++)
			{
				p[i]=i;
				d[i]=0;
			}
			for(int i=1,x,y;i<=m;i++)
			{
				char op;
				cin>>op>>x;
				if(op=='+')
				{
					cin>>y;
					p[x]=func(y);
				}
				else if(op=='-')
				{
					cin>>y;
					p[x]=-func(y);
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(p[i]==-i)
				{
					d[i]=1;
					s++;
				}
			}
			for(int i=1;i<=n;i++)
			{
				int f=0;
				for(int j=1;j<=n;j++)
				{
					if(d[j]==1)	continue;
					if(d[qfunc(j)]==1)
					{
						d[j]=1;
						s++;
						f++;
					}
				}
				for(int j=n;j>=1;j--)
				{
					if(d[j]==1)	continue;
					if(d[qfunc(j)]==1)
					{
						d[j]=1;
						s++;
						f++;
					}
				}
				if(!f)	break;
			}
			cout<<s<<endl;
		}
	}
	if(c==1||c==2||c==9||c==10)
	{
		while(t--)
		{
			s=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++)
			{
				p[i]=i;
				d[i]=0;
			}
			for(int i=1,x,y;i<=m;i++)
			{
				char op;
				cin>>op>>x;
				if(op=='+')
				{
					cin>>y;
					int q=func(y);
					p[x]=q;
					d[x]=d[q];
				}
				else if(op=='-')
				{
					cin>>y;
					int q=func(y);
					p[x]=-q;
					d[x]=d[q];
				}
				else
				{
					if(op=='T')	p[x]=x,d[x]=2;
					if(op=='F')	p[x]=x,d[x]=2;
					if(op=='U')	p[x]=x,d[x]=1;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(p[i]==-i||d[i]==1)
				{
					d[i]=1;
					s++;
				}
			}
			for(int i=1;i<=n;i++)
			{
				int f=0;
				for(int j=1;j<=n;j++)
				{
					if(d[j])	continue;
					int qf=qfunc(j);
					if(d[qf])
					{
						d[j]=d[qf];
						if(d[j]==1)	s++;
						f++;
					}
				}
				for(int j=n;j>=1;j--)
				{
					if(d[j])	continue;
					int qf=qfunc(j);
					if(d[qf])
					{
						d[j]=d[qf];
						if(d[j]==1)	s++;
						f++;
					}
				}
				if(!f)	break;
			}
			cout<<s<<endl;
		}
	}
	if(c==5||c==6)
	{
		while(t--)
		{
			cin>>n>>m;
			for(int i=1;i<=n;i++)
			{
				p[i]=0;
				d[i]=0;
			}
			for(int i=1,x,y;i<=m;i++)
			{
				char op;
				cin>>op>>x;
				if(op=='+')
				{
					cin>>y;
					int q=func(y);
					p[x]=q;
					d[x]=d[q];
				}
				else	p[x]=x,d[x]=1;
			}
			while(1)
			{
				int f=0;
				for(int j=1;j<=n;j++)
				{
					if(d[j])	continue;
					int qf=func(j);
					if(d[qf])
					{
						d[j]=d[qf];
						f++;
					}
				}
				for(int j=n;j>=1;j--)
				{
					if(d[j])	continue;
					int qf=func(j);
					if(d[qf])
					{
						d[j]=d[qf];
						f++;
					}
				}
				if(!f)	break;
			}
			int ss=0;
			for(int i=1;i<=n;i++)
			{
				if(d[i]==1)	ss++;
			}
			cout<<ss<<endl;
		}
	}
	if(c==3||c==4)
	{
		while(t--)
		{
			s=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++)	l[i]=0;
			for(int i=1,x;i<=m;i++)
			{
				char op;
				cin>>op>>x;
				if(op=='T')	l[x]=2;
				if(op=='F')	l[x]=2;
				if(op=='U')	l[x]=1;
			}
			for(int i=1;i<=n;i++)
			{
				if(l[i]==1)	s++;
			}
			cout<<s<<endl;
		}
	}
	return 0;
}
