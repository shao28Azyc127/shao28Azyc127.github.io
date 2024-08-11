#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
string s;
bool pd(string s)
{
    int l=s.length();
    for(int i=0;i<l-1;i++)
    {
        if(s[i]==s[i+1])
        return 1;
    }
    return 0;
}
void yd(string s,int pos,int num)
{
    int l=s.length();
    for(int i=pos;i<l;i++)
    s[i]=s[i+num];
}
void pd(string s)
{
    int pos=0,ans=0;
    int l=s.length();
    while(pd(s)==1)
    {
        if(pos==l)
        pos=0;
        if(s[pos]==s[pos+1])
        {
            s[pos]=s[pos+1]=48;
            yd(s,pos,2);
            l-=2;
        }
        pos++;
    }
    if(l!=0)
    return 0;
    else return 1;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> s;
    for(int i=2;i<=n;i+=2)
    {
        for(int j=1;j<=n-i+2;j++)
        {
            string ss;
            for(int pos=j,k=1;k<=i;k++,pos++)
            ss+=s[pos];
            ans+=pd(ss);
        }
    }
    cout << ans;
    return 0;
}
