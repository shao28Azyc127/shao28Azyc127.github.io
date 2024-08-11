#include <iostream>

using namespace std;

int n,a[10][10],b[10],c[10],ans=0;

bool check(int x)
{
    int i,j;
    b[0]=(x/10000)%10;
    b[1]=(x/1000)%10;
    b[2]=(x/100)%10;
    b[3]=(x/10)%10;
    b[4]=x%10;
    for(i=0;i<n;i++)
    {
        for(j=0;j<5;j++)
        {
            if(a[i][j]<b[j])
                c[j]=(a[i][j]+10-b[j])%10;
            else
                c[j]=(a[i][j]-b[j])%10;
        }
        int ck=0;
        for(j=0;j<5;j++)
        {
            if(ck==0)
            {
                if(c[j]==0)
                    continue;
                ck++;
            }
            else
            {
                if(c[j]!=0)
                {
                    if(c[j]!=c[j-1] || ck>=2)
                        return 0;
                    ck++;
                }
            }

        }
        if(ck==0)
            return 0;
    }
    return 1;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n ;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<5;j++)
            cin >> a[i][j] ;
    for(i=0;i<100000;i++)
    {
        if(check(i))
            ans++;
    }
    cout << ans ;
}
