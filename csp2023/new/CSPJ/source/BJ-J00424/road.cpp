#include<bits/stdc++.h>
using namespace std;
struct station
{
	int id,w,v;
}a[100010],b[100010];
int n,d;
int qzh[100010];
int lx[100010];
bool cmp(station x,station y)
{
	if(x.w != y.w) return x.w < y.w;
	return x.id < y.id;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&d);
	//cout << "end0" << endl;
	for(int i = 1;i <= n-1;i++)
	{
		scanf("%d",&a[i].v);
		b[i].v = a[i].v;
		qzh[i+1] = qzh[i] + a[i].v;
	}
	//cout << "end1" << endl;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i].w);
		b[i].w = a[i].w;
 		a[i].id = i;
		b[i].id = i;
	}
	//cout << "end2" << endl;
	sort(a+1,a+n+1,cmp);
	//for(int i = 1;i <= n;i++)
		//cout << a[i].id << " ";
	//cout << endl;
	int nowi = n,pl = 1,id = 1;
	while(nowi != 1) 
	{
		//cout << pl << " " << a[pl].id << " " << nowi << endl;
		if(a[pl].id < nowi) 
		{
			lx[id++] = a[pl].id; 
			nowi = a[pl].id;
		}
		pl++;
		//cout << nowi << endl;
	}
	id--;
	reverse(lx+1,lx+id+1);
	//for(int i = 1;i <= id;i++)
	//	cout << lx[i] << " ";
	lx[id+1] = n;
	//cout << endl;
	int oil = 0,spend = 0;
	for(int i = 1;i <= id;i++)
	{
		int want = lx[i+1];
		int now = lx[i];
		int dis = 0;
		for(int j = now;j <= want - 1;j++)
			dis += b[j].v;
	//	cout << dis << " ";
		spend += ceil(1.0 * (dis-oil) / d) * b[lx[i]].w;
		oil += ceil(1.0 * dis / d) * d;
		oil -= dis;
	//	cout << spend << endl;
	}
	cout << spend << endl;
	return 0;
}
