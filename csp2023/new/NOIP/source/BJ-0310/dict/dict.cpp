#include<bits/stdc++.h>
using namespace std;
struct node{
    int tp,op;
    string s;
};
int n;
string s[3010];
int maxx[3010],minn[3010];
int cot[3010][30],cnt;
node p[3010];
bool judge(int x)
{

    for(int j=1;j<=n;j++)
    {
        if(j==x) continue;
        if(minn[x]>maxx[j]) return false;
        if(minn[x]<maxx[j]) continue;
        if(minn[x]==maxx[j]&&cot[x][minn[x]]>=cot[j][maxx[j]]) return false;
    }
    return true;
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i],s[i]=' '+s[i];
    for(int i=1;i<=n;i++)
    {
        minn[i]=100;
        for(int j=1;j<=m;j++) cot[i][s[i][j]-'a'+1]++,maxx[i]=max(maxx[i],s[i][j]-'a'+1),minn[i]=min(minn[i],s[i][j]-'a'+1);
    }
    //sort(p+1,p+cnt+1);
    for(int i=1;i<=n;i++)
    {
        if(judge(i)) cout<<1;
        else cout<<0;
    }
}
