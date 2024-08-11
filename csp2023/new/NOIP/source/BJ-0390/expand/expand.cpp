#include <iostream>
using namespace std;
const int N=5e5+5;
int c,n,m,q;
int x[N],y[N];
int fx[N],fy[N];
int tmpx[N],tmpy[N];
int cx[N],cy[N];
bool p[100000005];
void chec(int d,int k)
{
	bool p1=1,p2=1;
	int ix=0,jy=0;
	for(int i=1;i<=n;i++)
	{
		//cout << fx[i] << " ";
		for(int j=1;j<=fx[i];j++)
		{
			ix++;
			tmpx[ix]=cx[i];
		}
	}
	//cout << endl;
	for(int i=1;i<=m;i++)
	{
		//cout << fy[i] << " ";
		for(int j=1;j<=fy[i];j++)
		{
			jy++;
			tmpy[jy]=cy[i];
		}
	}
	//cout << endl << endl;
	if(ix!=jy)
	{
		return;
	}
	for(int i=1;i<=ix;i++)
	{
		if(tmpx[i]<=tmpy[i])
		{
			p1=0;
		}
		if(tmpx[i]>=tmpy[i])
		{
			p2=0;
		}
	}
	/*for(int i=1;i<=ix;i++)
	{
		cout << tmpx[i] << " ";
	}
	cout << endl ;
	for(int i=1;i<=ix;i++)
	{
		cout << tmpy[i] << " ";
	}
	cout << endl << endl;*/
	if(p1==1||p2==1)
	{
		p[k]=1;
	}
	return;
}
void dff(int ddd,int k)
{
	if(ddd==m)
	{
		chec(ddd,k);
		return;
	}
	for(int i=1;i<=m;i++)
	{
		fy[ddd+1]=i;
		dff(ddd+1,k);
	}
}
void checks(int k)
{
	dff(0,k);
	return;
}
void dfs(int dd,int k)
{
	if(dd==n)
	{
		checks(k);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		fx[dd+1]=i;
		dfs(dd+1,k);
	}
	return;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin >> c >> n >> m >> q;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		cx[i]=x[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&y[i]);
		cy[i]=y[i];
	}
	if((cx[1]>cy[1]&&cx[n]<cy[m])||(cx[1]<cy[1]&&cx[n]>cy[m])||(cx[1]==cy[1]||cx[n]==cy[m]))
	{
		cout << 0;
	}
	else
	{
		dfs(0,0);
		cout << p[0];
	}
	int cnt=0;
	while(q--)
	{
		cnt++;
		int kx,ky,a,b;
		for(int i=1;i<=n;i++)
		{
			cx[i]=x[i];
		}
		for(int i=1;i<=m;i++)
		{
			cy[i]=y[i];
		}
		cin >> kx >> ky;
		for(int i=1;i<=kx;i++)
		{
			cin >> a >> b;
			cx[a]=b;
		}
		for(int i=1;i<=ky;i++)
		{
			cin >> a >> b;
			cy[a]=b;
		}
		if((cx[1]>cy[1]&&cx[n]<cy[m])||(cx[1]<cy[1]&&cx[n]>cy[m])||(cx[1]==cy[1]||cx[n]==cy[m]))
		{
			cout << 0;
		}
		else
		{
			dfs(0,cnt);
			cout << p[cnt];
		}
	}
	return 0;
}
