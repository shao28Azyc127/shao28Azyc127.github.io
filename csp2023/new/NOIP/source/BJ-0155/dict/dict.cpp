#include<bits/stdc++.h>
using namespace std;

char s[3010];
int mi[3010],mx[3010];
bool ans[3010];
bool cmp(int x,int y)//small x,big y
{
    if(x==y)return 1;
    return mi[x]<mx[y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>(s+1);
        mi[i]=1e9;
        mx[i]=0;
        for(int j=1;j<=m;j++)
        {
            mi[i]=min(mi[i],s[j]-'a');
            mx[i]=max(mx[i],s[j]-'a');
        }
    }
    for(int i=1;i<=n;i++)
    {
        bool flag=1;
        for(int j=1;j<=n;j++)if(cmp(i,j)==0){
            flag=0;
            break;
        }
        ans[i]=flag;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i];
    }cout<<'\n';
    return 0;
}