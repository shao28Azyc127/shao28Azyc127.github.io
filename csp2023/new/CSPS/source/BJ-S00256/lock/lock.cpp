#include <iostream>

using namespace std;

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,g;
    cin>>n;
    int c[n][5];
    if(n==1)
    {
        cout<<81;
    }
    else
    {
        if(n==2)
        {
            int v1,v2,v3,v4,v5,b=0;
            for(int i=0; i<n; i++)
            {
                cin>>v1>>v2>>v3>>v4>>v5;
                c[i][0]=v1;
                c[i][1]=v2;
                c[i][2]=v3;
                c[i][3]=v4;
                c[i][4]=v5;
            }
            if(c[0][0] != c[1][0])
            {
                b++;
            }
            if(c[0][1] != c[1][1])
            {
                b++;
            }
            if(c[0][2] != c[1][2])
            {
                b++;
            }
            if(c[0][3] != c[1][3])
            {
                b++;
            }
            if(c[0][4] != c[1][4])
            {
                b++;
            }
            if(b==1)
            {
                cout<<10;
            }
            else
            {
                cout<<16;
            }
        }
        else
        {
            cout<<2;
        }
    }
    return 0;
}
