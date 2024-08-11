#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t , m;
    cin >> t >> m;
    while(t--)
    {
        int a , b , c;
        cin >> a >> b >> c;
        if(b * b - 4 * a *c < 0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            if(c == 0)
            {
                cout<<max(0 , -b / a)<<endl;

            }
            else
            {

                cout<<max((-b + sqrt(b * b - 4 * a*c)) / 2*a,(-b - sqrt(b * b - 4 * a*c)) / 2*a)<<endl;
            }
        }
    }

    return 0;
}
