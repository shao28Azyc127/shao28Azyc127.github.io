#include<bits/stdc++.h>

using namespace std;

int n;
bool flag[1000010];
vector<int> A;
int ans1, ans2;

int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; ; i++)
	{
		//printf("------\n");
		A.clear();
		for (int j = 1; j <= n; j++)
			if (!flag[j])
				A.push_back(j);
		if (A.empty())
		{
			ans1 = i - 1;
			break;
		}
		for (int j = 0, len = A.size(); j < len; j += 3)
		{
			//printf("abc\n");
			if (A[j] == n)
				ans2 = i;
			flag[A[j]] = true;
		}
	}
	printf("%d %d\n", ans1, ans2);

	return 0;
}
