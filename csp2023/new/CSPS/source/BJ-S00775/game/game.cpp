#include <bits/stdc++.h>
using namespace std;
string s,a;
int n,ans;
bool fun(string b,int l)
{
    int t=l;
    string c;
    while(t--&&b!="")
    {
        for(int i=0;i<l;i++)
        {
            if(b[i]==b[i+1])
            {
                c="";
                for(int j=0;j<l;j++)
                {
                    if(j!=i&&j!=i+1)
                    {
                        c+=b[j];
                    }
                }
                i--;
                l-=2;
                b=c;
            }
        }
    }
    return b=="";
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+2;j<=n;j+=2)
        {
            a="";
            for(int k=i;k<j;k++)
            {
                a+=s[k];
            }
            if(fun(a,j-i))
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
