#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector <int> v[10005],v2[10005];
struct node
{
    int x,cnt;
};
int n,m,k;
queue <node> q;
bool vis[10005];
void bfs()
{
    q.push(node{1,0});
    vis[1] = 1;
    while (!q.empty())
    {
    	int x = q.front().x,cnt = q.front().cnt;
    	q.pop();
    	for (int i = 0;i < v[x].size();i++)
    	{
    		if (v[x][i] == n){
    			cout << cnt + 1 << endl;
    			return;
    		}
            if (!vis[v[x][i]])
            {
            	vis[v[x][i]] = true;
            	q.push(node{v[x][i],cnt + 1});
            }
    	}
    }
    cout << -1 << endl;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    int maxn = 0;
    for (int i = 1;i <= m;i++)
    {
    	int a,b,w;
    	cin >> a >> b >> w;
    	maxn = max(maxn,w);
        v[a].push_back(b),v2[a].push_back(w);
    }
    if (k == 1 && maxn == 0)
        bfs();
    else cout << -1 << endl;
	return 0;
}