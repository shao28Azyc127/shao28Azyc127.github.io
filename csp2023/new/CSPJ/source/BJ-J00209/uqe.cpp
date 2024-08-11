#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin >>t >>m;
    for(int i=1; i<=t; i++)
    {
        double a,b,c;
        cin >> a >> b >> c;
        double p=b*b-4*a*c;
        if(p<0)
        {
            cout << "NO" << endl;
            continue;
        }
        int x=1.0*(-b+sqrt(p))/(2*a);
        int y=1.0*(-b-sqrt(p))/(2*a);
        cout << max(x,y) << endl;
    }
    return 0;
}