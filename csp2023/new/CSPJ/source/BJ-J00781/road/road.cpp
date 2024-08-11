#include<bits/stdc++.h>
using namespace std;
long long n,dis[100010],v[100010],mn=INT_MAX,aim,cdis[100010],tmp,a[100010],q=1,cadis[100010];
long long sum;
double c,oil;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> c;
	for(int i=2;i<=n;i++)
	cin >> dis[i];
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cdis[i]+=dis[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin >> v[i];
		if(v[i]<mn)
		{
			if(i!=1)
			{
				cadis[q]=cdis[aim]-cdis[i];
				q++;
				a[q]=i;
			}
			else
			{
				a[q]=i;
			}
			mn=v[i];
			aim=i;
		}
	}
	cadis[q]=cdis[aim];
	for(int i=1;i<=q;i++)
	{
		sum+=ceil(ceil(cadis[i]/c)-oil)*v[a[i]];
		oil+=ceil(ceil(cadis[i]/c)-oil);
		oil-=cadis[i]/c;
		if(oil>=1)
		{
			sum-=floor(oil)*v[a[i]];
			oil=oil-floor(oil);
		}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}