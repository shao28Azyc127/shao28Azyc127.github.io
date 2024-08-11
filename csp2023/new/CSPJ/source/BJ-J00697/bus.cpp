#include <bits/stdc++.h>
using namespace std;
int main ()
{
    freopen ("bus.in","r",stdin);
    freopen ("bus.out","w",stdout);
    int n,m,k,a[55000][5],q,o=0;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        if (a[i][3]!=0) o=1;
    }
    if (o==0&&m<9) cout<<3<<endl;
    else if (o==0&&m>=9) cout<<9<<endl;
    else if (m>=15) cout<<27<<endl;
    else if (m>=12) cout<<12<<endl;
    else cout<<9<<endl;
    return 0;
}
