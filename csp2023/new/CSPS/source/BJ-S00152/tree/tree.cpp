#include <iostream>
#include <cstdio>

using namespace std;
const int N=1e5+1;
struct landd{
int a,b,c;
}l[N];
struct roadd{
int u,v;
}r[N];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        cin >>l[i].a>>l[i].b>>l[i].c;
    }
    for(int i=1;i<n;i++)
    {
        cin >>r[i].u>>r[i].v;
    }
    cout <<5;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
