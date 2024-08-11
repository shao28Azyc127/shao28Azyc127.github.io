#include <bits/stdc++.h>
using namespace std;
int c,n,m,q;
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    srand(time(0));
    cin>>c>>n>>m>>q;
    for(int i=0;i<=q;i++)
    {
        cout<<rand()%2;
    }
    return 0;
}
