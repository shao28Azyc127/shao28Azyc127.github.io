#include<bits/stdc++.h>
using namespace std;
bool q(int a,int b,string s)
{
    int c,d;
    string t;
    t=s;
    for (c=a;c<=b-1;c++)
    {
        if (t[c]=='*') continue;
        for (d=c+1;d<=b;d++)
        {
            if (t[c]==t[d])
            {
                t[c]='*',t[d]='*';
                break;
            }
        }
    }
    for (c=a;c<=b;c++)
    {
        if (t[c]!='*') return false;
    }
    return true;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int a,b,c,d,e;
    string s;
    cin>>a>>s;
    b=0;
    for (c=0;c<=a-2;c++)
    {
        for (d=c+1;d<=a-1;d+=2)
        {
            if (q(c,d,s)) b++;
        }
    }
    cout<<b;
    return 0;
}
