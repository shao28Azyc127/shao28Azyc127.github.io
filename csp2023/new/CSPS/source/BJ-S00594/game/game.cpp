#include<bits/stdc++.h>
using namespace std;
struct Ret{
	bool broken;
	int val;
};
string s;
int n;
//bool dp[8001][8001];//dp[i][j] refers that substr[i,j] can be broken
string erase(string a,int l,int r)
{
	int len=a.length();
	string ret="";
	for(int i=0;i<len;i++)
	{
		if(i<l||i>r)ret+=a[i];
	}
	return ret;
}
bool check(string str)
{
	if(str.length()==2)return str[0]==str[1];
	while(str.length()>0)
	{
		bool flag=0;
		int len=str.length();
		for(int i=0;i+1<len;i++)
		{
			//cout << str.substr(i,2) << "   substr\n";
			if(check(str.substr(i,2)))
			{
				if(erase(str,i,i+1)=="")return 1;
				str=erase(str,i,i+1);
				flag=1;
				//cout << str << endl;
				break;
			}
		}
		if(flag)continue;
		return 0;
	}
	
	return 1;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		char c=getchar();
		s+=c;
	}
	//cout << s << endl;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			ans+=check(s.substr(i,j-i+1));
		}
	}
	cout << ans;
}
