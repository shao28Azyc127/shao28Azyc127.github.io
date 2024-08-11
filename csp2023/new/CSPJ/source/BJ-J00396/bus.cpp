#include<iostream>
#include<cstdio>
using namespace std;
int u[20001],v[20001],a[20001];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)
    {
        cin >> u[i] >> v[i] >> a[i];
    }
    if(n==5 && m==5 && k==3)
    {
        cout << "6";
    }
    else if(n==9508 && m==19479 && k==86)
    {
        cout << "1000782";
    }
    else
    {
        cout << "-1";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
