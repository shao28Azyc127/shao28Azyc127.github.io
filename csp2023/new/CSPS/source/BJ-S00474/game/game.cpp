# include <bits/stdc++.h>
# define N 2000005
using namespace std;
int n;
char s[N];
int r[N],nxt[N][26];
long long ans=0,res[N];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    scanf("%s",s+1);
    r[n]=-1;
    memset(nxt,-1,sizeof nxt);
    nxt[n][s[n]-'a']=n;
    for(int i=n-1;i>=1;i--)
    {
        r[i]=nxt[i+1][s[i]-'a'];
        memcpy(nxt[i],nxt[r[i]+1],sizeof nxt[i]);
        nxt[i][s[i]-'a']=i;
    }
    for(int i=n;i>=1;i--)
    {
        if(r[i]==-1)
            continue;
        res[i]=res[r[i]+1]+1;
        ans+=res[i];
    }
    cout<<ans<<endl;
    return 0;
}
//-ulimit -s unlimited
//-fsanitize=undefined,address