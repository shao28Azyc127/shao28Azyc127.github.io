#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int N=2e5+10;

int n;
char s[N];
ll f[N],ans;
bool g[801][801];
vector<int> ok[N][26],pos[26];

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",s+1);
    if(n>=800)
    {
    for(int i=1;i<=n;i++)
    {
        for(auto j:ok[i-1][s[i]-'a'])
            f[i]+=f[j-1]+1;
//        cout<<endl;
        for(auto j:ok[i-1][s[i]-'a'])
        {
            if(j>1) ok[i][s[j-1]-'a'].push_back(j-1);
            for(int c=0;c<26;c++)
                for(auto k:ok[j-1][c]) ok[i][c].push_back(k);
        }
        ok[i][s[i]-'a'].push_back(i);
        ans+=f[i];
        for(int j=0;j<26;j++) ok[i][j].erase(unique(ok[i][j].begin(),ok[i][j].end()),ok[i][j].end());
//        cout<<i<<"***"<<f[i]<<endl;
    }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            g[i][i-1]=true;
            for(int j:pos[s[i]-'a'])
            {
                if(g[j+1][i-1])
                {
                    g[j][i]=true;
                    for(int k=1;k<j;k++)
                    {
                        g[k][i]|=g[k][j-1];
                    }
                }
            }
            pos[s[i]-'a'].push_back(i);
        }
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                ans+=g[i][j];
    }
    printf("%lld",ans);

    return 0;
}

//accabccb
