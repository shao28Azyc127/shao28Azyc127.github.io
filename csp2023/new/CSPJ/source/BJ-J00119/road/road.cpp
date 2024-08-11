#include<bits/stdc++.h>
using namespace std;
long long jl[1000002],yq[1000002];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,d,y=0,z=1,j,k=1,f,yy=0;
	cin>>n>>d;
	for(int i=1;i<=n-1;i++)
		cin>>jl[i];
	for(int i=1;i<=n;i++)
		cin>>yq[i];
	while(z<n)
	{
		j=jl[z];
		k=1;
		for(int i=z+1;i<=n-1;i++)
		{
			if(yq[i]>yq[z])
			{
				j+=jl[i];
				k++;
			}
			else
				break;
		}
		j-=yy;
		if(j%d==0)
			f=j/d;
		else
			f=(j/d)+1;
//		f=floor((j*1.0)/(d*1.0));
		y+=f*yq[z];
		yy=f*d-j;
		z+=k;
	}
	cout<<y;
	return 0;
}