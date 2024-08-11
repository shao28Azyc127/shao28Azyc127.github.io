#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int M=1e5+1;
struct chaa{
int x,y,v;}ch[M];
bool cmp(chaa a,chaa b)
{
    if(a.x!=b.x)return a.x<b.x;
    return a.y>b.y;
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    cin >>c>>t;
    while(t--)
    {
        int n,m,k,d;
        cin >>n>>m>>k>>d;
        for(int i=0;i<m;i++)
        {
            cin >>ch[i].x>>ch[i].y>>ch[i].v;
        }
        sort(ch,ch+m,cmp);
        cout <<ch[0].v-d*(n-1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
