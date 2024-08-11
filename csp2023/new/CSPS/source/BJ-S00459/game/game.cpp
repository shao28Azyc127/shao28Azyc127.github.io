#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
int n,k;
char s[1000005];
int main() //区间dp,忘了 用括号配对试试
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	int cnt=0,rec=0;
	char stk[1000005];
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			stk[k]=s[i];
		}
		else
		{
			if(s[i]==stk[k])
			{
				rec=1;
				k--;
				i++;
				cnt++;
				while(i+1<n&&stk[k]==s[i])
				{
					cnt+=1+rec;
					rec++;
					k--;
					i++;
				}
			}
			k++;
			stk[k]=s[i];
		}
	}
	cout<<cnt+1;
	return 0;
}
