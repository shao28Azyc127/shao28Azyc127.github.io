//By Pr_159
#include <bits/stdc++.h>
using namespace std;

const int N = 5;
int n, a[N][N], ans = 0;

bool check(int* input)
{
	for(int i = 0; i < n; i++)
	{
		int pos1 = -1, pos2 = -1, flag = 0;
		for(int j = 0; j < 5; j++)
		{
			if(a[i][j] != input[j])
			{
				//cout << "j=" << input[j] << endl;
				if(pos1 == -1)
				{
					pos1 = j;
					//printf("pos1=%d\n", pos1);
				}
				else if(pos2 == -1)
				{
					pos2 = j;
					//printf("pos2=%d\n", pos2);
				}
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if(flag) return 0;
		if(pos1 == -1 && pos2 == -1) return 0;
		if(pos2 != -1)
		{
			if(pos1 + 1 != pos2) return 0;
			int tmp1 = a[i][pos1] - input[pos1];
			int tmp2 = a[i][pos2] - input[pos2];
			//cout << pos1 << ' ' << pos2 << endl;
			//cout << tmp1 << ' ' << tmp2 << endl;
			if(tmp1 != tmp2) return 0;
		}
	}
	//printf("successed on input = ");
	//for(int i = 0; i < 5; i++) cout << input[i];
	//cout << endl;
	return 1;
}
/*
 * if(a[i][j] != input[j] && flag1)
			{
				//printf("second time flag1 = 1 on j = %d\n", j);
				flag1 = 0, flag2 = 1;
			}
			if(a[i][j] != input[j] && !flag2)
			{
				//printf("first time flag1 = 1 on j = %d\n", j);
				flag1 = 1;
			}
			if(j == 4) break;
			int tmp1 = a[i][j] - input[j];
			int tmp2 = a[i][j + 1] - input[j + 1];
			if(tmp1 == 0 || tmp2 == 0) continue;
			if(tmp1 == tmp2 && flag3) flag3 = 0, flag4 = 1;
			if(tmp1 == tmp2 && !flag4) flag3 = 1;
*/
void dfs(int step, int c[N])
{
	if(step == 5)
	{
		//for(int i = 0; i < 5; i++) cout << c[i] << ' ';
		//cout << endl;
		//for(int i = 0; i < 5; i++) input[i] = c[i];
		if(check(c)) ans++;
		return;
	}
	for(int i = 0; i <= 9; i++)
	{
		int tmp = c[step];
		c[step] = i;
		dfs(step + 1, c);
		c[step] = tmp;
	}
}

int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cin >> a[i][j];
		}
	}
	if(n == 1)
	{
		cout << 81;
		return 0;
	}
	int tmp[5] = {0, 0, 0, 0, 0};
	dfs(0, tmp);
	//int in[5] = {1, 1, 1, 4, 4};
	//for(int i = 0; i < 5; i++) input[i] = in[i];
	//cout << check(in) << endl;
	cout << ans << endl;
	return 0;
}
/*
2
1 1 1 2 2
1 1 1 3 3
*/
