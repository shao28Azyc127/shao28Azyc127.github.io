#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M,a,b,c;
    long long d;
    double sqd,x1,x2;
    cin >> T >> M;
    for(int i=0;i<T;i++)
    {
        cin >> a >> b >> c;
        d = b*b-4*a*c;
        if(d<0)
            cout << "NO";
        else
        {
            sqd = sqrt(d);
            x1 = (-b+sqd)/(2*a);
            x2 = (-b-sqd)/(2*a);
            if(x1>x2)
                cout << int(-b+sqd)/(2*a);
            else
            cout << (-b-sqd)/(2*a);
        }
    }
    return 0;
}
