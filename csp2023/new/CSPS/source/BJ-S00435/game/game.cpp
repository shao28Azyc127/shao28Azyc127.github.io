#include<iostream>
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
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            ans++;
            if(i>0&&i<n-2&&s[i-1]==s[i+2])
                ans++;
        }
    }
    cout<<ans;
    return 0;
}