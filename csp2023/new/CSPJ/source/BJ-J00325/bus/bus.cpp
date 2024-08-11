#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
int n , m , k , minn = 2e9 , b;
int mp[10005][10005];
struct node
{
	int x , cnt;
};
queue<node> q;
void bfs(int c)
{
	q.push({1 , c});
	while(!q.empty())
	{
		int x = q.front().x , cnt = q.front().cnt;
		q.pop();
		if(cnt % k == 0 && x == n)
		{
			minn = min(minn , cnt);
			return ;
		}
		for(int i = 1 ; i <= n ; i ++)
			if(mp[x][i] != 0x3f && mp[x][i] <= cnt)
				q.push({i , cnt + 1});
	}

}
int main()
{
	freopen("bus.in" , "r" , stdin);
	freopen("bus.out" , "w" , stdout);
	memset(mp , 0x3f , sizeof(mp));
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i ++)
	{
		int x , y , z;
		cin >> x >> y >> z;
		mp[x][y] = z;
		b = max(b , z);
	}	
	for(int i = 0 ; i <= (b + k - 1) / k ; i ++)
	{
		bfs(i * k);
		while(!q.empty())
			q.pop();
	}
	if(minn == 2e9) minn = -1;
	cout << minn << endl;
	return 0;
}