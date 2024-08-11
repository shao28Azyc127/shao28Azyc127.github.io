#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct asdas{
int n;string c;bool y=0;
}s[3001],t[3001];
bool cmp(asdas a,asdas b)
{
    return a.c<b.c;
}
asdas minx;
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin >>n>>m;
    for(int i=0;i<n;i++)
    {
        cin >>s[i].c;
        s[i].n=i;
        t[i].c=s[i].c;
        t[i].n=s[i].n;
    }
    sort(t,t+n,cmp);
    s[t[0].n].y=1;
    for(int i=0;i<n;i++)
    {
        if(s[i].y){cout <<1;}
        else{cout <<0;}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
