#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
int n,m;
int c[N][30];
string yu[30][N],mins,s1,s2;
string s;
bool check(int a,int b)
{
    s1 = "",s2 = "";
    for(int i = 1;i <= 26;i++)
    {
//        for(int j = 1;j <= c[a][i];j++)
//           s1 = s1+char(i+'a'-1);
		s1 = s1+yu[i][c[a][i]];
    }
    for(int i = 26;i >= 1;i--)
    {
//        for(int j = 1;j <= c[b][i];j++)
//            s2 = s2+char(i+'a'-1);
		s2 = s2+yu[i][c[b][i]];
    }
//    cout<<s1<<endl<<s2<<endl;
    if(s1<s2)
        return 1;
    return 0;
}
bool cmp(int a,int b)
{
	s1 = "",s2 = "";
    for(int i = 26;i >= 1;i--)
    {
//        for(int j = 1;j <= c[a][i];j++)
//           s1 = s1+char(i+'a'-1);
		s1 = s1+yu[i][c[a][i]];
    }
    for(int i = 26;i >= 1;i--)
    {
//        for(int j = 1;j <= c[b][i];j++)
//            s2 = s2+char(i+'a'-1);
		s2 = s2+yu[i][c[b][i]];
    }
//    cout<<s1<<endl<<s2<<endl;
    if(s1<s2)
        return 1;
    return 0;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        cin>>s;
        for(int j = 0;j < m;j++)
            c[i][s[j]-'a'+1]++;
    }
 /*   for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= 26;j++)
            cout<<c[i][j]<<' ';
        cout<<endl;
    }*/
    for(int i = 1;i <= 26;i++)
    {
		for(int j = 1;j <= m;j++)
			yu[i][j] = yu[i][j-1]+char('a'+i-1);
	}
	for(int i = 1;i <= m;i++)
		mins = mins+'z';
	c[3001][26] = m;
	for(int i = 1;i <= n;i++)
		if(!cmp(3001,i))
		{
			mins = s2;
			for(int j = 1;j <= 26;j++)
				c[3001][j] = c[i][j];
		}
//	cout<<mins<<endl;
    for(int i = 1;i <= n;i++)
    {
//		cout<<i<<endl;
        if(check(i,3001))
            printf("1");
        else
            printf("0");
    }
    cout<<endl;
//    cout<<check(4,2);
    return 0;
}
