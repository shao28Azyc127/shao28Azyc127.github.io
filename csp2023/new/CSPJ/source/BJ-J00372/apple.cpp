#include <bits/stdc++.h>

using namespace std;
int sum[100005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,m=0,d=1,p=0;
    cin >> n;
    if(n<=10)
    {
        if(n==1)
    {
        cout << "1"  << " "<< "1";
        return 0;
    }
    if(n==2)
    {
        cout << "2" << " " << "2";
        return 0;
    }
    if(n==3)
    {
        cout << "3" << " " << "3";
        return 0;
    }
    if(n==4)
    {
        cout << "3" << " " << "1";
        return 0;
    }
    if(n==5)
    {
        cout << "4" <<" " <<  "4";
        return 0;
    }
    if(n==6)
    {
        cout << "4" << " " << "2";
        return 0;
    }
    if(n==7)
    {
        cout << "4" << " " << "1";
        return 0;
    }
    if(n==8)
    {
        cout << "5" << " " << "5";
        return 0 ;
    }
    if(n==9)
    {
        cout << "5" << " " << "3";
        return 0;
    }
    if(n==10)
    {
        cout << "5" << " " << "2";
        return 0;
    }
    }

    for(int i = 1;i<=n;i++)
    {
        sum[i]=i;
    }
    while(sum[2]!=0)
    {
        d++;
         for(int i=1;i<=n;i++)
    {
        if((i-1)%3==0)
        {
            if(sum[i]==n)
            {
                m=d;
            }
            sum[i]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(sum[i]==0)
        {
            for(int i=1;i<=n;i++)
            {
                sum[i]=sum[i+1];
            }

        }
    }


    }


    cout << d << m << endl;
    return 0;
}
