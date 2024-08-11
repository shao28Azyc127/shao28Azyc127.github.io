#include <iostream>
using namespace std;
int locks[10][10];
int same[100000];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	
	int n;
	cin >> n;
	for (int i=0;i<n;i++){
		for(int j = 0; j < 5; j++){
			cin >> locks[i][j];
		}
	}
	if (n == 1)
	{
		cout << 81;
		return 0;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 5;j++){
			for(int k = 0; k <= 9; k++)
			{
				if(k == locks[i][j]) continue;
				int sum = 0;
				for(int v = 0; v < 5;v++){
					sum *= 10;
					if(v == j) sum += k;
					else sum += locks[i][v];
				}
				same[sum]++;
			}
		}
		for(int j = 0; j < 4;j++){
			for(int k = 0; k <= 9; k++)
			{
				if(k == locks[i][j]) continue;
				int sum = 0;
				int a = locks[i][j+1] - locks[i][j] + k;
				if (a >= 10) a -= 10;
				if (a < 0) a += 10;
				for(int v = 0; v < 5;v++){
					sum *= 10;
					if(v == j) sum += k;
					else if (v == j+1) sum += a;
					else sum += locks[i][v];
				}
				same[sum]++;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 100000; i++)
	{
		if(same[i]==n) 
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
