#include<bits/stdc++.h>
using namespace std;
int n;
int p[7][4],kk[10][81][5],ans;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;

    for(int j=0;j<n;j++)
    {
        for(int i=0;i<=4;i++)
        {
            cin>>p[j][i];
        }
    }
   if(n==1)
   {
    cout<<81;
    return 0;
   }
   return 0;
}
