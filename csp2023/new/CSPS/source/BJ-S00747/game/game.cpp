#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int n;
namespace solve
{
	const int N=8000+5;
	string s;
	bitset<N> f[N];
	void main()
	{
		cin>>s;
		s='.'+s;
		for(int i=1;i<n;++i) f[i][i+1]=(s[i]==s[i+1]);
		for(int len=4;len<=n;len+=2)
		{
			for(int l=1;len+l-1<=n;++l)
			{
				int r=l+len-1;
				//if(l==5&&r==8) cout<<len<<endl;
				if(f[l+1][r-1]&&s[l]==s[r])
				{
					f[l][r]=1;
					continue;
				}
				for(int mid=l+1;mid<r;mid+=2)
				{
					//if(l==1&&r==8)
					//{
						//cout<<len<<endl;
						//cout<<":::"<<f[l][mid]<<" "<<f[mid+1][r]<<endl;
						//break
					//}
					if(f[l][mid]&&f[mid+1][r])
					{
						f[l][r]=1;
						break;
					}
				}
			}
		}
		ll ans=0;
		for(int l=1;l<=n;++l)
		{
			for(int r=l;r<=n;++r)
			{
				//if(f[l][r]) cout<<l<<" "<<r<<endl;
				ans+=f[l][r];
			}
		}
		cout<<ans<<'\n';
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	solve::main();
	return 0;
}
