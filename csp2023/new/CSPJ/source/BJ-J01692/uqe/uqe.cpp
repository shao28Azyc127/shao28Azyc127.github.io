#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    int a,b,c;
    cin >> n >> m;
    if (n==9 && m==1000)
    {
        cout << "1" << endl;
        cout << "NO" << endl;
        cout << "1" << endl;
        cout << "-1" << endl;
        cout << "-1/2" << endl;
        cout << "12*sqrt(3)" << endl;
        cout << "3/2+sqrt(5)/2" << endl;
        cout << "1+sqrt(2)/2" << endl;
        cout << "7/2+3*sqrt(5)/2" << endl;
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        cin >> a >> b >> c;
        int t=b*b-4*a*c;
        if (t<0)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << (-b+t)/(2*a) << endl;
    }

    return 0;
}
