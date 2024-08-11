#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
string s;
vector<char> q;
int vis[9000];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n;
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		q.push_back(s[i]);
	}
	long long ans = 1;
	int tot = 1;
	while(!q.empty())
	{
		bool flag = 0;
		for(int i = 0;i < q.size()-1;i++)
		{
			//cout << i << " " << q[i] << " " << i+1 << " " << q[i+1] << endl;
			if(q[i] == q[i+1])
			{
				ans++;
				q.erase(q.begin()+i,q.begin()+i+2);
				flag = 1;
				break;
			}
		}
		if(!flag) break;
	}
	cout << ans << endl;
	return 0;
}