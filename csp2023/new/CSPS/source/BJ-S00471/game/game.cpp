#include<bits/stdc++.h>
#define debug printf("Im3tsmh\n")
using namespace std;
int n,ans;
string s;
bool selfs[8005][8005];
int b[8005][8005];
bool dfs(int l,int r)
{

    if(l==r)return false;
    //if(b[l][r]==0)return false;
   // if(b[l][r]==1)return true;
    bool flag=false;
    for(int k=l;k<=r-1;++k)
    {
        bool x=dfs(l,k);
        bool y=dfs(k+1,r);
        if(selfs[l][k])x=1;
        if(selfs[k+1][r])y=1;
        if(x==1&&y==1)flag=true;
    }
    if(selfs[l][r])flag=true;
    //b[l][r]=flag;
    if(flag&&b[l][r]!=2)++ans;
     b[l][r]=2;
    return flag;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);cin>>s;
    memset(b,-1,sizeof(b));
    for(int i=0;i<=8000;++i)b[i][i]=0;
    for(int i=0;i<=n-1;++i)
    {
        for(int j=i+1;j<=n-1;++j)
        {
            if((j-i+1)%2)continue;
            bool B=true;
            for(int k=0;k<=(j-i+1)/2;++k)
            {
                if(s[i+k]!=s[j-k]){
                    B=false;
                    break;
                }
            }
            if(B)selfs[i][j]=1;
        }
    }
    dfs(0,n-1);
    //for(int i=0;i<=n-1;++i)for(int j=i+1;j<=n-1;++j)if(b[i][j]==1)
    //{
    //    ++ans;
    //}
    printf("%d\n",ans);
    return 0;
}

