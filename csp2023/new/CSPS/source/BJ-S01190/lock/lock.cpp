#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[10][10];
bool t[10][100005];
void zhuan(int x)
{
	int tmp = 0;
	int num = 0;
	int tmp2 = 0;
	for(int i = 1 ; i <= 5 ; i ++)
	{
		for(int j = 1 ; j <= 9 ; j ++)
		{
			tmp = a[x][i];
			num = 0;
			a[x][i] = (a[x][i] + j) % 10;
			for(int k = 1 ; k <= 5 ; k ++)
			{
				num = num * 10 + a[x][k];
			}
			if(x == 1 || t[x - 1][num] == 1)
			{
				t[x][num] = 1;
			}
			a[x][i] = tmp;
		}
	}
	for(int i = 1 ; i <= 4 ; i ++)
	{
		for(int j = 1 ; j <= 9 ; j ++)
		{
			tmp = a[x][i];
			tmp2 = a[x][i + 1];
			num = 0;
			a[x][i] = (a[x][i] + j) % 10;
			a[x][i + 1] = (a[x][i + 1] + j) % 10;
			for(int k = 1 ; k <= 5 ; k ++)
			{
				num = num * 10 + a[x][k];
			}
			if(x == 1 || t[x - 1][num] == 1)
			{
				t[x][num] = 1;
			}
			a[x][i] = tmp;
			a[x][i + 1] = tmp2;
		}
	}
}
int cha()
{
	int tmp = 0;
	int num = 0;
	int tmp2 = 0;
	int cnt = 0;
	for(int i = 1 ; i <= 5 ; i ++)
	{
		for(int j = 1 ; j <= 9 ; j ++)
		{
			tmp = a[n][i];
			num = 0;
			a[n][i] = (a[n][i] + j) % 10;
			for(int k = 1 ; k <= 5 ; k ++)
			{
				num = num * 10 + a[n][k];
			}
			if(t[n - 1][num] == 1)
			{
				cnt ++;
			}
			a[n][i] = tmp;
		}
	}
	for(int i = 1 ; i <= 4 ; i ++)
	{
		for(int j = 1 ; j <= 9 ; j ++)
		{
			tmp = a[n][i];
			tmp2 = a[n][i + 1];
			num = 0;
			a[n][i] = (a[n][i] + j) % 10;
			a[n][i + 1] = (a[n][i + 1] + j) % 10;
			for(int k = 1 ; k <= 5 ; k ++)
			{
				num = num * 10 + a[n][k];
			}
			if(t[n - 1][num] == 1)
			{
				cnt ++;
			}
			a[n][i] = tmp;
			a[n][i + 1] = tmp2;
		}
	}
	return cnt;
}
int main()
{
	freopen("lock.in" , "r" , stdin);
	freopen("lock.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= 5 ; j ++)
		{
			cin >> a[i][j];
		}
	}
	if(n == 1) {cout << 81; return 0;}
	for(int i = 1 ; i < n ; i ++)
	{
		zhuan(i);
	}
	cout << cha();
	return 0;
}