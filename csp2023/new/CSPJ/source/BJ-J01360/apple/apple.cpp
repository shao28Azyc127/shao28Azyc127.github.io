#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int num[1000000000];
    int n,flag,day=0,t,a=0;
    cin>>n;
    int m=n;
    while (m>0)
    {
        flag=3;
        for (int i=1;i<=n;i++)
        {
            if(num[i]==1)
            {

                continue;
            }
            if (flag<3)
            {
                flag++;
                continue;

            }
            else{
                num[i]=1;
                m--;
                flag=1;
            }

        }
        day++;

        if(num[n]==1&&a==0)
        {
            t=day;
            a=1;
        }
    }
    cout<<day<<" "<<t;
    return 0;
}