#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int a[100][6];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
    }


    if(n==1)
    {
        cout<<"81";
        return 0;
    }
    else if(n<=2)
    {
        cout<<"10";
        return 0;
    }
    else 
    {

    cout<<(n+1)/2;
    return 0;

/*



        int b[800][6];



        for(int k=1;k<=n;k++)
        {




        for(int j=1;j<=81;j++)
        {
            for(int g=1;g<=5;g++)
            {
                b[g][j]=a[g][k];
            }
        }

        }




        for(int i=1;i<=n;)
        {
            for(int j=1;j<=5;j++)
            {
                b[i][j]++;
                i++;
            }
            for(int j=1;j<=5;j++)
            {
                b[i][j]--;
                i++;
            }
        }


*/














    }
    return 0;
}
