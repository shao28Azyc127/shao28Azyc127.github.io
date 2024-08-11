#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;
int n,m,num[3010][27];
int i,j;
string t;
int sum[3010][27];
int mi[3010],ma[3010];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        cin>>t;
        for(j=0;j<m;j++)
            num[i][t[j]-'a']++;
        for(j=0;j<26;j++)
            sum[i][j]=num[i][j];
        for(j=1;j<26;j++)
            sum[i][j]+=sum[i][j-1];
        for(j=0;j<26;j++)
            if(num[i][j]>0)
            {
                mi[i]=j;
                break;
            }
        for(j=25;j>=0;j--)
            if(num[i][j]>0)
            {
                ma[i]=j;
                break;
            }
    }
    for(i=1;i<=n;i++)
    {
        bool fl=true;
        for(j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            if(mi[i]<ma[j])
                continue;
            if(mi[i]>=ma[j])
            {
                fl=false;
                break;
            }
        }
        cout<<fl;
    }
    return 0;
}