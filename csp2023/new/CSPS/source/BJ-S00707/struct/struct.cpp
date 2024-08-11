#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
typedef long long ll;

string name[114], Name[114];
string sname[114][114];
int son[114][114], cson[114], a[114], tp[114];
ll s[114], b[114], o[114][114];
int tot = 4, len = 0, blen;
char tmp[114];
char big[11451];
string ttp;
void getst()
{
	int l, i;
	ttp = "";
	scanf("%s", tmp);
	l = strlen(tmp);
	for(i = 0; i < l; i++)
		ttp += tmp[i];
}
int Pos(string str)
{
	int i;
	for(i = 1; i <= len; i++)
		if(Name[i] == str)
			return i;
	return 0;
}
int Type(string str)
{
	int i;
	for(i = 1; i <= tot; i++)
		if(name[i] == str)
			return i;
	return 0;
}
int Son(int p, string str)
{
	int i;
	for(i = 1; i <= cson[p]; i++)
		if(sname[p][i] == str)
			return i;
	return 0;
}
void add(string s)
{
	int i, l = s.size();
	for(i = 0; i < l; i++)
		big[++blen] = s[i];
	big[blen + 1] = '\0';
}
void work()
{
	int p, i;
	ll ps;
	blen = 0;
	scanf("%lld", &ps);
	for(i = 1; i <= len; i++)
		if(b[i] > ps)
			break;
	i--;
	ps -= b[i];
	if(ps >= s[tp[i]] || ps < 0)
	{
		printf("ERR\n");
		return ;
	}
	add(Name[i]);
	p = tp[i];
	while(p > 4)
	{
		for(i = 1; i <= cson[p]; i++)
			if(o[p][i] > ps)
				break;
		i--;
		ps -= o[p][i];
		if(ps >= s[son[p][i]] || ps < 0)
		{
			printf("ERR\n");
			return ;
		}
		big[++blen] = '.';
		add(sname[p][i]);
		p = son[p][i];
	}
	printf("%s\n", big + 1);
}

int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	int n, i, j, k, op, las, L, p, r;
	ll q;
	scanf("%d", &n);
	name[1] = "byte";
	s[1] = a[1] = 1;
	name[2] = "short";
	s[2] = a[2] = 2;
	name[3] = "int";
	s[3] = a[3] = 4;
	name[4] = "long";
	s[4] = a[4] = 8;
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &op);
		if(op == 1)
		{
			++tot;
			getst();
			name[tot] = ttp;
			scanf("%d", cson + tot);
			for(j = 1; j <= cson[tot]; j++)
			{
				getst();
				son[tot][j] = Type(ttp);
				a[tot] = max(a[tot], a[son[tot][j]]);
				if(j > 1)
				{
					o[tot][j] = o[tot][j - 1] + s[son[tot][j - 1]];
					o[tot][j] = (o[tot][j] + a[son[tot][j]] - 1) / a[son[tot][j]] * a[son[tot][j]];
				}
				getst();
				sname[tot][j] = ttp;
			}
			s[tot] = o[tot][cson[tot]] + s[son[tot][cson[tot]]];
			s[tot] = (s[tot] + a[tot] - 1) / a[tot] * a[tot];
			printf("%lld %d\n", s[tot], a[tot]);
		}
		if(op == 2)
		{
			++len;
			getst();
			tp[len] = Type(ttp);
			getst();
			Name[len] = ttp;
			b[len] = b[len - 1] + s[tp[len - 1]];
			b[len] = (b[len] + a[tp[len]] - 1) / a[tp[len]] * a[tp[len]];
			printf("%lld\n", b[len]);
		}
		if(op == 3)
		{
			scanf("%s", big + 1);
			las = 0;
			p = q = 0;
			L = strlen(big + 1);
			for(j = 1; j <= L + 1; j++)
				if(big[j] == '.' || big[j] == '\0')
				{
					ttp = "";
					for(k = las + 1; k < j; k++)
						ttp += big[k];
					if(!p)
					{
						r = Pos(ttp);
						q = b[r];
						p = tp[r];
					}
					else
					{
						r = Son(p, ttp);
						q += o[p][r];
						p = son[p][r];
					}
					las = j;
				}
			printf("%lld\n", q);
		}
		if(op == 4)
			work();
	}
	return 0;
}