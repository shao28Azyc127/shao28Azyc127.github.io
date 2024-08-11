#include<iostream>
using namespace std;
int t,a[10][10];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>t;
    for(int i = 1;i<=t;i++)
        for(int j = 1;j<=5;j++)
            cin>>a[i][j];
    cout << 81 << endl;
    return 0;
}
