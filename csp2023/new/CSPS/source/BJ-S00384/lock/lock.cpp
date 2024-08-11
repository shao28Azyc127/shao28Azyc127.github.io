#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAXN = 10;
typedef long long LL;
LL ans = 0;
struct node
{
	int p[6];
}a[MAXN];
bool vis[6];
int n;
vector<int> ans1,ans2;
void dfs1(int step,int x,int ans)
{
	if(step == 6)
	{
		ans1.push_back(ans);
	}
	if(vis[step])
	{
		for(int i = 0;i <= 9;i++)
		{
			if(i == a[1].p[step] || i == a[2].p[step]) continue;
			//cout << i << " " << ans << endl;
			dfs1(step+1,i,ans + i*pow(10,5-i+1));
		}
	}
	else
	{
		dfs1(step+1,x,ans);
	}
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= 5;j++)
		{
			cin >> a[i].p[j];
		}
	}
	for(int i = 1;i < n;i++)
	{
		for(int j = 1;j <= 5;j++)
		{
			if(a[i].p[j] != a[i+1].p[j])
			{
				vis[j] = 1;	
			}
		}
	}
	if(n == 1)
	{
		cout << 81 << endl;
		return 0;
	}
	
	return 0;
}