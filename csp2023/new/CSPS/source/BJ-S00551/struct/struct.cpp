#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 105;

map<string,int> tname;
map<string,int> bname[N];

int tot;
int bot[N];

struct tpnode
{
	int cnt;
	vector<int> typ;
	vector<int> nam;
	int maxq;
}tp[N];

void init()
{
	++tot;
	tp[tot].maxq = 1;
	tname["byte"] = tot;
	tp[tot].cnt = 1;
	++tot;
	tp[tot].maxq = 2;
	tname["short"] = tot;
	tp[tot].cnt = 1;
	++tot;
	tp[tot].maxq = 4;
	tname["int"] = tot;
	tp[tot].cnt = 1;
	++tot;
	tp[tot].maxq = 8;
	tname["long"] = tot;
	tp[tot].cnt = 1;
}

string ttt;

int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	init();
	cin >> n;
	LL allnc = 0;
	for(int i = 1;i <= n;i++)
	{
		int opt;
		cin >> opt;
		//~ cout << "opt:" << opt << "\n";
		if(opt == 1)
		{
			++tot;
			string ts;
			cin >> ts;
			tname[ts] = tot;
			cin >> tp[tot].cnt;
			for(int j = 0;j < tp[tot].cnt;j++)
			{
				cin >> ts;
				int tmp = tname[ts];
				tp[tot].typ.push_back(tmp);
				tp[tot].maxq = max(tp[tot].maxq,tp[tmp].cnt * tp[tmp].maxq);
				cin >> ts;
				++bot[tot];
				bname[tot][ts] = bot[tot];
				tp[tot].nam.push_back(bot[tot]);
			}
			cout << tp[tot].cnt * tp[tot].maxq << " " << tp[tot].maxq << "\n";
		}
		else if(opt == 2)
		{
			string ttpp,nnmm;
			cout << allnc << "\n";
			cin >> ttpp >> nnmm;
			int tmp = tname[ttpp];
			bname[0][nnmm] = bot[0];
			allnc += tp[tmp].cnt * tp[tmp].maxq;
			ttt = nnmm;
		}
		else if(opt == 3)
		{
			string str;
			cin >> str;
			cout << ttt << "\n";
		}
		else if(opt == 4)
		{
			cout << "ERR\n";
		}
	}
	return 0;
}
/*
2
1 aa 2
int xx
byte yy
1 bb 2
byte yy
aa xx

*/
