#include<bits/stdc++.h>

using namespace std;

string zichuan,s;
string ss[int(2e6)+5];
int n,idx,t;

stack<char> stk;

bool check(string key)
{

    if(key=="")
    {
        return 0;
    }

    while(!stk.empty())
    {
        stk.pop();
    }

    char c=key[0];

    stk.push(c);

    for(int i=1;i<s.size();i++)
    {
        c=key[i];
        if(!stk.empty())
        {
            if(c==stk.top())
            {
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }
        else
        {
            stk.push(c);
        }
    }
    return stk.empty();
}

int main() {

    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    cin>>n;
    cin>>s;

    int ans=0;
    for(int l=0;l<s.size();l++)
    {
        for(int r=0;r<s.size();r++)
        {
            zichuan="";
            for(int i=l;i<=r;i++)
            {
                zichuan+=s[i];
            }
            if(check(zichuan))
            {
                ans++;
            }
        }
    }

    cout<<ans;

    return 0;
}