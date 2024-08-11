#include<iostream>
#include<cstdio>
using namespace std;
const int N=15;
const int A=1e5;
const int M=15;
int n;
int a[N][M];
int b[A][M];
int k=1;
namespace _100pts
{
    bool fd(int x, int left)
    {
        for(int i=left; i<=left+80; i++)
        {
            bool flag=0;
            for(int j=1; j<=5; j++)
            {
                if(b[i][j]!=b[x][j])
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                return 1;
            }

        }

        return 0;
    }
    void mian()
    {
        for(int i=1; i<=n; i++)
        {
            for(int t=1; t<=5; t++)
            {
                for(int j=0; j<=9; j++)
                {
                    if(j==a[i][t])
                        continue;
                    b[k][t]=j;
                    for(int p=1; p<t; p++)
                        b[k][p]=a[i][p];
                    for(int p=t+1; p<=5; p++)
                        b[k][p]=a[i][p];
                    k++;
                }
            }
            for(int t=1; t<=4; t++)
            {
                for(int addt=1; addt<=9; addt++)
                {
                    b[k][t]=(a[i][t]+addt)%10;
                    b[k][t+1]=(a[i][t+1]+addt)%10;
                    for(int p=1; p<t; p++)
                        b[k][p]=a[i][p];
                    for(int p=t+2; p<=5; p++)
                        b[k][p]=a[i][p];
                    k++;
                }


            }


        }

      //  print();
        int ans=0;
        for(int i=1; i<=81; i++)
        {
            bool flag=1;
            for(int j=1; j<n; j++)
            {
                if(!fd(i, j*81+1))
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1) ans++;
        }
        cout << ans << endl;
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=5; j++)
            cin >> a[i][j];
    if(n==1) cout << 81 << endl;
    else _100pts::mian();
    return 0;
}
