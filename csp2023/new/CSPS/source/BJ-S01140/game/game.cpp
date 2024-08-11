#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string s,tmp,last;
int n,cnt;
bool check(int x,int y)
{
	tmp=s;
	last="a";
	tmp.erase(y+1,n-y-1);
	tmp.erase(0,x);
	//cout<<x<<" "<<y<<" "<<tmp<<endl;
	while(tmp.size())
	{
		for(int i=0;i<tmp.size();++i)
		{
			if(tmp[i]==tmp[i+1])
			{
				tmp.erase(i,2);
				i-=2;
			}
		}
		if(tmp==last) return false;
		last=tmp;
	}
	return true;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>s;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;j+=2)
			if(check(i,j)) ++cnt;
	cout<<cnt;
	return 0;
}