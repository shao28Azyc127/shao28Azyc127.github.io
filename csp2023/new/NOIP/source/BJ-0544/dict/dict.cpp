#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<iostream>
using namespace std;
const int MAXN=3010;
string s[MAXN],mins[MAXN],maxs[MAXN];
map<pair<string,int>,int> mp;
int minv[MAXN],maxv[MAXN];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,l,i,j;
    scanf("%d %d",&n,&l);
    for(i=1;i<=n;i++) cin>>s[i];
    for(i=1;i<=n;i++)
    {
        sort(s[i].begin(),s[i].end());
        mins[i]=s[i];maxs[i]=s[i];
        for(j=0;j<l/2;j++) swap(maxs[i][j],maxs[i][l-j-1]);
    }
    for(i=1;i<=n;i++)
    {
        mp[make_pair(mins[i],i)]++;
        mp[make_pair(maxs[i],i+n)]++;
    }
    map<pair<string,int>,int>::iterator it;
    int cnt=1;
    string now=" ";
    for(it=mp.begin();it!=mp.end();it++)
    {
        pair<string,int> p=it->first;
        int num=p.second;
        if(now!=p.first) cnt++;
        now=p.first;
        if(num<=n)
        {
            minv[num]=cnt;
        }
        else maxv[num-n]=cnt;
    }
    for(i=1;i<=n;i++)
    {
        int mint=1000000;
        for(j=1;j<=n;j++)
        {
            if(j==i) continue;
            mint=min(mint,maxv[j]);
        }
        if(mint<minv[i]) printf("0");
        else printf("1");
    }
    return 0;
}
