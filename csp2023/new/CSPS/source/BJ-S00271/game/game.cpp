#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000010;
int n,top;
LL ans;
string str;
char stk[N];
int dir[N];
int l[N],r[N];
bool vis[N];
LL sum[N];
void solve1()
{
	memset(l,-1,sizeof(l));
	memset(r,-1,sizeof(r));
	for(int i = 1;i <= n;++i)
	{
		if(l[i] != -1) continue ;
		top = 0;
		stk[++top] = str[i];
		dir[top] = i;
		for(int j = i+1;j <= n;++j)
		{
			//cout << "ok" << endl;
			if(top && stk[top] == str[j]) 
			{
				l[dir[top]] = j;
				r[j] = dir[top];
				--top;
			}
			else if(vis[j] && l[j] == -1) break;
			else if(vis[j] && l[j] != -1) j = l[j];
			else 
			{
				stk[++top] = str[j];
				dir[top] = j;
				vis[j] = true;
			}
			if(top == 0) break;
		}
	}
	//cout << "ok" << endl;
	for(int i = 1;i <= n;++i) if(l[i] != -1) sum[i] = 1;
	for(int i = n;i >= 1;--i)
	{
		ans += sum[i];
		if(l[i] != -1 && r[i-1] != -1) sum[r[i-1]] += sum[i];
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> str;
	str  = " " + str;
	//cout << "ok" << endl;
	solve1();
	cout << ans << endl;
	return 0;
}
