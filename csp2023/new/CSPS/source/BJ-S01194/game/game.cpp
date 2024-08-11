#include<bits/stdc++.h>
using namespace std;
string a;
long long b[2000010];
int num,k,j;
bool vis[200];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,i;
	cin>>n;
	cin>>a;
	for(i=1;i<=n;i++)
		b[i]=a[i]-'a';
	for(i=1;i<=n;i++)
	{
		if(b[i]==b[i+1]){
			num++;
			for(j=1;j<=n;j++)
			{
				if(b[i-j]==b[i+2+j])
					num++;
			}
		}
	}
	cout<<num-1;
	return 0;
}	