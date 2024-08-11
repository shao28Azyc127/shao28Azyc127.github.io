#include <iostream>

using namespace std;
int n,a,b,c,d,e;
int ans[11][11][11][11][11];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    int k=0;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c>>d>>e;

        for(int j=1;j<=9;j++)
        {
            int a1=a,b1=b,c1=c,d1=d,e1=e;
            if(j>a)a1=a+10;
            //else a1=a;
            if(j>b)b1=b+10;
            //else b1=b;
            if(j>c)c1=c+10;
            //else c1=c;
            if(j>d)d1=d+10;
            //else d1=a;
            if(j>e)e1=e+10;
            //else e1=e;
            ans[a1-j][b][c][d][e]++;
            ans[a][b1-j][c][d][e]++;
            ans[a][b][c1-j][d][e]++;
            ans[a][b][c][d1-j][e]++;
            ans[a][b][c][d][e1-j]++;
            ans[a1-j][b1-j][c][d][e]++;
            ans[a][b1-j][c1-j][d][e]++;
            ans[a][b][c1-j][d1-j][e]++;
            ans[a][b][c][d1-j][e1-j]++;
        }

    }
    int cnt=0;
    for(int a2=0;a2<10;a2++)
        for(int b2=0;b2<10;b2++)
            for(int c2=0;c2<10;c2++)
                for(int d2=0;d2<10;d2++)
                    for(int e2=0;e2<10;e2++)
                    {
                        if(ans[a2][b2][c2][d2][e2]==n)
                        {
                            cnt++;
                        }
                    }
    cout << cnt<< endl;
    return 0;
}
