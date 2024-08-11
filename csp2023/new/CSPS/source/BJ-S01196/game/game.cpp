#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
string s;
int ans=0,n,a[maxn];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            a[i]=i;
            a[i+1]=i;
            ans++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0) continue ;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]!=0) continue ;
            if(s[j]==s[i])
            {
                a[i]=a[i+1];
                a[j]=a[i+1];
                ans++;
            }
            else break ;
        }
    }
    //for(int i=0;i<n;i++) cout<<a[i]<<" ";
    //cout<<endl;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=a[i+1] && a[i]!=0 && s[i]!=s[i+1]) ans++;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
