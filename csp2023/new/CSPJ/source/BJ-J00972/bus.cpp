#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10005;
const int INF = 1e9 + 7;

int n, m, k, ans = INF;
int x, y, z;
vector<int> e[N], v[N];

void find(int cur, int t)
{
	if(cur == n && t % k == 0) ans = min(ans, t);
	if(t >= ans || cur == n) return ;
	for(int i = 0; i < e[cur].size(); i++)
		if(v[cur][i] <= t) find(e[cur][i], t + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		e[x].push_back(y), v[x].push_back(z);
	}
	for(int i = 0; i < ans; i += k) find(1, i);
	if(ans == INF) cout << -1;
	else cout << ans;
	
	return 0;
}

// ���ΰ�ʿ����д��QaQ ��ʵǰ�����ҷ־ͺ�
// �����ĳ�����·���ݣ����ɾ���
// �᲻���л������᲻��Ҫ���㰢����֮����д�˰�
// ������û�������ǲ���Ҫ���Һ��㷨������
// ����