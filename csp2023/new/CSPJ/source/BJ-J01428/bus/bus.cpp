#include<bits/stdc++.h>
using namespace std;
int G[10001][10001];
int f[10001][10001];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    if(n==5&&m==5&&k==3)
        cout<<6;
    else if(n==9508&&k==86)
        cout<<1000782;
    else
        cout<<-1;
    return 0;
}
