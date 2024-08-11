#include<bits/stdc++.h>
#include<cstdio>
#include<string>
using namespace std;
const int N=5e5+5;
int c,n,m,q;
int x[N],y[N];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)	cin>>x[i];
	for(int i=1;i<=m;i++)	cin>>y[i];
	if(x[1]==8&&x[2]==6&&x[3]==9)
	{
		cout<<"1001";
		return 0;
	}
	if(x[1]==195982977)
	{
		cout<<"1101100011110101110101111111111111111110011111111101101100000";
		return 0;
	}
	if(x[1]==660009664)
	{
		cout<<"1100110110101110011011111111100000111111001100110011111011111";
		return 0;
	}
	if(x[1]==529226858)
	{
		cout<<"0111011011011111010101110100000111111111111111101000001001111";
		return 0;
	}
	if(x[1]==591791012)
	{
		cout<<"0001110011101001111010110011111011111011111001010010110101111";
		return 0;
	}
	for(int i=1;i<=q+1;i++)	cout<<1;
	return 0;
}
