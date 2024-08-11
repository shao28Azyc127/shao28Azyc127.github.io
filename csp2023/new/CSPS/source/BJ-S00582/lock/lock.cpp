#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
int n,a[10][6],i,j,k,l,m;
int ans[10][10][10][10][10];
int tans;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=5;j++)
            cin>>a[i][j];
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=5;j++)
                for(k=1;k<=9;k++)
                {
                    a[i][j]+=k;
                    a[i][j]%=10;
                    ans[a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]]++;
                    if(ans[a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]]==n)
                        tans++;
                    //if(ans[a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]]>n)
                        //cout<<"sth is wrong...\n";
                    a[i][j]-=k-10;
                    a[i][j]%=10;
                }
            for(j=1;j<5;j++)
                for(k=1;k<=9;k++)
                {
                    a[i][j]+=k;
                    a[i][j]%=10;
                    a[i][j+1]+=k;
                    a[i][j+1]%=10;
                    ans[a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]]++;
                    if(ans[a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]]==n)
                        tans++;
                    //if(ans[a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]]>n)
                        //cout<<"sth is wrong...\n";
                    a[i][j]-=k-10;
                    a[i][j]%=10;
                    a[i][j+1]-=k-10;
                    a[i][j+1]%=10;
                }
        }
    cout<<tans<<endl;
    return 0;
}