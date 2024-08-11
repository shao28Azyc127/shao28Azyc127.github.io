#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int n;
string s[9];
int dis(int a,int b)
{
	if(a>=b) return a-b;
	if(a<b) return 10+a-b;
}
bool check(int a,int b,int c,int d)
{   
	if (a==b or c==d) return 0;
	if(dis(a,b) == dis(c,d) )return 1;return 0;
}
bool judge(string a,string b)
{
	int fg =0,fg2=0;;
	for(int i=0;i<=4;i++)
	{
		if (a[i] == b[i]) {fg2 ++;continue;}
		if (i>0 and check(a[i]-'0',b[i]-'0',a[i-1]-'0',b[i-1]-'0')) fg++;
	}
	//cout << fg2 << fg ;
	if (fg2 ==4 or (fg2==3 and fg ==1)) return 1;return 0;

}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ll ans = 0;
	
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j =0;j<5;j++)
		{int tmp;
		cin >> tmp;
		s[i].push_back('0'+tmp);}
		
	}
	for(int i=0;i<=99999;i++)
	{
		string s2 = to_string(i);
		string s1;
		for(int k=0;k<(5-s2.size());k++)
		{
			s1.push_back('0');
		}
		s1 =s1+s2;
		int fg =1;
		for(int j=1;j<=n;j++)
		{
			
			if(!judge(s1,s[j]))
			{
				fg=0;
				//cout << s1 << " " << s[j] << endl;;
			}
		}
		if(fg) ans ++;
	}
	cout << ans;
	return 0;
}