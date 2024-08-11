#include<iostream>
using namespace std;
char s[2000001];
int dp[2000001],head[2000001],type[2000001],lst[26][2000001];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    long long ans = 0,sz = 1;
    head[0] = 1;
    for(int i = 1;i <= n;i++)
    {
        //cerr << i << endl;
        if(s[i-1] == s[i])
        {
            dp[i] = dp[i-2] + 1;
            head[i] = head[i-2];
            type[i-1] = head[i];
            if(i > 3) lst[s[i-2]-'a'][head[i]] = i-2;
            head[i-2] = 0;
        }
        else if(lst[s[i]-'a'][head[i-1]])
        {
            dp[i] = dp[lst[s[i]-'a'][head[i-1]]-1] + 1;
            head[i] = head[lst[s[i]-'a'][head[i-1]]-1];
            type[lst[s[i]-'a'][head[i-1]]] = head[i];
            if(lst[s[i]-'a'][head[i-1]] > 1)
                lst[s[lst[s[i]-'a'][head[i-1]]-1]-'a'][head[i]] = max(lst[s[lst[s[i]-'a'][head[i-1]]-1]-'a'][head[i]],lst[s[i]-'a'][head[i-1]]-1);
            head[lst[s[i]-'a'][head[i-1]]-1] = 0;
        }
        else head[i] = ++sz;
        ans += dp[i];
    }
    printf("%lld",ans);
    return 0;
}