#include <iostream>

using namespace std;

bool check(string s)
{
	while(s.size())
	{
		bool flag=false;
		for(int i=0;i<s.size()-1;i++)
		{
			if(s[i]==s[i+1])
			{
				s.erase(i,2);
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	int n;
	string s;
	cin>>n>>s;

	s='-'+s;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		string tmp="";
		for(int j=i;j<=n;j++)
		{
			tmp+=s[j];
			if(check(tmp))
			{
				res++;
			}
		}
		if(double(clock())/CLOCKS_PER_SEC>=0.95)
		{
			break;
		}
	}

	cout<<res<<endl;

	return 0;
}