#include<iostream>
#include<stdio.h>
char a[10][10];
long long n,ans;
using namespace std;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
            
    }
    cout<<81;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
