#include <iostream>
using namespace std;
char l[2000000];
char temp[2000000];
bool find(int st, int len)
{
	for(int i = 0; i < len; i++)
	{
		temp[i]=l[i + st];
	}
	for(int k = 0; k < len/2;k++)
	{
		for(int i = 0; i < len - 1; i++)
		{
			int t = i + 1;
			while (temp[t]=='*') t++;
			if(t >= len) break;
			if(temp[i]==temp[t])
			{
				temp[i]='*'; temp[t] = '*';
			}
		}
	}
	for(int  i = 0; i < len; i++)
	{
		if(temp[i]!='*') return false;
	}
	return true;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> l[i];
	}
	int sum = 0;
	for(int i = 2; i <= n; i+=2)
	{
		
		for(int  j = 0; j <= n - i; j++)
		{
			if (find(j,i))
			{
				 sum++;
			 }
		}
	}
	cout << sum;
	return 0;
}
