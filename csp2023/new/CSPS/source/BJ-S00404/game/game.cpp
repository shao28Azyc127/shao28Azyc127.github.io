#include<iostream>
#include<set>
using namespace std;
const int maxn=2e6+5;
typedef long long ll;
char s[maxn];
ll dp[maxn];
int opt[maxn][30];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int in;
    ll oans=0;
    cin>>in;
    scanf("%s",s+1);
    s[1]-='a'-1;
    for(int v1=2;v1<=in;v1++)
    {
        s[v1]-='a'-1;
        int pos;
        if(s[v1]==s[v1-1])pos=opt[v1][s[v1-2]]=v1-2;
        else
        {
            opt[v1][s[pos]]=pos=opt[v1-1][s[v1]]-1;
        }
        if(pos<0)continue;
        for(int v2=1;v2<=26;v2++)if(!opt[v1][v2])opt[v1][v2]=opt[pos][v2];
        dp[v1]=dp[pos]+1;
        oans+=dp[v1];
    }
    cout<<oans<<endl;
    return 0;
}
