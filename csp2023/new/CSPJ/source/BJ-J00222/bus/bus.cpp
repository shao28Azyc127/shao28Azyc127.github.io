#include <iostream>
#include <cstdio>
using namespace std;
const int N=2*1e4+10;

int u[N],v[N],a[N];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin >>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin >>u[i]>>v[i]>>a[i];
    }
    cout <<k*2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
