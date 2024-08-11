#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int c,t,n,m,data[100005],tmp,tmp2;
char v;
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(data,0,sizeof(data));
		int cnt=0;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>v;
			if(v=='T')
			{
				cin>>tmp;
				if(data[tmp]==1) cnt--;
				data[tmp]=0;
			}
			else if(v=='U')
			{
				cin>>tmp;
				if(data[tmp]!=1) cnt++;
				data[tmp]=1;
			}
			else if(v=='F')
			{
				cin>>tmp;
				if(data[tmp]==1) cnt--;
				data[tmp]=2;
			}
			else if(v=='+')
			{
				bool f=true;
				cin>>tmp>>tmp2;
				if(data[tmp]==1) f=false;
				data[tmp]=data[tmp2];
				if(data[tmp]==1 && f) cnt++;
			}
			else
			{
				cin>>tmp>>tmp2;
				data[tmp]=2-data[tmp2];
			}
		}
		cout<<cnt<<endl;
	}
	return 0;	
}