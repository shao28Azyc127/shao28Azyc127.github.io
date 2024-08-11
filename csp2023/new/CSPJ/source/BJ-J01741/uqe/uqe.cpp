#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    while(a != b)
    {
        if(a > b)
            a = a % b;
        else
            b = b % a;
    }
    return a;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int z = b * b - 4 * a * c;
        if(z < 0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            if(sqrt(z) - (int)sqrt(z) == 0)
            {
                int q1 = 2 * a;
                int q2 = -b + sqrt(z);
                q1 /= gcd(q1,q2);
                q2 /= gcd(2 * a,q2);
                if(q1 == 1)
                    cout<<q2<<endl;
                else
                    cout<<q2<<"/"<<q1<<endl;
            }
            else{
                int q1 = 2 * a;
                int q2 = -b;
                q1 /= gcd(q1,q2);
                q2 /= gcd(2 * a,q2);
                if(q2 == 0)
                {
                    cout<<"sqrt("<<z<<")/"<<q1<<endl;
                }
                else
                {
                    if(q1 == 1)
                    {
                        cout<<q2<<"+";
                    }
                    else
                    {
                        cout<<q2<<"/"<<q1<<"+";
                    }
                }
            }
        }
    }
    return 0;
}
