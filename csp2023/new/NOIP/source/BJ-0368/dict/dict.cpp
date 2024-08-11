#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,cnt[30];
string mins[3010],maxs[3010];
bool cmp(const char &x,const char &y){
    return x>y;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>mins[i];
        for(int j=0;j<26;j++)cnt[j]=0;
        for(int j=0;j<m;j++)cnt[mins[i][j]-'a']++;
        mins[i]="";
        for(int j=0;j<26;j++)
            for(int k=1;k<=cnt[j];k++)
                mins[i]+=char(j+'a');
        for(int j=25;j>=0;j--)
            for(int k=1;k<=cnt[j];k++)
                maxs[i]+=char(j+'a');
    }
    for(int i=1;i<=n;i++)
    {
        bool flag=1;
        for(int j=1;j<=n;j++)
            if(i==j)continue;
            else if(mins[i]>maxs[j])flag=0;
        cout<<flag;
    }
    return 0;
}