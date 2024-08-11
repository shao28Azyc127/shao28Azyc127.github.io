#include<bits/stdc++.h>
using namespace std;
int f(int n,string s)
{
    for(int i=n;i>=1;i--)
        s[i]=s[i-1];
    s[0]='A';
    int i=1,flag=1,x=1;
    while(i<=n)
    {
        if(s[i]==s[i+x]&&s[i]!='A')
        {
            s[i]='A',s[i+x]='A';
            if(s[i-1]==s[i+1+x]&&s[i-1]!='A')
                i--,x+=2;
            else
                x=1;
        }
        else
            x=1,i++;
    }
    for(int i=1;i<=n;i++)
        if(s[i]!='A')
                flag=0;
    if(flag) return 1;
    else return 0;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,ans=0;
    string s;
    cin>>n>>s;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    for(int i=n;i>=1;i--)
        s[i]=s[i-1];
    for(int i=2;i<=n;i+=2)
    {
        for(int j=1;j<=n;j++)
        {
            string g;
            if(i+j-1>n) break;
            int len=0;
            for(int k=j;k<=j+i-1;k++)
            {
                len++;
                g+=s[k];
            }
            if(f(len,g)) ans++;
        }
    }
    cout<<ans;
    return 0;
}
