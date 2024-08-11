#include<iostream>
#include<cstring>
using namespace std;
inline bool solve(int *a,int *b,int n,int m)
{
	if(a[1]>=b[1])
	{
		return 0;
	}
	static int maxa[500010],mina[500010];
	maxa[n+1]=-1,mina[n+1]=1e9;
	for(int i=n;i;i--)
	{
		maxa[i]=max(maxa[i+1],a[i]);
		mina[i]=min(mina[i+1],a[i]);
	}
	static int maxb[500010];
	maxb[m+1]=-1;
	for(int i=m;i;i--)
	{
		maxb[i]=max(maxb[i+1],b[i]);
	}
	int i=1,j=1,maxx=b[1],p=1;
	for(;mina[i+1]==mina[1];i++)
	{
		while(j<m&&b[j+1]>a[i])
		{
			if(b[++j]>maxx)
			{
				maxx=b[p=j];
			}
		}
		if(maxx<=a[i])
		{
			return 0;
		}
	}
	for(j=p;i<=n;i++)
	{
		if(b[j]<=a[i])
		{
			return 0;
		}
		if(mina[i]==mina[i+1])
		{
			continue;
		}
		while(j<m&&maxb[j+1]>maxa[i])
		{
			if(b[++j]<=a[i])
			{
				return 0;
			}
		}
	}
	return j==m;
}
int Task,n,m,q,a[500010],b[500010],A[500010],B[500010];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>Task>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	cout<<(a[1]<b[1]?solve(a,b,n,m):solve(b,a,m,n));
	while(q--)
	{
		memcpy(A,a,sizeof(A));
		memcpy(B,b,sizeof(B));
		int k1,k2;
		cin>>k1>>k2;
		while(k1--)
		{
			int x,y;
			cin>>x>>y;
			A[x]=y;
		}
		while(k2--)
		{
			int x,y;
			cin>>x>>y;
			B[x]=y;
		}
		cout<<(A[1]<B[1]?solve(A,B,n,m):solve(B,A,m,n));
	}
	cout<<endl;
	return 0;
}