#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=' '+s;
    int sum=0;
    while(1)
    {
        bool b=false;
        for(int i=1;i<=n;i++)
        {
            int j=i+1;
            while(s[j]=='0')
            {
                j++;
            }
            if(s[i]==s[j])
            {
                s[i]='0';
                s[j]='0';
                sum++;
                b=true;
            }
        }
        if(b==false)break;
    }
    string aaa=" ";
    for(int i=1;i<=n;i++)
    {
        aaa=aaa+"0";
    }
    if(s==aaa)sum++;
    cout<<sum;
    return 0;
}
