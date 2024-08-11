#include<bits/stdc++.h>
using namespace std;

const int N=1e9+5;
bool v[N];

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	int ans1;
	memset(v,0,sizeof(v));
	int sq=n;
	while(sq>0)
	{
		cnt++;
		int x=0;
		for(int i=1;i<=n;i++)
		{
			if(v[i]==0)
			{
				x=(x+1)%3;
				if(x==1) 
				{
					v[i]=1;
					sq--;
					if(i==n) ans1=cnt;
				}
				
			}
		}
	}
	cout<<cnt<<" "<<ans1<<endl;
	return 0;
}