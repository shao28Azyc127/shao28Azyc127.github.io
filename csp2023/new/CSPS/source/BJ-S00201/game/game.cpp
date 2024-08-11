#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int cnt=0;
	cin>>n;
	cin>>s;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]==s[i-1]&&s[i-1]!='M')
		{
			cnt++;
			s.erase(i-1,2);
			s.insert(i-1,"M");
			if(i>0)
			{
				while(s[i-1]=='M'&&s[i-2]==s[i])
				{
					cnt++;
					s.erase(i,1);
					s.erase(i-2,1);
				}
			}
			i--;
		}
	}
	int tmp=0,x=0;
	while(tmp<s.size())
	{
		if(s[tmp]=='M')
		{
			x++;
		}
		else if(x!=0)
		{
			cnt+=((x*(x-1))/2);
			x=0;
		}
		tmp++;
	}
	if(x!=0)
	{
		cnt+=((x*(x-1))/2);
		x=0;
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}