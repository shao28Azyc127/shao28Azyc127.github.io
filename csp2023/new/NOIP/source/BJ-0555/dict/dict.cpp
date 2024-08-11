#include <bits/stdc++.h>
#define MAXN 3009
using namespace std;

struct Word
{
	string word;
	bool real;
	int num;
}w[2*MAXN];

bool ans[MAXN];

int n,m;

bool cmp(Word a,Word b)
{
	return a.word < b.word;
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char cinword[MAXN];
		cin>>cinword;
		w[i].word = cinword;
		w[i].real = 1;
		w[i].num = i;

		sort(cinword,cinword+m);

		w[i+n].word = cinword;
		w[i+n].real = 0;
		w[i+n].num = i;
	}
	sort(w+1,w+2*n+1,cmp);
	bool Ans = 1;
	for(int i=1;i<=2*n;i++)
	{
		//cout<<w[i].word<<":"<<w[i].num<<" = "<<w[i].real<<endl;
		if(w[i].real == 1)
		{
			Ans = 0;
		}
		else
		{
			ans[w[i].num] = Ans;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i];
	}
	return 0;
}