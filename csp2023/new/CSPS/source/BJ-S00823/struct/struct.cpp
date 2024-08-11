#include <bits/stdc++.h>
using namespace std;
int d[100010],cnt1=-1,cnt2,cnt3,e[30];
map<string,int> m,m2;
string m3[100010];
struct node1
{
	string s2,s3;
	int d;
}b[10010];
struct node
{
	string s1;
	int k;
	int c,ma;
}a[110];
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int n,i,j,jj,o,d1;
	string sn,sx;
	cin>>n;
	e['b'-'a']=1;
	e['s'-'a']=2;
	e['i'-'a']=4;
	e['l'-'a']=8;
	for(i=1;i<=n;i++)
	{
		cin>>o;
		if(o==1)
		{
			++cnt3;
			cin>>a[cnt3].s1>>a[cnt3].k;
			a[cnt3].c=cnt2;
			m2[a[cnt3].s1]=cnt3;
			a[cnt3].ma=0;
			for(j=1;j<=a[cnt3].k;j++)
			{
				++cnt2;
				cin>>b[cnt2].s2>>b[cnt2].s3;
				a[cnt3].ma=max(a[cnt3].ma,e[b[cnt2].s2[0]-'a']);
			}
			cout<<a[cnt3].k*a[cnt3].ma<<" "<<a[cnt3].ma<<'\n';
		}
		else if(o==2)
		{
			cin>>sn>>sx;
			cout<<cnt1+1<<'\n';
			if(sn=="byte"||sn=="short"||sn=="int"||sn=="long")
			{
				++cnt2;
				b[cnt2].s2=sn;
				b[cnt2].s3=sx;
				b[cnt2].d=cnt1+1;
				m[b[cnt2].s3]=cnt1+1;
				m3[cnt1+1]=b[cnt2].s2;
				for(j=1;j<=e[b[cnt2].s2[0]-'a'];j++)
					d[++cnt1]=cnt2;
			}
			else
			{
				for(j=1;j<=a[m2[sn]].k;j++)
				{
					b[a[m2[sn]].c+j].d=cnt1+1;
					m[sx+'.'+b[a[m2[sn]].c+j].s3]=cnt1+1;
					m3[cnt1+1]=sx+'.'+b[a[m2[sn]].c+j].s3;
					for(jj=1;jj<=e[b[a[m2[sn]].c+j].s2[0]-'a'];jj++)
						d[cnt1+jj]=a[m2[sn]].c+j;
					cnt1+=a[m2[sn]].ma;
				}
			}
		}
		else if(o==3)
		{
			cin>>sn;
			cout<<m[sn]<<'\n';
		}
		else if(o==4)
		{
			cin>>d1;
			if(d1>cnt1||d[d1]==0)
				cout<<"ERR"<<'\n';
			else
				cout<<m3[b[d[d1]].d]<<'\n';
		}
	}
	return 0;
}
