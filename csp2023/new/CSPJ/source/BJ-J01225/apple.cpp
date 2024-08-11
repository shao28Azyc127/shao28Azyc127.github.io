#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int k = 0,summm=0,m,zy,flagn;
int main()
{
    freopen("apple.in","r",stdin)
    freopen("apple.out","w",stdout)
    int n;
    cin >> n;
    while(1)
    {
        m++;
        k=2;
        flagn=0;
        for(int i = 0;i < n;i++)
        {
            if(a[i]==0&&k!=2)
            {
                k++;
            }
            else if(a[i]==0&&k==2&&i!=n-1)
            {
                k=0;
                a[i]=1;
                flagn=1;
                //cout << i << endl;
            }
            else if(a[i]==0&&k==2&&i==n-1)
            {
                zy=m;
                flagn=1;
                a[i]=1;
                //cout << i << endl;
            }
        }
        if(flagn==0)
        {
            m--;
            cout << m << " " << zy;
            return 0;
        }
    }
    return 0;
}
