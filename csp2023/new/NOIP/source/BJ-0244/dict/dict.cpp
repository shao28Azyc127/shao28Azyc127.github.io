#include<bits/stdc++.h>
using namespace std;
const int Maxn=3010;
int tong[Maxn][26];
int Above[Maxn],End[Maxn];
int n,m;
int main()
{
    // NOIP2023 RP++
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        for(int j=0;j<str.size();j++)
        {
            tong[i][str[j]-'a']++;
        }
        for(int j=0;j<26;j++)
        {
            if(tong[i][j]) End[i]=j;
        }
        for(int j=25;j>=0;j--)
        {
            if(tong[i][j]) Above[i]=j;
        }
    }
    for(int i=1;i<=n;i++)
    {
        bool flag=1;
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(Above[i]>=End[j])
            {
                flag=0;
                break;
            }
        }
        printf("%d",flag);
    }
    putchar('\n');
    return 0;
}
