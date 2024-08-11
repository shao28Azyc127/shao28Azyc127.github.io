#include<bits/stdc++.h>
using namespace std;

const int maxn=3007;
const int maxm=3007;
int n,m;

char w_greater[maxn][maxm];
char w_smaller[maxn][maxm];
int fst_smallest=0,sec_smallest=0;

bool cmp_greater(char a,char b)
{
	return a>b;
}
bool cmp_smaller(char a,char b)
{
	return a<b;
}
bool cmp_smaller_dict(char a[],char b[])
{
	for(int i=0;i<m;i++)
	{
		if(a[i]>b[i])return 0;
		else if(a[i]<b[i])return 1;
	}
	return 0;
}
bool cmp_greater_dict(char a[],char b[])
{
	for(int i=0;i<m;i++)
	{
		if(a[i]>b[i])return 1;
		else if(a[i]<b[i])return 0;
	}
	return 1;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		w_smaller[0][i]='{';
		w_greater[0][i]='{';
	}
	for(int i=1;i<=n;i++)
	{
		getchar();
		char in1[maxm],in2[maxm];
		for(int j=1;j<=m;j++)
		{
			in1[j]=getchar();
			in2[j]=in1[j];
		}
		sort(in1+1,in1+m+1,cmp_greater);
		sort(in2+1,in2+m+1,cmp_smaller);
		for(int j=1;j<=m;j++)w_greater[i][j-1]=in1[j];
		for(int j=1;j<=m;j++)w_smaller[i][j-1]=in2[j];
		if( cmp_smaller_dict( w_greater[i] , w_greater[fst_smallest] ) )sec_smallest=fst_smallest,fst_smallest=i;
		else if( cmp_smaller_dict( w_greater[i] , w_greater[sec_smallest] ) )sec_smallest=i;
	}
//	for(int i=0;i<m;i++)cout << w_greater[fst_smallest][i];
//	cout << endl;
//	for(int i=0;i<m;i++)cout << w_greater[sec_smallest][i];
//	cout << endl;
	for(int i=1;i<=n;i++)
	{
		int smallest=fst_smallest;
		if(i==fst_smallest)smallest=sec_smallest;
		if( cmp_smaller_dict(w_smaller[i],w_greater[smallest]) )printf("1");
		else printf("0");
	}
	return 0;
}
