#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+7;

int n,m;
struct operation{
	char type;
	int a,b;
}op[maxn];
char tribool[maxn];
char tritype[]={'\0','T','F','U'};
const int inf=2147483647;
int minu;
bool check()
{
	char tmp[maxn];
	for(int i=1;i<=n;i++)tmp[i]=tribool[i];
	for(int i=1;i<=m;i++)
	{
		if(op[i].type=='U'||op[i].type=='F'||op[i].type=='T')
			tmp[op[i].a]=op[i].type;
		else if(op[i].type=='+')
			tmp[op[i].a]=tmp[op[i].b];
		else{
			if(tmp[op[i].b]=='F')tmp[op[i].a]='T';
			else if(tmp[op[i].b]=='T')tmp[op[i].a]='F';
			else if(tmp[op[i].b]=='U')tmp[op[i].a]='U';
		}
	}
	for(int i=1;i<=n;i++)
		if(tribool[i]!=tmp[i])return 0;
	return 1;
}
void work(int i)
{
	for(int j=1;j<=3;j++)
	{
		tribool[i]=tritype[j];
		if(i==n)
		{
			
			int amu=0;
			for(int k=1;k<=n;k++)amu+=int(tribool[k]=='U');
			if(check()){
				minu=min(amu,minu);
			}
		}
		if(i!=n)
		{
			work(i+1);
		}
	}
	return;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i=1;i<=m;i++)
		{
			cin >> op[i].type;
			if(op[i].type=='+'||op[i].type=='-')cin >> op[i].a >> op[i].b;
			else cin >> op[i].a;
		}
		if(c==3||c==4)
		{
			int ans=0;
			for(int i=1;i<=m;i++)tribool[op[i].a]=op[i].type;
			for(int i=1;i<=n;i++)if(tribool[i]=='U')ans++;
			cout << ans;
		}
		if(c==1||c==2)
		{
			minu=inf;
			work(1);
			cout << minu << endl;
		}
	}
        return 0;
}
