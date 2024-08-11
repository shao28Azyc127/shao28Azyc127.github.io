#include <bits/stdc++.h>
using namespace std;
int n;
string str;
int ans;
int main()
{

    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>str;
    bool flag=1;
    while(flag)
    {
        flag=0;
        for(int i=0;i<str.length()-1;i++)
        {
            if(str[i]==str[i+1])
            {

                ans++;
                if(str.length()!=2)
                {
                    for(int j=i+2;j<str.length();j++)
                    {
                        str[j-2]=str[j];
                    }

                    str=str.substr(0,str.length()-2);
                   // cout<<str<<endl;
                    flag=1;
                }
                else
                    ans++;
            }
        }
    }
    cout<<ans;
    return 0;

}
