#include<iostream>
#include<stdio>
using namespace std;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==s[i-1])
        {
            ans++;
            s[i]='0';
            s[i-1]='0';
        }
    }
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(s[i]!='0')
        {
            flag=false;
        }
    }
    if(flag==true)
    {
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}