#include<bits/stdc++.h>
using namespace std;
bool f;
int n,s,t;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while (n>0)
    {
        s++;
        if (n==1)
        {
            if (f==false)
            {
                t=s;
            }
            break;
        }
        else if (n==2||n==3)
        {
            n--;
        }
        else
        {
            if (n%3==1)
            {
                if (f==false)
                {
                    t=s;
                    f=true;
                }
                n--;
                n/=3;
                n*=2;
            }
            else
            {
                n--;
                n/=3;
                n*=2;
                n++;
            }
        }
    }
    cout<<s<<" "<<t;
    return 0;
}
